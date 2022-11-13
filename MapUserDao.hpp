#ifndef MAPUSERDAO_HPP
# define MAPUSERDAO_HPP

#include <map>
#include "User.hpp"

class MapUserDao {
    public:
        MapUserDao();
        virtual ~MapUserDao();
        void addUser(int fd, User& user);
        void delUser(int fd);
        User *getUser(int fd);
        const std::map<int, User *> &getMapUsers() const;

    private:
        std::map<int, User*> mapUsers;
};

#endif
