#ifndef SOCKET_HPP
# define SOCKET_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <stdexcept>
#include <iostream>
#include <netinet/in.h>
#include <sys/select.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

class Socket {
    public:
        Socket();
        ~Socket();
        int createSocket(int port);
        void listeningSocket(int fdSocket);
        int acceptingConnections(int fdSocket);

    private:
        void configSocket(int fdSocket);
        void bindingSocket(int port, int fdSocket);
};

#endif