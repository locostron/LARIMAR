#include "transaction.h"
#include <sstream>
#include <openssl/sha.h>

CTransaction::CTransaction(std::string sender, std::string receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount) {}

std::string CTransaction::GetTransactionHash() const {
    std::stringstream ss;
    ss << sender << receiver << amount;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)ss.str().c_str(), ss.str().size(), hash);
    std::stringstream hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        hashString << std::hex << (int)hash[i];
    return hashString.str();
}
