#include "explorer.h"
#include <iostream>

void Explorer::StartServer(Blockchain& blockchain) {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([&blockchain]() {
        crow::json::wvalue blocks;
        for (size_t i = 0; i < blockchain.chain.size(); i++) {
            CBlock block = blockchain.chain[i];
            crow::json::wvalue blockJson;
            blockJson["height"] = block.nHeight;
            blockJson["prevHash"] = block.prevBlockHash;
            blockJson["hash"] = block.nHash;
            blockJson["time"] = block.nTime;
            blockJson["nonce"] = block.nNonce;
            blocks[i] = blockJson;
        }
        return blocks;
    });

    std::cout << "Explorador de bloques corriendo en http://localhost:18080" << std::endl;
    app.port(18080).multithreaded().run();
}
