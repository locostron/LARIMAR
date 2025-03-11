#include "blockchain.h"

void Blockchain::AddTransactionToBlock(const CTransaction& tx) {
    CBlock& lastBlock = chain.back();
    lastBlock.AddTransaction(tx);
}
