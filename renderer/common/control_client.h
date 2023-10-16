/***********************************************************************************************************************
 * @author Hackman Lo
 * @file control_client.h
 * @description 
 * @created_at 2023-10-16
***********************************************************************************************************************/

#ifndef OBELISK_CONTROL_CLIENT_H
#define OBELISK_CONTROL_CLIENT_H

#include "obelisk.h"
class control_client: public obelisk::core::details::socket_base {
public:
    control_client(boost::asio::ip::tcp::socket &socket);

    ~control_client() override;
protected:

    void e_connected() override;

    void e_data_sent(std::size_t bytes_transferred) override;

    void e_data_received(std::size_t bytes_transferred) override;
};


#endif //OBELISK_CONTROL_CLIENT_H
