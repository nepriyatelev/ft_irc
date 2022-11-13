#ifndef USERMESSAGE_HPP
#define USERMESSAGE_HPP

#include <sstream>
#include <utility>
#include <iostream>
#include <vector>
#include <arpa/inet.h>
#include <unistd.h>

class UserMessage {
    public:
        UserMessage();
        virtual ~UserMessage();
        void readMessage(int fd, fd_set& master);
        const std::string &getCommand() const;
        const std::string &getPrefix() const;
        const std::vector<std::string> &getParameters() const;

    private:
        std::string prefix;
        std::string command;
        std::vector<std::string> parameters;
        void parseMessage(std::vector<std::string>& splitMessage);
};

#endif
