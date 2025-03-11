#include "block.h"
#include <iostream>
#include <sstream>
#include <openssl/sha.h>

CBlock::CBlock(int height, std::string prevHash)
    : nHeight(height), prevBlockHash(prevHash), nTime(time(nullptr)), nNonce(0) {}

std::string CBlock::GetHash() const {
    std::stringstream ss;
    ss << nHeight << prevBlockHash << nTime << nNonce;
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)ss.str().c_str(), ss.str().size(), hash);
    std::stringstream hashString;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        hashString << std::hex << (int)hash[i];
    return hashString.str();
}

void CBlock::AddTransaction(const CTransaction& tx) {
    vTransactions.push_back(tx);
}
