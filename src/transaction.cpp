#include "transaction.h"

CTransaction::CTransaction(std::string sender, std::string receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount) {}
