#include <iostream>
#include "
int main()
{

#ifndef __RDSERVER__
    std::cout << "client" << std::endl;
#endif


//    std::shared_ptr<A> test = std::make_shared<B>();
//
//    std::shared_ptr<A> data1 = std::dynamic_pointer_cast<A>(test);
//    std::shared_ptr<B> data2 = std::dynamic_pointer_cast<B>(test);
//     std::shared_ptr<C> data3 = std::dynamic_pointer_cast<C>(test);
//    std::shared_ptr<D> data4 = std::dynamic_pointer_cast<D>(test);
//
//    int a=0;
//
//
//
//    obelisk::http_router router;
//    router.add_router("/test/{bbq}",[](std::shared_ptr<obelisk::http_request>&)-> std::shared_ptr<obelisk::http_response>{});
//    router


//    sahara::log::initialize();
//    try{
//        obelisk::io_context context;
//        obelisk::http_server server(context, "/Users/hackman/workspace/website/ZK_VSPA_Backend/dist");
//
//        server.listen("0.0.0.0", 3308);
//        std::vector<std::thread> threads;
//        threads.reserve(3);
//
//
//        context.run();
//
//        while (true);
//
////        int listenfd, connfd, efd, ret;
////        listenfd = socket(AF_INET, SOCK_STREAM, 0);
////        sockaddr_in addr{};
////        addr.sin_family = AF_INET;
////        addr.sin_addr.s_addr = htonl(INADDR_ANY);
////        addr.sin_port = htons(3307);
////
////        char data[100] = {0};
////        if(bind(listenfd, (struct sockaddr*)&addr, sizeof(addr)) == -1){
////            THROW(obelisk::network_exception,strerror(errno), "module");
////        }
////
////        if(listen(listenfd, OBELISK_MAX_LISTEN_CONNECTION)){
////            THROW(sahara::exception::database_exception,"message", "module", 200);
////        }
////
////
//    }catch (sahara::exception::exception_base& e){
//        std::cout << e.what() << std::endl;
//    }
    return 0;
}
