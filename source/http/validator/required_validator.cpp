#include "http/validator/required_validator.h"
#include <memory>
#include "http/core/http_request.h"
#include "http/exception//validation_exception.h"
namespace obelisk::http {
    std::shared_ptr<required_validator> required() {
        return std::make_shared<required_validator>();
    }

    void required_validator::validate(const std::string &name, http_request &request) {
        if (!request.params_.contains(name)) {
            throw obelisk::http::validation_exception("Required param " + name + " not found");
        }
    }
}