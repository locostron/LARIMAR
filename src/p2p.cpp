#include "p2p.h"

P2PNetwork::P2PNetwork(int port) : port(port) {
    InitSSL();
}

void P2PNetwork::InitSSL() {
    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    ctx = SSL_CTX_new(TLS_server_method());
}

SSL* P2PNetwork::CreateSSLConnection(int socket) {
    SSL* ssl = SSL_new(ctx);
    SSL_set_fd(ssl, socket);
    return ssl;
}

void P2PNetwork::Start() {
    std::thread listener(&P2PNetwork::Listen, this);
    listener.detach();
}

void P2PNetwork::ConnectToPeer(const std::string& address, int port) {
    peers.push_back(address + ":" + std::to_string(port));
    std::cout << "Conectado a " << address << ":" << port << " con SSL" << std::endl;
}

void P2PNetwork::BroadcastBlock(const CBlock& block) {
    for (const auto& peer : peers) {
        std::cout << "Enviando bloque a " << peer << std::endl;
        // Se enviará con cifrado SSL
    }
}

void P2PNetwork::SyncBlockchain(Blockchain& blockchain) {
    std::cout << "Solicitando sincronización de blockchain..." << std::endl;
    // Lógica para pedir y comparar bloques con otros nodos
}

void P2PNetwork::Listen() {
    std::cout << "Nodo seguro escuchando en el puerto " << port << "..." << std::endl;
}
