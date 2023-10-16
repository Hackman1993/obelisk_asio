/***********************************************************************************************************************
 * @author Hackman Lo
 * @file evented_socket.h
 * @description 
 * @created_at 2023-10-13
***********************************************************************************************************************/

#ifndef OBELISK_EVENTED_SOCKET_H
#define OBELISK_EVENTED_SOCKET_H
#include "details/socket_base.h"
namespace obelisk {
    namespace core {

        class evented_socket {
        public:
            evented_socket(boost::asio::io_context& ctx);
            void on_connected(const std::function<void ()>& callback);
            void on_disconnected(const std::function<void ()>& callback);
        protected:
            std::function<void ()> connected_;
            std::function<void ()> disconnected_;
        };

    } // obelisk
} // core

#endif //OBELISK_EVENTED_SOCKET_H
