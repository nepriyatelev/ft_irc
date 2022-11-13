#ifndef PASSCOMMAND_HPP
#define PASSCOMMAND_HPP

#include "User.hpp"
#include "UserMessage.hpp"

class PassCommand {
    public:
        PassCommand(User &user, UserMessage &userMessage, std::string &serverPassword);
        virtual ~PassCommand();
        void executing();
    private:
        User& _user;
        UserMessage& _userMessage;
        std::string& _serverPassword;
};

#endif
