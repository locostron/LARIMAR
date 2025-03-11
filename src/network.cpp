#include "network.h"
#include <iostream>

void P2PNetwork::ConnectToPeer(const std::string& peer) {
    peerList.push_back(peer);
    std::cout << "Conectado a nodo: " << peer << std::endl;
}

void P2PNetwork::BroadcastTransaction(const std::string& txData) {
    for (const std::string& peer : peerList) {
        std::cout << "Enviando transacción a " << peer << ": " << txData << std::endl;
    }
}

void P2PNetwork::BroadcastBlock(const std::string& blockData) {
    for (const std::string& peer : peerList) {
        std::cout << "Enviando bloque a " << peer << ": " << blockData << std::endl;
    }
}
