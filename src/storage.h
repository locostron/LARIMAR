#pragma once

#include "blockchain.h"
#include <fstream>

class Storage {
public:
    static void SaveBlockchain(const Blockchain& blockchain);
    static void LoadBlockchain(Blockchain& blockchain);
};
