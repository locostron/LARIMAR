#pragma once

#include <vector>
#include <string>
#include "transaction.h"

class CBlock {
public:
    int nHeight;
    std::string prevBlockHash;
    std::string nHash;
    std::vector<CTransaction> vTransactions;
    int nTime;
    int nNonce;

    CBlock(int height, std::string prevHash);
    std::string GetHash() const;
    void AddTransaction(const CTransaction& tx);
};
