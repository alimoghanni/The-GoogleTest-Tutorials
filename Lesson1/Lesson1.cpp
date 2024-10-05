#include <gtest/gtest.h>
#include <gmock/gmock.h>

// A simple test case
TEST(SampleTest, Test1) {
	EXPECT_EQ(1, 1);  // This test passes
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
