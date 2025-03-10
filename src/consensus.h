#ifndef CONSENSUS_H
#define CONSENSUS_H

#include <stdint.h>

namespace Consensus {
    enum DeploymentPos {
        DEPLOYMENT_TESTDUMMY,
        DEPLOYMENT_CSV,
        DEPLOYMENT_SEGWIT,
        MAX_VERSION_BITS_DEPLOYMENTS
    };

    struct Params {
        int nSubsidyHalvingInterval;
        int nPowTargetSpacing;
        int64_t powLimit;
        int nBlockReward;
        uint256 hashGenesisBlock;
    };

    const Params mainParams = {
        170000,                 // Halving cada 170,000 bloques
        40,                     // 40 segundos por bloque
        uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"), // Dificultad inicial
        41 * COIN,              // 41 monedas por bloque
        uint256S("0x...")       // Hash de bloque génesis (por definir)
    };
}

#endif // CONSENSUS_H
