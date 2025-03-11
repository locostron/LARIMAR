#pragma once

#include "blockchain.h"
#include "crow_all.h"

class Explorer {
public:
    static void StartServer(Blockchain& blockchain);
};
