//
// Created by Hackman.Lo on 10/12/2023.
//

#include "core/details/socket_base.h"
#include "core/details/acceptor_base.h"
#include <iostream>
namespace obelisk::core::details {
    acceptor_base::acceptor_base(boost::asio::io_context& ctx): acceptor_(ctx) {
    }

    acceptor_base::~acceptor_base() {
        std::cout << "acceptor_base Released" << std::endl;
    }

    void acceptor_base::listen(const std::string &addr, std::uint16_t port) {
        boost::asio::ip::address address = boost::asio::ip::address::from_string(addr);
        boost::asio::ip::tcp::endpoint ep(address, port);
        acceptor_.open(ep.protocol());
        acceptor_.bind(ep);
        acceptor_.listen();
        post_accept_();
    }

    void acceptor_base::close() {
        acceptor_.close();
    }

    void acceptor_base::accepted_(const boost::system::error_code &err, boost::asio::ip::tcp::socket& socket) {
        if(err){
            std::cout << err.what() << std::endl;
            acceptor_.close();
            return;
        }
        auto accepted = e_accepted(socket);
        if(accepted)
            accepted->e_connected_();
        else socket.close();
        post_accept_();
    }

    void acceptor_base::post_accept_() {
        acceptor_.async_accept([&](const boost::system::error_code &err, boost::asio::ip::tcp::socket socket){ accepted_(err, socket);});
    }
} // details