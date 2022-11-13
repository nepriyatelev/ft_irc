#include "Socket.hpp"


Socket::Socket() {

}

Socket::~Socket() {

}

int Socket::createSocket(int port) {
    int fdSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (fdSocket == -1) {
        throw std::runtime_error("socket() failed");
    }
    configSocket(fdSocket);
    bindingSocket(port, fdSocket);
    return fdSocket;
}

void Socket::configSocket(int fdSocket) {
    int optVal = 1;
    int status = setsockopt(fdSocket, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(int));
    if (status == -1) {
        throw std::runtime_error("setsockopt() failed");
    }
}

void Socket::bindingSocket(int port, int fdSocket) {
    struct sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    hint.sin_addr.s_addr = INADDR_ANY;
    int status = bind(fdSocket, (struct sockaddr*)&hint, sizeof(hint));
    if (status == -1) {
        throw std::runtime_error("bind() failed");
    }
}

void Socket::listeningSocket(int fdSocket) {
    int status = listen(fdSocket, 5);
    if (status == -1) {
        throw std::runtime_error("listen() failed");
    }
}

int Socket::acceptingConnections(int fdSocket) {
    char clientIp[INET_ADDRSTRLEN];
    int fdClient = -1;
    struct sockaddr_storage clientAdd;
    socklen_t addLen = sizeof(clientAdd);
    fdClient = accept(fdSocket, (struct sockaddr *)&clientAdd, &addLen);
    if (fdClient == -1) {
        throw std::runtime_error("accept() failed");
    }
    inet_ntop(clientAdd.ss_family, &((struct sockaddr_in*)&clientAdd)->sin_addr, clientIp, INET_ADDRSTRLEN);
    std::cout << "Server: new connection from " << clientIp << " on socket " << fdClient << std::endl;
    return fdClient;
}


