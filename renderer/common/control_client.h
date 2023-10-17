/***********************************************************************************************************************
 * @author Hackman Lo
 * @file control_client.h
 * @description 
 * @created_at 2023-10-16
***********************************************************************************************************************/

#ifndef OBELISK_CONTROL_CLIENT_H
#define OBELISK_CONTROL_CLIENT_H

#include "obelisk.h"
#include "packages/package.h"
#include "protos/client_info.pb.h"
#include "packages/package_header.h"

class control_client: public obelisk::core::details::socket_base {
public:
    control_client(boost::asio::ip::tcp::socket &socket);
    control_client(boost::asio::io_context& ios);
    template<typename T>
    void send_package(package<T>& pkg){
        auto &buf = pkg.data();
        outstream_.sputn(boost::asio::buffer_cast<const char*>(buf.data()), buf.size());
        send();
    };
    ~control_client() override;
    void on_registered(const std::function<void (client_info&)>& callback){ registered_ = callback; };
protected:
    std::function<void (client_info&)> registered_;
    virtual void e_registered(client_info& info);
    std::shared_ptr<package_header> header_ = nullptr;
    void e_connected() override;
    void e_data_sent(std::size_t bytes_transferred) override;
    void e_data_received(std::size_t bytes_transferred) override;
};


#endif //OBELISK_CONTROL_CLIENT_H
