#include "storage.h"
#include <iostream>

void Storage::SaveBlockchain(const Blockchain& blockchain, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error al abrir archivo para guardar blockchain." << std::endl;
        return;
    }
    for (const auto& block : blockchain.chain) {
        file.write(reinterpret_cast<const char*>(&block), sizeof(CBlock));
    }
    file.close();
}

void Storage::LoadBlockchain(Blockchain& blockchain, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "No se encontró un archivo de blockchain, iniciando desde cero." << std::endl;
        return;
    }
    CBlock block;
    while (file.read(reinterpret_cast<char*>(&block), sizeof(CBlock))) {
        blockchain.chain.push_back(block);
    }
    file.close();
}
