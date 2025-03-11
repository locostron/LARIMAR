#include "mining.h"
#include <iostream>
#include <yespower.h>

CBlock Miner::MineBlock(const CBlock& previousBlock) {
    CBlock newBlock(previousBlock.nHeight + 1, previousBlock.GetHash());
    std::cout << "Minando bloque #" << newBlock.nHeight << "..." << std::endl;

    // Parámetros de Yespower
    yespower_params_t params = {YESPOWER_1_0, 2048, 8, "Larimar", 7};

    while (true) {
        std::string data = std::to_string(newBlock.nHeight) + newBlock.prevBlockHash + std::to_string(newBlock.nTime) + std::to_string(newBlock.nNonce);
        unsigned char hash[32];

        if (yespower((const uint8_t*)data.c_str(), data.size(), &params, hash) == 0) {
            std::string hashStr;
            for (int i = 0; i < 32; i++) {
                hashStr += "0123456789abcdef"[hash[i] / 16];
                hashStr += "0123456789abcdef"[hash[i] % 16];
            }

            newBlock.nHash = hashStr;
            std::cout << "Bloque minado con éxito: " << newBlock.nHash << std::endl;
            return newBlock;
        }

        newBlock.nNonce++;
    }
}
