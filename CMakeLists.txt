project(CurrencyConverterApp)

cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_STANDARD 17)

set( CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -O3 -fPIC" )

find_package(OpenSSL REQUIRED)

find_package(ZLIB REQUIRED)

find_package(fmt CONFIG REQUIRED)

find_package(cpr CONFIG REQUIRED)

find_package(nlohmann_json 3.12.0 REQUIRED)

include_directories(include)

add_library(CurConverter SHARED src/CurConverter.cpp)
target_link_libraries(CurConverter PRIVATE fmt::fmt cpr::cpr OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB nlohmann_json::nlohmann_json)

add_executable(app src/main.cpp)
target_link_libraries(app PRIVATE fmt::fmt CurConverter)