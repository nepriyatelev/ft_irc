#include "MapUserDao.hpp"

MapUserDao::MapUserDao(){};

MapUserDao::~MapUserDao(){};

void MapUserDao::addUser(int fd, User &user) {
    mapUsers[fd] = &user;
}

void MapUserDao::delUser(int fd) {
    delete mapUsers[fd];
    mapUsers.erase(fd);
}

User *MapUserDao::getUser(int fd) {
    return mapUsers[fd];
}

const std::map<int, User *> &MapUserDao::getMapUsers() const {
    return mapUsers;
}


