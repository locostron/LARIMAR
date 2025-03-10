#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <asio.hpp>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include "blockchain.h"

class P2PNetwork {
public:
    P2PNetwork(int port);
    void Start();
    void ConnectToPeer(const std::string& address, int port);
    void BroadcastBlock(const CBlock& block);
    void SyncBlockchain(Blockchain& blockchain);
    void Listen();

private:
    int port;
    std::vector<std::string> peers;
    asio::io_context io_context;
    SSL_CTX* ctx;

    void InitSSL();
    SSL* CreateSSLConnection(int socket);
};
