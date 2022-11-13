#include <iostream>
#include "Server.hpp"
int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "./ircserv [port] [password]\n";
        return 1;
    }
    Server *server = new Server(atoi(argv[1]), argv[2]);
    server->run();
}
