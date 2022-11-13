#ifndef USER_HPP
#define USER_HPP

#include <iostream>
#include "UserMessage.hpp"

class User {
    public:
        User(int fd, UserMessage *userMessage);
        virtual ~User();
        const std::string &getNickname() const;
        void setNickname(const std::string &nickname);
        const std::string &getUserName() const;
        void setUserName(const std::string &userName);
        const std::string &getHostName() const;
        void setHostName(const std::string &hostName);
        const std::string &getServerName() const;
        void setServerName(const std::string &serverName);
        const std::string &getRealName() const;
        void setRealName(const std::string &realName);
        int getFd() const;
        void setFd(int fd);
        bool isChannelOperator() const;
        void setChannelOperator(bool channelOperator);
        bool isPassword() const;
        void setPassword(bool password);
        bool isRegistered() const;
        void setRegistered(bool registered);
        UserMessage *getUserMessage() const;
        void setUserMessage(UserMessage *userMessage);

    private:
        std::string _nickname;
        std::string _userName;
        std::string _hostName;
        std::string _serverName;
        std::string _realName;
        int _fd;
        bool _channelOperator;
        bool _password;
        bool _registered;
        UserMessage *_userMessage;
};


#endif
