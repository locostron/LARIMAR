#pragma once

#include <vector>
#include "block.h"

class Blockchain {
public:
    std::vector<CBlock> chain;

    Blockchain();
    void AddBlock(CBlock newBlock);
    CBlock GetLatestBlock() const;
};
