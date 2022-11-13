#include "NickCommand.hpp"

NickCommand::NickCommand(User &user, UserMessage &userMessage, MapUserDao& mapUserDao) : _user(user),
                                                                    _userMessage(userMessage),
                                                                    _mapUserDao(mapUserDao) {}

NickCommand::~NickCommand() {}

/*
 * Можно пеереписать под регулярку, но я хз как !!!
 */
bool isValidNickName(const std::string& nickName){
    if (nickName.size() > 9) {
        return false;
    }
    std::string	special = "-[]\\`^{}";
    for (char i : nickName)
    {
        if (!((i >= 'a' && i <= 'z')
              || (i >= 'A' && i <= 'Z')
              || (i >= '0' && i <= '9')
              || (special.find(i) != std::string::npos))) {
            return false;
        }
    }
    return true;
}

bool NickCommand::isNickNameContainsInDB(const std::string& nickName) {
    std::map<int, User*>::const_iterator iterator = _mapUserDao.getMapUsers().begin();
    while(iterator != _mapUserDao.getMapUsers().end()) {
        if (iterator->second->getNickname() == nickName && _user.getFd() != iterator->second->getFd()) {
            return false;
        }
        iterator++;
    }
    return true;
}

void NickCommand::executing() {
    if (_userMessage.getParameters().empty()) {
        std::cout << "Error message1\n";
    } else if (!isValidNickName(_userMessage.getParameters()[0])) {
        std::cout << "Error message2\n";
    } else if (!isNickNameContainsInDB(_userMessage.getParameters()[0])) {
        std::cout << "Error message3\n";
    }
}
