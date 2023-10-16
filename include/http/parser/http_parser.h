//
// Created by hackman on 10/7/23.
//

#ifndef OBELISK_HTTP_PARSER_H
#define OBELISK_HTTP_PARSER_H
#include <string>
#include <memory>
#include <unordered_map>
#include "http/core/http_request.h"

namespace obelisk::http {

    class socket;

    bool boundary_parse(std::string_view  data, const std::shared_ptr<http_request>& request);
    bool package_header_parse(std::string_view data, std::shared_ptr<http_request> request);

    bool http_body_parser(std::shared_ptr<http_request> &request);
    bool http_multipart_body_parser(std::shared_ptr<http_request> &request);
    bool http_urlencoded_param_parser(std::shared_ptr<http_request> &request, std::string_view data);


} // obelisk

#endif //OBELISK_HTTP_PARSER_H
