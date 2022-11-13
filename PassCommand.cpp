#include "PassCommand.hpp"

PassCommand::PassCommand(User &user, UserMessage &userMessage, std::string &serverPassword) : _user(user),
                                                                                              _userMessage(userMessage),
                                                                                              _serverPassword(serverPassword) {}

PassCommand::~PassCommand(){};

void PassCommand::executing() {
    if (_userMessage.getParameters().empty()) {
        std::cout << "Error message1\n";
    } else if (_user.isPassword()) {
        std::cout << "Error message2\n";
    } else if (!_user.getNickname().empty() && !_user.getUserName().empty() && !_user.getRealName().empty()) {
        return;
    } else {
        if (_serverPassword == _userMessage.getParameters()[0]) {
            std::cout << "success!!!" << std::endl;
            _user.setPassword(true);
        }
    }
}
