/***********************************************************************************************************************
 * @author Hackman Lo
 * @file package.h
 * @description 
 * @created_at 2023-10-17
***********************************************************************************************************************/

#ifndef OBELISK_PACKAGE_H
#define OBELISK_PACKAGE_H


#include "package_header.h"
#include <boost/asio/streambuf.hpp>
class package_base{
public:
    virtual ~package_base() = default;
    boost::asio::streambuf& data(){ return data_; };
protected:
    boost::asio::streambuf data_;
};

template <typename T>
class package : public package_base{
public:
    package(message_type type, T& message) {
        auto length = message.ByteSizeLong();
        package_header header;
        header.type_ = htonl(type);
        header.length_ =htonl(length);

        data_.prepare(length + sizeof(package_header));
        data_.sputn(reinterpret_cast<const char *>(&header), sizeof(package_header));
        auto *data_ptr = boost::asio::buffer_cast<const unsigned char*>(data_.data());
        message.SerializeToArray((void*)(&data_ptr[sizeof(package_header)]), length);
        data_.commit(length);
    }
};


#endif //OBELISK_PACKAGE_H
