#include <gtest/gtest.h>
#include <gmock/gmock.h>

// A simple function to add two integers
int Add(int a, int b) {
	return a + b;
}

// A test case to test the Add function with positive numbers
TEST(AdditionTest, PositiveNumbers) {
	EXPECT_EQ(Add(2, 3), 5); // pass
	EXPECT_EQ(Add(10, 20), 30); // pass
}

// A test case to test the Add function with negative numbers
TEST(AdditionTest, NagativeNumbers) {
	EXPECT_EQ(Add(-2, -3), -5);
	EXPECT_EQ(Add(-10, -20), -30);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
