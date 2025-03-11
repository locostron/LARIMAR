void Blockchain::StartMining() {
    while (true) {
        CBlock lastBlock = GetLastBlock();
        CBlock newBlock = Miner::MineBlock(lastBlock);
        AddBlock(newBlock);
        network.BroadcastBlock(newBlock.GetHash());
    }
}
