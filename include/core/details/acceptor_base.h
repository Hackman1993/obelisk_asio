//
// Created by Hackman.Lo on 10/12/2023.
//

#ifndef OBELISK_ACCEPTOR_BASE_H
#define OBELISK_ACCEPTOR_BASE_H
#include <boost/asio.hpp>
#include "socket_base.h"

namespace obelisk::core::details {
    class acceptor_base {
    public:
        acceptor_base(boost::asio::io_context& ctx);
        virtual ~acceptor_base();
        void listen (const std::string &addr, std::uint16_t port);
        void close();
    protected:
        void post_accept_();
        virtual std::shared_ptr<socket_base> e_accepted(boost::asio::ip::tcp::socket& socket) = 0;
        void accepted_(const boost::system::error_code& err, boost::asio::ip::tcp::socket& socket);
        boost::asio::ip::tcp::acceptor acceptor_;
    };
} // details

#endif //OBELISK_ACCEPTOR_BASE_H
