#pragma once

#include <vector>
#include "transaction.h"

class CBlock {
public:
    int nHeight;
    uint256 prevBlockHash;
    uint256 nHash;
    std::vector<CTransaction> vTransactions;
    int nTime;
    int nNonce;

    uint256 GetHash() const;
    uint256 GetPrevBlockHash() const;
    void AddTransaction(const CTransaction& tx);
};
