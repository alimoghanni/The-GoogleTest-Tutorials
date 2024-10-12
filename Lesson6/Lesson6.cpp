#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdexcept>


void Division(int a, int b) {
    if (b == 0)
    {
        throw std::invalid_argument("Divide by zero!");
    }
}


TEST(EXceptionTest, HandlesZeroDivision) {
    EXPECT_THROW(Division(10, 0), std::invalid_argument); // pass
    EXPECT_NO_THROW(Division(10, 2)); // pass
}

TEST(FloatingPointTest, HandlesFloatingPoint) {
    EXPECT_NEAR(0.1 + 0.2, 0.3, 1e-9); // pass
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
