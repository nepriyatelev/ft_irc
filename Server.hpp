#ifndef SERVER_HPP
# define SERVER_HPP

#include "Socket.hpp"
#include "UserMessage.hpp"
#include "User.hpp"
#include "MapUserDao.hpp"
#include "UserMessage.hpp"
#include "CommandService.hpp"
#include <utility>
#include <map>

class Server {
    public:
        Server(int port, const std::string& password);
        virtual ~Server();
        void run();

    private:
        Socket *socket;
        MapUserDao *mapUserDao;
        int port;
        std::string password;
        fd_set master;
        void userRegistration(int fd);
        bool verificationRegisteredUser(int fd);
};


#endif
