#include "User.hpp"

User::User(int fd, UserMessage *userMessage) : _nickname(""),
                                                _userName(""),
                                                _hostName("#"),
                                                _serverName("#"),
                                                _realName(""),
                                                _fd(fd),
                                                _channelOperator(false),
                                                _password(false),
                                                _registered(false),
                                                _userMessage(userMessage) {}

User::~User() {}

const std::string &User::getNickname() const {
    return _nickname;
}

void User::setNickname(const std::string &nickname) {
    _nickname = nickname;
}

const std::string &User::getUserName() const {
    return _userName;
}

void User::setUserName(const std::string &userName) {
    _userName = userName;
}

const std::string &User::getHostName() const {
    return _hostName;
}

void User::setHostName(const std::string &hostName) {
    _hostName = hostName;
}

const std::string &User::getServerName() const {
    return _serverName;
}

void User::setServerName(const std::string &serverName) {
    _serverName = serverName;
}

const std::string &User::getRealName() const {
    return _realName;
}

void User::setRealName(const std::string &realName) {
    _realName = realName;
}

int User::getFd() const {
    return _fd;
}

void User::setFd(int fd) {
    _fd = fd;
}

bool User::isChannelOperator() const {
    return _channelOperator;
}

void User::setChannelOperator(bool channelOperator) {
    _channelOperator = channelOperator;
}

bool User::isPassword() const {
    return _password;
}

void User::setPassword(bool password) {
    _password = password;
}

bool User::isRegistered() const {
    return _registered;
}

void User::setRegistered(bool registered) {
    _registered = registered;
}

UserMessage *User::getUserMessage() const {
    return _userMessage;
}

void User::setUserMessage(UserMessage *userMessage) {
    _userMessage = userMessage;
}

