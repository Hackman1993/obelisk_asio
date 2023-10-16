/***********************************************************************************************************************
 * @author Hackman Lo
 * @file package_header.h
 * @description 
 * @created_at 2023-10-16
***********************************************************************************************************************/

#ifndef OBELISK_PACKAGE_HEADER_H
#define OBELISK_PACKAGE_HEADER_H
#include <cstdint>
#include <arpa/inet.h>
enum message_type{
    mt_none = 0,
    mt_client_register = 1,
};
struct package_header {
    std::uint32_t identifier_ = htonl(0x19930323);
    unsigned int type_ = htonl(mt_none);
    std::uint32_t length_ = 0;
};


#endif //OBELISK_PACKAGE_HEADER_H
