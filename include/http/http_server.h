/***********************************************************************************************************************
 * @author Hackman Lo
 * @file http_server.h
 * @description 
 * @created_at 2023-10-13
***********************************************************************************************************************/

#ifndef OBELISK_HTTP_SERVER_H
#define OBELISK_HTTP_SERVER_H
#include "core/acceptor.h"
#include <filesystem>
#include "http_connection.h"
namespace obelisk::http {
    class http_response;
    class http_request;
    class route_item;
    class http_middleware_base;
    class http_server {
    public:
        http_server(boost::asio::io_context& ctx, const std::string& webroot);
        void listen(const std::string& address, unsigned short port);
        std::shared_ptr<route_item>& route(const std::string& route, std::function<std::shared_ptr<http_response> (std::shared_ptr<http_request>&)> handler);
    protected:
        std::filesystem::path webroot_;
        std::vector<std::string> index_files_= {"index.html", "index.htm"};
        obelisk::core::acceptor<http_connection> acceptor_;
        std::vector<std::shared_ptr<route_item>> routes_;
        std::vector<std::shared_ptr<http_middleware_base>> middlewares_;
        virtual std::shared_ptr<http_response> on_request_(std::shared_ptr<http_request>& request);
    };

} // obelisk::http

#endif //OBELISK_HTTP_SERVER_H
