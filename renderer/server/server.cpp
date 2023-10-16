/***********************************************************************************************************************
 * @author Hackman Lo
 * @file server.cpp
 * @description 
 * @created_at 2023-10-16
***********************************************************************************************************************/

#include "server.h"

server::server(boost::asio::io_context &ctx): acceptor_(ctx) {
    acceptor_.on_accepted([&](auto accepted){
    });

}

void server::listen(const std::string &address, unsigned short port) {
    acceptor_.listen(address, port);
}
