#include "UserMessage.hpp"

UserMessage::UserMessage(){};

UserMessage::~UserMessage() {};

std::vector<std::string> separationBySpaces(const std::string &s) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, ' ')) {
        result.push_back (item);
    }
    return result;
}

void UserMessage::readMessage(int fd, fd_set& master) {
    std::string message;
    char buff[2];
    buff[0] = 0;
    buff[1] = '\0';
    ssize_t bytes = 0;
    while((bytes = recv(fd, buff, 1, 0) > 0)) {
        if (buff[0] == '\n') {
            break;
        }
        message += buff;
        buff[0] = 0;
    }
    if (bytes <= 0) {
        close(fd);
        FD_CLR(fd, &master);
        if (bytes == -1) {
            throw std::runtime_error("recv() failed");
        }
    }
    if (message.length() > 512) {
        message = message.substr(0, 510);
    }
    std::vector<std::string> splitMessage = separationBySpaces(message);
    parseMessage(splitMessage);
}


void UserMessage::parseMessage(std::vector<std::string>& splitMessage) {
    if (!splitMessage.empty() && splitMessage.front()[0] == ':') {
        prefix = std::string(splitMessage.front().begin() + 1, splitMessage.front().end());
        splitMessage.erase(splitMessage.begin());
    }
    if (!splitMessage.empty()) {
        command = splitMessage.front();
        splitMessage.erase(splitMessage.begin());
    }
    while (!splitMessage.empty()) {
        if (splitMessage.front()[0] == ':') {
            std::string tmpStr(splitMessage.front().begin() + 1, splitMessage.front().end());
            splitMessage.erase(splitMessage.begin());
            while (!splitMessage.empty())
            {
                tmpStr.append(" ");
                tmpStr.append(splitMessage.front());
                splitMessage.erase(splitMessage.begin());
            }
            parameters.push_back(tmpStr);
        } else {
            parameters.push_back(splitMessage.front());
            splitMessage.erase(splitMessage.begin());
        }
    }
}

const std::string &UserMessage::getPrefix() const {
    return prefix;
}

const std::string &UserMessage::getCommand() const {
    return command;
}

const std::vector<std::string> &UserMessage::getParameters() const {
    return parameters;
}


