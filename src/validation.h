#pragma once

#include "transaction.h"

class TransactionValidator {
public:
    static bool IsValid(const CTransaction& tx);
};
