#include <gtest/gtest.h>
#include <gmock/gmock.h>

int Add(int a, int b) {
	return a + b;
}


TEST(AdditionTest, HandlesPositiveNumbers) {
	EXPECT_EQ(Add(2, 3), 5); // pass
	ASSERT_EQ(Add(10, 20), 30); // pass
	EXPECT_EQ(Add(5, 6), 11); // pass
	EXPECT_EQ(Add(1, 6), 7); // pass
}


TEST(AdditionTest, HandlesNegativeNumbers) {
	EXPECT_EQ(Add(-2, -3), -5); // pass
	EXPECT_EQ(Add(-10, -20), -30); // pass
}

TEST(AdditionTest, HandlesMixedNumbers) {
	EXPECT_EQ(Add(10, -5), 5); // pass
	EXPECT_EQ(Add(-5, 10), 5); // pass
}

// New test cases using different assertions
TEST(AssertionTest, EqualityAssertions) {
	EXPECT_EQ(10, 10); // pass
	EXPECT_NE(10, 5);  // pass
}

TEST(AssertionTest, BoolenAssertions) {
	EXPECT_TRUE(2 == 2); // pass
	EXPECT_FALSE(1 == 0); // pass
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
