#pragma once

#include <fstream>
#include "blockchain.h"

class Storage {
public:
    static void SaveBlockchain(const Blockchain& blockchain, const std::string& filename);
    static void LoadBlockchain(Blockchain& blockchain, const std::string& filename);
};
