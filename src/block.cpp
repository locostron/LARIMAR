#include "block.h"

void CBlock::AddTransaction(const CTransaction& tx) {
    vTransactions.push_back(tx);
}
