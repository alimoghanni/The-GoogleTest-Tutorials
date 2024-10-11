#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <tuple>

// A simple Add function
int Add(int a, int b) {
	return a + b;
}

// Define a test fixture for parameterized tests
class AddTest : public ::testing::TestWithParam<std::tuple<int, int, int>> {};

// Test the Add function using different parameterized inputs
TEST_P(AddTest, HandlesVariousInputs) {
	int a = std::get<0>(GetParam());
	int b = std::get<1>(GetParam());
	int expected = std::get<2>(GetParam());

	EXPECT_EQ(Add(a, b), expected);
}

// Provide multiple sets of parameters (input1, input2, expected_output)
INSTANTIATE_TEST_SUITE_P(
    AddTests,
    AddTest,
    ::testing::Values(
        std::make_tuple(1, 1, 2),
        std::make_tuple(-1, -1, -2),
        std::make_tuple(5, 7, 12),
        std::make_tuple(0, 0, 0)
    )
);


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
