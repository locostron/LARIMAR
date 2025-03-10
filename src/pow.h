#pragma once

#include <cstdint>
#include <string>

class ProofOfWork {
public:
    static uint256 MineBlock(uint256 prevHash, int difficulty);
    static bool ValidateBlock(uint256 blockHash, int difficulty);
};
