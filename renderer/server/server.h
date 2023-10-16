/***********************************************************************************************************************
 * @author Hackman Lo
 * @file server.h
 * @description 
 * @created_at 2023-10-16
***********************************************************************************************************************/

#ifndef OBELISK_SERVER_H
#define OBELISK_SERVER_H

#include "obelisk.h"
#include "common/control_client.h"
class server {
public:
    server(boost::asio::io_context& ctx);
    void listen(const std::string& address, unsigned short port);
protected:
    obelisk::core::acceptor<control_client> acceptor_;
};


#endif //OBELISK_SERVER_H
