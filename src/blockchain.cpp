#include "blockchain.h"
#include <iostream>

Blockchain::Blockchain() {
    chain.push_back(CBlock(0, "0")); // Bloque génesis
}

void Blockchain::AddBlock(const CBlock& block) {
    chain.push_back(block);
}

CBlock Blockchain::GetLastBlock() const {
    return chain.back();
}
