#include "Commands.hpp"

#include <utility>

Commands::Commands(std::string serverPassword, User& user, UserMessage& userMessage, MapUserDao& mapUserDao) : serverPassword(std::move(serverPassword)),
                                                                                                               user(user),
                                                                                                               userMessage(userMessage),
                                                                                                               mapUserDao(mapUserDao) {
    mapMethods.insert(std::pair<std::string, std::function<void()>>("PASS", std::bind(&Commands::pass, this)));
}

Commands::~Commands() {

}

void Commands::definitionCommands() {
    if (mapMethods.find(userMessage.getCommand()) != mapMethods.end()) {
        mapMethods[userMessage.getCommand()]();
    }
}

void Commands::pass() {
    if (userMessage.getParameters().empty()) {
        std::cout << "Error message1\n";
    } else if (user.isPassword()) {
        std::cout << "Error message2\n";
    } else if (!user.getNickName().empty() && !user.getUserName().empty() && !user.getRealName().empty()) {
        return;
    } else {
        if (serverPassword == userMessage.getParameters()[0]) {
            std::cout << "ПОЛУЧИЛОСЬ!" << std::endl;
            user.setPassword(true);
        }
    }
}

void Commands::nick() {
    if (userMessage.getParameters().empty()) {
        std::cout << "Error message1\n";
    } else if (!isValidNickName(userMessage.getParameters()[0])) {
        std::cout << "Error message2\n";
    } else if (!isNickNameContainsInDB(userMessage.getParameters()[0])) {
        std::cout << "Error message3\n";
    } if (isNickNameContainsInDB(userMessage.getParameters()[0]) && )
}

/*
 * Можно пеереписать под регулярку, но я хз как !!!
 */
bool Commands::isValidNickName(const std::string& nickName){
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

bool Commands::isNickNameContainsInDB(const std::string& nickName) {
    std::map<int, User*>::const_iterator iterator = mapUserDao.getMapUsers().begin();
    while(iterator != mapUserDao.getMapUsers().end()) {
        if (iterator->second->getNickName() == nickName && user.getFd() != iterator->second->getFd()) {
            return false;
        }
        iterator++;
    }
    return true;
}


