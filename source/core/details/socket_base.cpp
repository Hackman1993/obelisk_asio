//
// Created by Hackman.Lo on 10/12/2023.
//

#include <iostream>
#include "core/details/socket_base.h"


namespace obelisk::core::details {
    void socket_base::e_connected_() {
        self_holder_ = shared_from_this();
        post_receive();
    }

    void socket_base::send() {
        io_reference_ += 1;
        write_pending_ = true;
        boost::asio::async_write(socket_, outstream_, [&](const boost::system::error_code &error, std::size_t bytes_transferred){
            io_reference_ -= 1;
            write_pending_ = false;
            if(bytes_transferred > 0) outstream_.consume(bytes_transferred);
            bytes_sent_(error, bytes_transferred);
        });
    }

    void socket_base::bytes_received_(const boost::system::error_code &error, std::size_t bytes_transferred) {
        if(error){
            if(error != boost::asio::error::eof)
                std::cout << error.what() << error.value() << std::endl;
            close();
            return;
        }
        instream_.commit(bytes_transferred);
        e_data_received(bytes_transferred);
        std::cout << "Readed Bytes : " << bytes_transferred << std::endl;
        post_receive();
    }

    void socket_base::bytes_sent_(const boost::system::error_code &error, std::size_t bytes_transferred) {
        if(error){
            if(error != boost::asio::error::eof)
                std::cout << error.what() << error.value() << std::endl;
            close();
            return;
        }
        e_data_sent(bytes_transferred);
    }

    socket_base::socket_base(boost::asio::ip::tcp::socket &socket): socket_(std::move(socket)) {}

    void socket_base::close() {
        if(socket_.is_open())
            socket_.close();
        if(io_reference_ == 0)
            self_holder_ = nullptr;
    }

    void socket_base::post_receive() {
        io_reference_ += 1;
        socket_.async_receive(instream_.prepare(256 * 1024), [&](const boost::system::error_code &error, std::size_t bytes_transferred){
            io_reference_ -= 1;
            bytes_received_(error, bytes_transferred);
        });
    }

    socket_base::~socket_base() {
        std::cout << "Base Socket Released" << std::endl;
        if(socket_.is_open())
            socket_.close();
    }
} // obelisk::core::details