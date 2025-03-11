#include "crypto.h"

class CTransaction {
public:
    std::string sender;
    std::string receiver;
    double amount;
    std::string signature;

    CTransaction(std::string sender, std::string receiver, double amount);
    void SignTransaction(const std::string& privateKey);
    bool IsValid() const;
};
