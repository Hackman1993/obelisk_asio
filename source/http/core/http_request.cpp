//
// Created by hackman on 10/7/23.
//

#include "http/core/http_request.h"

#include <utility>
#include <filesystem>
namespace obelisk::http {
    void http_request::set_param(const std::string& name, const std::string& value) {
        if(params_.contains(name)){
            params_[name].push_back(value);
        }else{
            params_[name] = std::vector<std::string>{value};
        }
    }

    bool http_request::contains_param(const std::string &name) {
        return params_.contains(name);
    }

    bool http_request::contains_file(const std::string &file) {
        return filebag_.contains(file);
    }

    std::shared_ptr<http_file> http_request::file(const std::string &file) {
        return filebag_[file];
    }

    std::vector<std::string> http_request::param(const std::string &name) {
        return params_[name];
    }

    http_temp_fstream::http_temp_fstream(std::string path): path_(std::move(path)) {
        std::ofstream fstream(path_);
        fstream.close();
        this->open(path_, std::ios::out | std::ios::in | std::ios::binary);
    }

    http_temp_fstream::~http_temp_fstream() {
        this->close();
        if(std::filesystem::exists(path_) && std::filesystem::is_regular_file(path_))
            std::filesystem::remove(path_);
    }

    std::string http_temp_fstream::path() {
        return path_;
    }
} // obelisk