/***********************************************************************************************************************
 * @author Hackman Lo
 * @file server.cpp
 * @description 
 * @created_at 2023-10-16
***********************************************************************************************************************/

#include "server.h"

server::server(boost::asio::io_context &ctx): acceptor_(ctx) {
    acceptor_.on_accepted([&](std::shared_ptr<control_client> accepted){
        accepted->on_registered([&](client_info& info){
            endpoint_mutex_.lock();
            idle_.emplace_back(std::make_shared<client_data>(info, accepted));
            endpoint_mutex_.unlock();
            std::cout << info.client_id_() << "is Registered" << std::endl;
        });
    });

}

void server::listen(const std::string &address, unsigned short port) {
    acceptor_.listen(address, port);
}
