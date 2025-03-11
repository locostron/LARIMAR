#pragma once

#include <vector>
#include "block.h"

class Blockchain {
public:
    std::vector<CBlock> chain;

    Blockchain();
    void AddBlock(const CBlock& block);
    CBlock GetLastBlock() const;
};
