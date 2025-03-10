#pragma once

#include <string>

class CTransaction {
public:
    std::string sender;
    std::string receiver;
    double amount;

    CTransaction(std::string sender, std::string receiver, double amount);
};
