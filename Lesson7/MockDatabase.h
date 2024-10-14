#pragma once

#include <gmock/gmock.h>
#include "IDatabase.h"

// Mock class that inherits from IDatabase
class MockDatabase : public IDatabase {
public:
    MOCK_METHOD(bool, Connect, (const std::string& url), (override));
    MOCK_METHOD(bool, GetUser, (int userId, std::string& username), (override));
};
