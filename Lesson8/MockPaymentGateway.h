#pragma once
#include <gmock/gmock.h>
#include "PaymentGateway.h"
class MockPaymentGateway : public PaymentGateway
{
public:
	MOCK_METHOD(bool, ProcessPayment, (const std::string& accountId, double amount), (override));
};

