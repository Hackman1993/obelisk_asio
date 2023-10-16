file(GLOB_RECURSE COMMON_SOURCES common/*.h common/*.cpp common/*.cc)
file(GLOB_RECURSE SERVER_SOURCES server/*.h server/*.cpp)
file(GLOB_RECURSE CLIENT_SOURCES client/*.h client/*.cpp)
file(GLOB_RECURSE PROTOBUF_FILES ./common/protos/*.proto)

find_package(sahara REQUIRED)
find_package(Protobuf REQUIRED)
set(Protobuf_IMPORT_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/common/protos)
set(protobuf_generate_PROTOC_OUT_DIR common/protos)

add_executable(rdserver ${COMMON_SOURCES} ${SERVER_SOURCES} )
target_include_directories(rdserver PRIVATE ../include)
target_compile_definitions(rdserver PRIVATE -D__RDSERVER__)

add_executable(rdclient ${COMMON_SOURCES} ${CLIENT_SOURCES} )
target_include_directories(rdclient PRIVATE ../include)
message(${Protobuf_IMPORT_DIRS})
add_custom_command(
        PRE_BUILD
        TARGET rdserver
        COMMAND protobuf::protoc --proto_path=${Protobuf_IMPORT_DIRS} --cpp_out=${Protobuf_IMPORT_DIRS} ${PROTOBUF_FILES}
        VERBATIM )

add_custom_command(
        PRE_BUILD
        TARGET rdclient
        COMMAND protobuf::protoc --proto_path=${Protobuf_IMPORT_DIRS} --cpp_out=${Protobuf_IMPORT_DIRS} ${PROTOBUF_FILES}
        VERBATIM )
target_include_directories(rdserver PRIVATE "./")
target_link_libraries(rdserver PRIVATE $<$<BOOL:${WIN32}>:ws2_32> $<$<BOOL:${WIN32}>:Mswsock> obelisk sahara::sahara)
target_link_libraries(rdserver PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)
target_link_libraries(rdclient PRIVATE $<$<BOOL:${WIN32}>:ws2_32> $<$<BOOL:${WIN32}>:Mswsock> obelisk sahara::sahara)
target_link_libraries(rdclient PRIVATE protobuf::libprotoc protobuf::libprotobuf protobuf::libprotobuf-lite)