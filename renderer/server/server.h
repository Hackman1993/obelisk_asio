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
#include "common/protos/rendering_job.pb.h"
class server {
public:
    explicit server(boost::asio::io_context& ctx);
    void listen(const std::string& address, unsigned short port);
private:
    struct client_data{
        client_data(client_info& info, std::shared_ptr<control_client> ptr): info_(std::move(info)), ptr_(std::move(ptr)){};
        client_info info_;
        std::shared_ptr<control_client> ptr_;
    };
protected:
    obelisk::core::acceptor<control_client> acceptor_;
    std::condition_variable notify_;
    std::unique_lock<std::mutex> notify_lock_;

    std::mutex endpoint_mutex_;
    std::vector<std::shared_ptr<client_data>> idle_;
    std::vector<std::shared_ptr<client_data>> busy_;
};


#endif //OBELISK_SERVER_H
