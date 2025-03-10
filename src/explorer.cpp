#include "explorer.h"

Explorer::Explorer(Blockchain& blockchain, int port) : blockchain(blockchain), port(port) {}

void Explorer::Start() {
    httplib::Server svr;

    svr.Get("/blocks", [&](const httplib::Request&, httplib::Response& res) {
        std::string result = "Blockchain:\n";
        for (const auto& block : blockchain.chain) {
            result += "Bloque " + std::to_string(block.nHeight) + " - Hash: " + block.nHash.ToString() + "\n";
        }
        res.set_content(result, "text/plain");
    });

    svr.listen("0.0.0.0", port);
}
