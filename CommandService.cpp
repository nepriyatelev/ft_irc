#include "CommandService.hpp"

CommandService::CommandService(std::string& serverPassword, User &user, MapUserDao &mapUserDao) :
                                                                                                _serverPassword(serverPassword),
                                                                                                _user(user),
                                                                                                _mapUserDao(mapUserDao) {
    _mapMethods["PASS"] = &CommandService::pass;
    _mapMethods["NICK"] = &CommandService::nick;
}

CommandService::~CommandService(){};

void CommandService::definitionCommands() {
    if (_mapMethods.find(_user.getUserMessage()->getCommand()) != _mapMethods.end()) {
       (this->*_mapMethods[_user.getUserMessage()->getCommand()])();
    }
}

void CommandService::pass() {
    PassCommand *passCommand = new PassCommand(_user, *_user.getUserMessage(), _serverPassword);
    passCommand->executing();
    delete passCommand;
}

void CommandService::nick() {
    NickCommand *nickCommand = new NickCommand(_user, *_user.getUserMessage(), _mapUserDao);
    nickCommand->executing();
    delete nickCommand;
}
