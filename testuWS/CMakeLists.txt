cmake_minimum_required(VERSION 3.10)
PROJECT(main)
add_definitions(-DOTL_ODBC_UNIX)
add_definitions(-DUSE_LIBUV)
IF(APPLE)
    add_definitions(-DSPDLOG_FMT_EXTERNAL)
    include_directories(/Users/alqazy/source/vcpkg/installed/x64-osx/include)
    include_directories(/usr/local/include)
    link_directories(/Users/alqazy/source/vcpkg/installed/x64-osx/lib)
    link_directories(/usr/local/lib)
ELSEIF(UNIX)
    include_directories(/root/source/vcpkg/installed/x64-linux/include)
    link_directories(/root/source/vcpkg/installed/x64-linux/lib)
ENDIF()
link_libraries(uWS)
link_libraries(ssl)
link_libraries(fmt)
link_libraries(crypto)
link_libraries(protobuf)
link_libraries(cpp_redis)
link_libraries(tacopie)
link_libraries(xxhash)
link_libraries(z)
link_libraries(dl)
link_libraries(libuv)
link_libraries(pthread)
link_libraries(odbc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(ccserver ${DIR_SRCS})
