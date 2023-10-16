/***********************************************************************************************************************
 * @author Hackman Lo
 * @file control_client.cpp
 * @description 
 * @created_at 2023-10-16
***********************************************************************************************************************/

#include "control_client.h"
#include <iostream>
control_client::control_client(boost::asio::ip::tcp::socket &socket) : socket_base(socket) {

}

control_client::~control_client() {

}

void control_client::e_connected() {
#ifdef __RDSERVER__
    std::cout << "[Server] Connected" << std::endl;
#else
    std::cout << "[Client] Connected" << std::endl;
#endif
}

void control_client::e_data_sent(std::size_t bytes_transferred) {

}

void control_client::e_data_received(std::size_t bytes_transferred) {

}
