#include "Server.hpp"


Server::Server(int port, const std::string& password) : socket(new Socket),
                                                        mapUserDao(new MapUserDao),
                                                        port(port),
                                                        password(password),
                                                        master() {}

Server::~Server() {
    delete socket;
    delete mapUserDao;
}

void Server::run() {
    FD_ZERO(&master);
    int listeningSocket = socket->createSocket(port);
    socket->listeningSocket(listeningSocket);
    FD_SET(listeningSocket, &master);
    int fdMax = listeningSocket;
    int fdNew = 0;
    while(1) {
        fd_set copy = master;
        int sockCount = select(fdMax + 1, &copy, nullptr, nullptr, nullptr);
        if (sockCount == -1) {
            throw std::runtime_error("select() failed");
        }
        for (int i = 0; i <= fdMax ; i++) {
                if (FD_ISSET(i, &copy)) {
                    if (i == listeningSocket) {
                        fdNew = socket->acceptingConnections(listeningSocket);
                        FD_SET(fdNew, &master);
                        if (fdNew > fdMax) fdMax = fdNew;
                    } else {
                        if (!verificationRegisteredUser(fdNew))
                            userRegistration(i);
                        }
//                        else {
//                            ssize_t bytes = recv(i, buf, sizeof(buf), 0);
//                            for(int j = 0; j <= fdMax; j++) {
//                                // send to everyone!
//                                if (FD_ISSET(j, &master)) {
//                                    // except the listener and ourselves
//                                    if (j != listeningSocket && j != i) {
//                                        if (send(j, buf, bytes, 0) == -1) {
//                                            perror("send");
//                                        }
//                                    }
//                                }
//                            }
//                        }
//                    }
                }
        }
    }
}

void Server::userRegistration(int fd) {
    UserMessage *userMessage = new UserMessage();
    userMessage->readMessage(fd, master);
    User *user = new User(fd, userMessage);
    mapUserDao->addUser(fd, *user);
    CommandService *commandService = new CommandService(password, *user, *mapUserDao);
    commandService->definitionCommands();
    delete userMessage;
    delete commandService;
    std::cout << user->isPassword() << std::endl;
}

bool Server::verificationRegisteredUser(int fd) {
    User *user = mapUserDao->getUser(fd);
    if (user == nullptr) {
        return false;
    }
    return user->isRegistered();
}



