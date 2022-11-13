#ifndef COMMANDSERVICE_HPP
#define COMMANDSERVICE_HPP

#include <iostream>
#include <map>
#include <utility>
#include "User.hpp"
#include "UserMessage.hpp"
#include "MapUserDao.hpp"
#include "PassCommand.hpp"
#include "NickCommand.hpp"

class CommandService {
public:
    CommandService(std::string& serverPassword, User& user, MapUserDao& mapUserDao);
    virtual ~CommandService();
    void definitionCommands();
private:
    typedef void(CommandService::*func)();
    User& _user;
    MapUserDao& _mapUserDao;
    std::string& _serverPassword;
    std::map<std::string, func> _mapMethods;
    void pass();
    void nick();
};

#endif
