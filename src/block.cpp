#include "block.h"
#include "validation.h"

void CBlock::AddTransaction(const CTransaction& tx) {
    if (TransactionValidator::IsValid(tx)) {
        vTransactions.push_back(tx);
    } else {
        std::cerr << "Transacción rechazada." << std::endl;
    }
}
