#include <iostream>
#include "blockchain.h"
#include "pow.h"
#include "p2p.h"
#include "storage.h"
#include "explorer.h"

int main() {
    Blockchain larimarChain;
    Storage::LoadBlockchain(larimarChain, "larimar_chain.dat");

    P2PNetwork network(42003);
    network.Start();
    
    Explorer explorer(larimarChain, 8080);
    std::thread explorerThread(&Explorer::Start, &explorer);
    explorerThread.detach();

    network.SyncBlockchain(larimarChain);

    CTransaction tx1("Alice", "Bob", 10.5);
    CBlock block;
    block.AddTransaction(tx1);
    
    block.nHash = ProofOfWork::MineBlock(block.GetPrevBlockHash(), 2);
    larimarChain.AddBlock(block);

    std::cout << "Bloque agregado con hash: " << block.nHash << std::endl;

    network.BroadcastBlock(block);
    Storage::SaveBlockchain(larimarChain, "larimar_chain.dat");

    return 0;
}
