#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

#include <iostream>

using namespace std;

class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};

class CashPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount << " using Cash\n";
    }
};

class CardPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount << " using Card\n";
    }
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid Rs. " << amount << " using UPI\n";
    }
};

#endif