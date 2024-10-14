#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MockDatabase.h"
#include "UserManager.h"

using ::testing::Return;
using ::testing::_;  // Matcher for any argument

// Test that Login succeeds when GetUser returns true
TEST(UserManagerTest, LoginSuccess) {
    // Arrange
    MockDatabase mockDb;
    UserManager userManager(&mockDb);

    // Expect the GetUser method to be called with any int argument and return true
    EXPECT_CALL(mockDb, GetUser(_, _))
        .WillOnce(Return(true));  // Simulate successful user retrieval

    // Act
    bool result = userManager.Login(1);

    // Assert
    EXPECT_TRUE(result);  // Test passes if Login returns true
}

// Test that Login fails when GetUser returns false
TEST(UserManagerTest, LoginFailure) {
    // Arrange
    MockDatabase mockDb;
    UserManager userManager(&mockDb);

    // Expect GetUser to return false this time
    EXPECT_CALL(mockDb, GetUser(_, _))
        .WillOnce(Return(false));  // Simulate failed user retrieval

    // Act
    bool result = userManager.Login(1);

    // Assert
    EXPECT_FALSE(result);  // Test passes if Login returns false
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
