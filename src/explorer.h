#pragma once

#include <iostream>
#include <httplib.h>
#include "blockchain.h"

class Explorer {
public:
    Explorer(Blockchain& blockchain, int port);
    void Start();

private:
    Blockchain& blockchain;
    int port;
};
