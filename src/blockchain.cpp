void Blockchain::SyncBlockchain() {
    std::cout << "Sincronizando blockchain con la red..." << std::endl;
    for (const auto& block : chain) {
        network.BroadcastBlock(block.GetHash());
    }
}
