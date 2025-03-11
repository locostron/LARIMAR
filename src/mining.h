#pragma once

#include "block.h"

class Miner {
public:
    static CBlock MineBlock(const CBlock& previousBlock);
};
