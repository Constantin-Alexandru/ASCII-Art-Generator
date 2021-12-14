cmake_minimum_required(VERSION 3.21.4)

#Project Name
project(asciiart)

#Getting every file from source
file(GLOB asciiart_SRC CMAKE_CONFIGURE_DEPENDS ./src/include/*.h ./src/*.cpp)

#Setting program to C++20
set(CMAKE_CXX_STANDARD 20)

#Setting build type to release
set(CMAKE_BUILD_TYPE Release)

#Adding executable
add_executable(${PROJECT_NAME} ${asciiart_SRC})
