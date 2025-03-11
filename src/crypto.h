#pragma once

#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <string>

class Crypto {
public:
    static std::string GenerateKeyPair(std::string& publicKey);
    static std::string SignTransaction(const std::string& privateKey, const std::string& data);
    static bool VerifySignature(const std::string& publicKey, const std::string& data, const std::string& signature);
};
