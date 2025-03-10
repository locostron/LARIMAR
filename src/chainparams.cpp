#include "chainparams.h"

static CBlock CreateGenesisBlock(...) {
    const char* pszTimestamp = "Larimar (LAR) - Nueva criptomoneda lanzada en 2025";
    const CScript genesisOutputScript = CScript() << ParseHex("04ffff001d0104") << OP_CHECKSIG;
    return CreateGenesisBlock(pszTimestamp, genesisOutputScript, 1710000000, 0, 0x1e0ffff0, 1, 41 * COIN);
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        strNetworkID = "main";
        consensus.nSubsidyHalvingInterval = 170000;
        consensus.nPowTargetSpacing = 40;
        consensus.powLimit = uint256S("00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff");
        consensus.nBlockReward = 41 * COIN;
        pchMessageStart[0] = 0x4c; // "L"
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 48); // Prefijo de dirección "L"

        genesis = CreateGenesisBlock();
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock == uint256S("0x...")); // Se reemplazará con el hash correcto

        vSeeds.emplace_back("dnsseed.larimar.org");
    }
};
