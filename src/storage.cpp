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
