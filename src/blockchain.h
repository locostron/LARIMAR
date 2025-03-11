#include "mining.h"

class Blockchain {
public:
    std::vector<CBlock> chain;
    P2PNetwork network;

    Blockchain();
    void AddBlock(const CBlock& block);
    void AddTransactionToBlock(const CTransaction& tx);
    void SyncBlockchain();
    void StartMining();
};
