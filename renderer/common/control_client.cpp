/***********************************************************************************************************************
 * @author Hackman Lo
 * @file control_client.cpp
 * @description 
 * @created_at 2023-10-16
***********************************************************************************************************************/

#include "control_client.h"
#include "ability_define.h"
#include "packages/package.h"
#include <iostream>
control_client::control_client(boost::asio::ip::tcp::socket &socket) : socket_base(socket) {

}

control_client::control_client(boost::asio::io_context &ctx): socket_base(ctx) {

}

control_client::~control_client() {

}

void control_client::e_connected() {
#ifndef __RDSERVER__
    client_info info;

#ifdef _WIN32
    info.set_os_(OS_TYPE_WINDOWS);
#elif defined(__linux__)
    info.set_os_(OS_TYPE_LINUX);
#elif defined(__APPLE__)
    info.set_os_(OS_TYPE_MACOS);
#else
    info.set_os_(OS_TYPE_UNIX);
#endif
    info.set_ability_(ABI_RENDER);
    // TODO: Set Real Client ID
    info.set_client_id_("test_client");

    obelisk::debug::cost_timer timer;
    package<client_info> pkg(mt_client_register, info);
    send_package(pkg);
#endif
}

void control_client::e_data_sent(std::size_t bytes_transferred) {

}

void control_client::e_data_received(std::size_t bytes_transferred) {
    while(true){
        if(!header_ && instream_.size() < sizeof(package_header)) return;
        if(header_ && instream_.size() < header_->length_) return;

        if(!header_){
            header_ = std::make_shared<package_header>();
            instream_.sgetn((char*)header_.get(), sizeof (package_header));
            header_->length_ = ntohl(header_->length_);
            header_->type_ = ntohl(header_->type_);
            header_->identifier_ = ntohl(header_->identifier_);
            if(header_->identifier_ != 0x19930323){
                std::cout << "Invalid Identifier, Shutting Down" << std::endl;
                this->close();
                return;
            }
        }else{
            if(header_->type_ == mt_client_register){
                client_info data;
                auto parse_result = data.ParseFromArray(boost::asio::buffer_cast<const void *>(instream_.data()), header_->length_);
                instream_.consume(header_->length_);
                if(parse_result){
                    e_registered(data);
                }else{
                    std::cout << "mt_client_register received but parse failed, Shutting Down!" << std::endl;
                    this->close();
                    return;
                }
            }

        }
    }
}

void control_client::e_registered(client_info &info) {
    if(registered_)
        registered_(info);
}


