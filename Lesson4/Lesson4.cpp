#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Calculator.h"

// Define a test fixture class for Calculator tests
class CalculatorTest : public ::testing::Test {
protected:
	// This will be run before each test
	void SetUp() override {
		calc = new Calculator();
	}

	// This will be run after each test
	void TearDown() override {
		delete calc;
	}

	// Pointer to the Calculator instance
	Calculator* calc;
};

// Test addition using the fixture
TEST_F(CalculatorTest, HandlesAddition) {
	EXPECT_EQ(calc->Add(5,3), 8); // pass
	EXPECT_EQ(calc->Add(-2, 4), 2); // pass
}

// Test subtraction using the fixture
TEST_F(CalculatorTest, HandlesSubtraction) {
	EXPECT_EQ(calc->Subtract(10, 3), 7); // pass
	EXPECT_EQ(calc->Subtract(5, 10), -5); // pass
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
