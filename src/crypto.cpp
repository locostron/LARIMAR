#include "crypto.h"
#include <openssl/sha.h>
#include <iostream>
#include <vector>

std::string Crypto::GenerateKeyPair(std::string& publicKey) {
    EC_KEY* key = EC_KEY_new_by_curve_name(NID_secp256k1);
    EC_KEY_generate_key(key);

    BIO* pri = BIO_new(BIO_s_mem());
    PEM_write_bio_ECPrivateKey(pri, key, nullptr, nullptr, 0, nullptr, nullptr);

    BIO* pub = BIO_new(BIO_s_mem());
    PEM_write_bio_EC_PUBKEY(pub, key);

    char* priKey;
    char* pubKey;
    size_t priLen = BIO_get_mem_data(pri, &priKey);
    size_t pubLen = BIO_get_mem_data(pub, &pubKey);

    std::string privateKey(priKey, priLen);
    publicKey = std::string(pubKey, pubLen);

    BIO_free(pri);
    BIO_free(pub);
    EC_KEY_free(key);

    return privateKey;
}

std::string Crypto::SignTransaction(const std::string& privateKey, const std::string& data) {
    BIO* bio = BIO_new_mem_buf(privateKey.data(), privateKey.size());
    EC_KEY* key = PEM_read_bio_ECPrivateKey(bio, nullptr, nullptr, nullptr);
    BIO_free(bio);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)data.c_str(), data.size(), hash);

    ECDSA_SIG* sig = ECDSA_do_sign(hash, SHA256_DIGEST_LENGTH, key);
    EC_KEY_free(key);

    if (!sig) return "";

    int sigLen = i2d_ECDSA_SIG(sig, nullptr);
    std::vector<unsigned char> signature(sigLen);
    unsigned char* sigPtr = signature.data();
    i2d_ECDSA_SIG(sig, &sigPtr);
    ECDSA_SIG_free(sig);

    return std::string(signature.begin(), signature.end());
}

bool Crypto::VerifySignature(const std::string& publicKey, const std::string& data, const std::string& signature) {
    BIO* bio = BIO_new_mem_buf(publicKey.data(), publicKey.size());
    EC_KEY* key = PEM_read_bio_EC_PUBKEY(bio, nullptr, nullptr, nullptr);
    BIO_free(bio);

    if (!key) return false;

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char*)data.c_str(), data.size(), hash);

    const unsigned char* sigPtr = (const unsigned char*)signature.data();
    ECDSA_SIG* sig = d2i_ECDSA_SIG(nullptr, &sigPtr, signature.size());

    bool valid = ECDSA_do_verify(hash, SHA256_DIGEST_LENGTH, sig, key) == 1;

    ECDSA_SIG_free(sig);
    EC_KEY_free(key);

    return valid;
}
