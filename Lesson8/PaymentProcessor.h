// PaymentProcessor.h
#pragma once
#include "PaymentGateway.h"

class PaymentProcessor {
public:
    PaymentProcessor(PaymentGateway* gateway) : gateway_(gateway) {}

    bool ProcessTransaction(const std::string& accountId, double amount) {
        if (amount > 0) {
            return gateway_->ProcessPayment(accountId, amount);
        }
        return false;
    }

private:
    PaymentGateway* gateway_;
};
