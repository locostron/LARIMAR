#include "pow.h"
#include <iostream>
#include <sstream>

uint256 ProofOfWork::MineBlock(uint256 prevHash, int difficulty) {
    uint256 hash;
    int nonce = 0;
    
    do {
        std::stringstream ss;
        ss << prevHash << nonce;
        hash = std::hash<std::string>{}(ss.str());
        nonce++;
    } while (hash % difficulty != 0);

    return hash;
}

bool ProofOfWork::ValidateBlock(uint256 blockHash, int difficulty) {
    return (blockHash % difficulty == 0);
}
