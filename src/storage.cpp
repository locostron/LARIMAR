#include "storage.h"
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void Storage::SaveBlockchain(const Blockchain& blockchain) {
    std::ofstream file("blockchain.json");
    if (!file) {
        std::cerr << "Error al abrir blockchain.json para escribir" << std::endl;
        return;
    }

    json blockchainData;
    for (const CBlock& block : blockchain.chain) {
        json blockJson;
        blockJson["height"] = block.nHeight;
        blockJson["prevHash"] = block.prevBlockHash;
        blockJson["hash"] = block.nHash;
        blockJson["time"] = block.nTime;
        blockJson["nonce"] = block.nNonce;

        json transactionsJson;
        for (const CTransaction& tx : block.vTransactions) {
            json txJson;
            txJson["sender"] = tx.sender;
            txJson["receiver"] = tx.receiver;
            txJson["amount"] = tx.amount;
            transactionsJson.push_back(txJson);
        }
        blockJson["transactions"] = transactionsJson;
        blockchainData.push_back(blockJson);
    }

    file << blockchainData.dump(4);
    file.close();
    std::cout << "Blockchain guardada en blockchain.json" << std::endl;
}

void Storage::LoadBlockchain(Blockchain& blockchain) {
    std::ifstream file("blockchain.json");
    if (!file) {
        std::cerr << "No se encontró blockchain.json, iniciando una nueva blockchain" << std::endl;
        return;
    }

    json blockchainData;
    file >> blockchainData;
    file.close();

    blockchain.chain.clear();
    for (const auto& blockJson : blockchainData) {
        CBlock block(blockJson["height"], blockJson["prevHash"]);
        block.nHash = blockJson["hash"];
        block.nTime = blockJson["time"];
        block.nNonce = blockJson["nonce"];

        for (const auto& txJson : blockJson["transactions"]) {
            CTransaction tx(txJson["sender"], txJson["receiver"], txJson["amount"]);
            block.vTransactions.push_back(tx);
        }

        blockchain.chain.push_back(block);
    }

    std::cout << "Blockchain cargada desde blockchain.json" << std::endl;
}
