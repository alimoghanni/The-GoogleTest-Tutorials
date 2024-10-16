#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MockPaymentGateway.h"
#include "PaymentProcessor.h"

using ::testing::Return;
using ::testing::_;

TEST(PaymentProcessorTest, ProcessesPaymentSuccessfully) {
    MockPaymentGateway mockGateway;
    PaymentProcessor processor(&mockGateway);

    // Set up expectations for ProcessPayment to return true
    EXPECT_CALL(mockGateway, ProcessPayment("user123", 100.0))
        .WillOnce(Return(true));

    bool result = processor.ProcessTransaction("user123", 100.0);

    // Verify that the transaction is processed successfully
    EXPECT_TRUE(result);
}

TEST(PaymentProcessorTest, FailsForNegativeAmount) {
    MockPaymentGateway mockGateway;
    PaymentProcessor processor(&mockGateway);

    // No call to ProcessPayment should occur for a negative amount
    EXPECT_CALL(mockGateway, ProcessPayment(_, _)).Times(0);

    bool result = processor.ProcessTransaction("user123", -50.0);

    EXPECT_FALSE(result);  // Test passes if false is returned
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
