// PaymentGateway.h
#pragma once
#include <string>

class PaymentGateway {
public:
    virtual ~PaymentGateway() = default;
    virtual bool ProcessPayment(const std::string& accountId, double amount) = 0;
};

