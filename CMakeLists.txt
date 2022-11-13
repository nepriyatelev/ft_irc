cmake_minimum_required(VERSION 3.22)
project(ft_irc)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c98")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

include_directories(.)

add_executable(ft_irc
        Main.cpp
        Socket.cpp
        Socket.hpp
        User.cpp
        User.hpp
        UserMessage.cpp
        UserMessage.hpp
        Server.cpp
        Server.hpp
        MapUserDao.cpp
        MapUserDao.hpp
        CommandService.cpp
        CommandService.hpp
        PassCommand.cpp
        PassCommand.hpp
        NickCommand.cpp NickCommand.hpp)

set_property(TARGET ft_irc PROPERTY CXX_STANDARD 98)
