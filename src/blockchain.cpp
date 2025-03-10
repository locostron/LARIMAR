#include "blockchain.h"

Blockchain::Blockchain() {
    CBlock genesisBlock;
    chain.push_back(genesisBlock);
}

void Blockchain::AddBlock(CBlock newBlock) {
    newBlock.prevBlockHash = GetLatestBlock().GetHash();
    chain.push_back(newBlock);
}

CBlock Blockchain::GetLatestBlock() const {
    return chain.back();
}
