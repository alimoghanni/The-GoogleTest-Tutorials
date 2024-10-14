// UserManager.h
#pragma once
#include "IDatabase.h"

class UserManager {
public:
    UserManager(IDatabase* db) : database(db) {}

    bool Login(int userId) {
        std::string username;
        return database->GetUser(userId, username);
    }

private:
    IDatabase* database;
};

