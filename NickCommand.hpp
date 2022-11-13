#ifndef NICKCOMMAND_HPP
#define NICKCOMMAND_HPP

#include "User.hpp"
#include "UserMessage.hpp"
#include "MapUserDao.hpp"

class NickCommand {
public:
    NickCommand(User &user, UserMessage &userMessage, MapUserDao& mapUserDao);
    virtual ~NickCommand();
    void executing();
private:
    User& _user;
    UserMessage& _userMessage;
    MapUserDao& _mapUserDao;
    bool isNickNameContainsInDB(const std::string& nickName);
};


#endif
