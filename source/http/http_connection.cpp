/***********************************************************************************************************************
 * @author Hackman Lo
 * @file http_connection.cpp
 * @description 
 * @created_at 2023-10-13
***********************************************************************************************************************/
#include <iostream>
#include <sahara/utils/uuid.h>
#include "http/http_connection.h"
#include "http/parser/http_parser.h"
#include "http/core/http_request.h"
#include "http/core/http_response.h"
#include "http/exception/protocol_exception.h"

namespace obelisk::http {
    http_connection::http_connection(boost::asio::ip::tcp::socket &socket) : socket_base(socket) {
        request_ = std::make_shared<http_request>();
    }

    void http_connection::e_connected() {

    }

    void http_connection::e_data_sent(std::size_t bytes_transferred) {
        write_outgoing_request();
    }

    bool http_connection::e_data_received(std::size_t bytes_transferred) {
        bool finished;
        do {
            finished = expecting_body_ ? handle_body_() : handle_header_();
            if (finished) {
                e_request_received();
                request_ = std::make_shared<http_request>();
            }
        } while (finished && instream_.size() > 0);
        return true;
    }

    bool http_connection::handle_header_() {
        std::string_view received_data(boost::asio::buffer_cast<const char *>(instream_.data()), instream_.size());
        bool contains_header_eof = received_data.contains("\r\n\r\n");
        if (instream_.size() > 10 * 1024 && !contains_header_eof)
            THROW(protocol_exception, "Header Size Exceed, Shutting Down!", "Obelisk");
        if (!contains_header_eof) return false;
        received_data = std::string_view(received_data.data(), received_data.find("\r\n\r\n") + 4);
        auto parse_result = package_header_parse(received_data, request_);
        if (!parse_result)
            THROW(protocol_exception, "Invalid Package Header, Shutting Down!", "Obelisk");
        instream_.consume(received_data.size());
        if (request_->header_.headers_.contains("Content-Length") && request_->header_.headers_.contains("Content-Type")) {
            request_->content_type_ = request_->header_.headers_["Content-Type"];
            request_->content_length_ = std::stoull(request_->header_.headers_["Content-Length"]);
            body_reamains_ = request_->content_length_;
            // If Content-Type is form-data, then extract boundary
            if (request_->content_type_.contains("multipart/form-data")) {
                if (!boundary_parse(request_->content_type_, request_))
                    THROW(protocol_exception, "Extract Boundary With multipart/form-data Header Failed, Shutting Down!", "Obelisk");
            }
        }
        if (request_->content_length_ > 0) {
            expecting_body_ = true;
            if (request_->content_length_ > 1 * 1024 * 1024) {
                // If content length greater than 1 MB, Create a filestream
                std::string path = "./" + sahara::utils::uuid::generate();
                request_->raw_ = std::make_shared<http_temp_fstream>(path);
            } else {
                // If content length <= 1MB, Create a memory buffer
                request_->raw_ = std::make_shared<std::stringstream>();
            }
            if (instream_.size() > 0)
                return handle_body_();

        } else return true;

        return false;
    }

    bool http_connection::handle_body_() {
        std::string_view received_data(boost::asio::buffer_cast<const char *>(instream_.data()), instream_.size());
        // Calculate data should be written, prevent buffer contains some part of content and a new request header
        std::uint32_t bytes_write = std::min<std::uint64_t>(received_data.size(), body_reamains_);
        if (bytes_write > 0) {
            request_->raw_->write(received_data.data(), bytes_write);
            instream_.consume(bytes_write);
            body_reamains_ -= bytes_write;
        }
        // if request has been fully received, flush data and reset the header_received flag
        if (body_reamains_ == 0) {
            request_->raw_->flush();
            http_body_parser(request_);
            return true;
        }
        return false;
    }

    void http_connection::e_request_received() {
        if(f_requested_){
            auto ret = f_requested_(request_);
            if(ret) write_response(ret);
        }
        std::cout << "Request Received" << std::endl;
    }

    void http_connection::write_response(const std::shared_ptr<http_response> &resp) {
        out_requests_.push(resp->serialize());
        write_outgoing_request();
    }

    void http_connection::write_outgoing_request() {
        if (write_pending_ || out_requests_.empty() || outstream_.in_avail() >= 1 * 1024 * 1024) return;
        auto req = out_requests_.front();
        auto buffer_len = 1*1024*1024 - outstream_.size();
        auto buffer = outstream_.prepare(buffer_len);

        auto bytes_read = req->read(static_cast<unsigned char *>(buffer.data()), buffer_len);
        outstream_.commit(bytes_read);
        req->consume(bytes_read);
        if(bytes_read < buffer_len)
            out_requests_.pop();
        send();
    }

    void http_connection::on_request_received(const std::function<std::shared_ptr<http_response>(std::shared_ptr<http_request> &)> &callback) {
        f_requested_ = callback;
    }
} // obelisk
// http