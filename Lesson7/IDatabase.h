// IDatabase.h
#pragma once
#include <string>

class IDatabase {
public:
    virtual ~IDatabase() = default;
    virtual bool Connect(const std::string& url) = 0;
    virtual bool GetUser(int userId, std::string& username) = 0;
};


