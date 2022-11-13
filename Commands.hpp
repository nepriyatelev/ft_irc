#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <map>
#include "models/includes/User.hpp"
#include "models/includes/UserMessage.hpp"
#include "repositories/includes/MapUserDao.hpp"

class Commands {
    public:
        Commands(std::string serverPassword, User& user, UserMessage& userMessage, MapUserDao& mapUserDao);
        virtual ~Commands();
        void definitionCommands();

    private:
        User& user;
        UserMessage& userMessage;
        MapUserDao& mapUserDao;
        std::string serverPassword;
        std::map<std::string, std::function<void()>> mapMethods;
        bool isValidNickName(const std::string& nickName);
        bool isNickNameContainsInDB(const std::string& nickName);
        void pass();
        void nick();
};

#endif
