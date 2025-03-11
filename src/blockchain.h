#include "network.h"

class Blockchain {
public:
    std::vector<CBlock> chain;
    P2PNetwork network;  // Agregar la red P2P

    Blockchain();
    void AddBlock(const CBlock& block);
    void AddTransactionToBlock(const CTransaction& tx);
    void SyncBlockchain();
};
