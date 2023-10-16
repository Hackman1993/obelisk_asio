/***********************************************************************************************************************
 * @author Hackman Lo
 * @file http_server.cpp
 * @description 
 * @created_at 2023-10-13
***********************************************************************************************************************/

#include "http/http_server.h"
#include "http/response/file_response.h"
#include "http/exception/http_exception.h"
#include "http/response/json_response.h"
#include "http/core/http_request.h"
#include "http/middleware/middleware.h"
#include <boost/json.hpp>
#include "http/router/route_item.h"
namespace obelisk {
    namespace http {
        http_server::http_server(boost::asio::io_context &ctx, const std::string& webroot) : acceptor_(ctx), webroot_(webroot) {
            if(!(std::filesystem::exists(webroot_) && std::filesystem::is_directory(webroot_)))
                throw std::logic_error("Root Dirctory Not Exists");
            acceptor_.on_accepted([&](const std::shared_ptr<http_connection>& accepted){
                accepted->on_request_received(std::bind(&http_server::on_request_, this, std::placeholders::_1));
            });
        }

        std::shared_ptr<http_response> http_server::on_request_(std::shared_ptr<http_request> &request) {
            std::shared_ptr<http_response> resp = nullptr;
            {
                for(const auto& ptr : middlewares_){
                    auto derived_ptr = std::dynamic_pointer_cast<before_middleware>(ptr);
                    if(derived_ptr)
                        resp = derived_ptr->pre_handle(request);
                    if(resp)
                        break;
                }

            }
            if(!resp){
                for(const auto&ptr : routes_){
                    std::unordered_map<std::string,std::string> route_params;
                    if(!ptr->match(request->path_, route_params))
                        continue;
                    if(!ptr->method_allowed(request->header_.title_.method_))
                        THROW(http_exception, "Method Not Allowed!", "Obelisk", EHTTP_RESP_STATUS::EST_METHOD_NOT_ALLOWED);
                    request->route_params_ = route_params;
                    resp = ptr->handle(request);
                    if(resp) break;
                }
            }
            if(!resp){
                std::filesystem::path path(webroot_);
                path.append("./" + request->path_);
                if(std::filesystem::exists(path)){
                    if(!std::filesystem::is_directory(path)){
                        resp = std::make_shared<file_response>(path.string(), EHTTP_RESP_STATUS::EST_OK);
                    }else{
                        for(const auto& index: index_files_){
                            std::filesystem::path index_path(path);
                            index_path.append(index);
                            if(std::filesystem::exists(index_path) && !std::filesystem::is_directory(index_path))
                                resp = std::make_shared<file_response>(index_path.string(), EHTTP_RESP_STATUS::EST_OK);
                        }
                    }
                }
            }

            if(!resp)
                resp = std::make_shared<json_response>(boost::json::object({{"code",    404}, {"message", "Not Found"}, {"data",    boost::json::value()}}), EHTTP_RESP_STATUS::EST_NOT_FOUND);

            for(const auto& ptr : middlewares_){
                auto derived_ptr = std::dynamic_pointer_cast<after_middleware>(ptr);
                if(derived_ptr) derived_ptr->after_handle(request, resp);
            }

            resp->add_header("Host", request->header_.headers_["Host"]);
            resp->add_header("Cache-Control", "no-cache, private");
            resp->add_header("Vary", "Origin");
            resp->add_header("Content-Length", std::to_string(resp->content_length()));
            return resp;
        }

        void http_server::listen(const std::string &address, unsigned short port) {
            acceptor_.listen(address, port);
        }
    } // obelisk
} // http