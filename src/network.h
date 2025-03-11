#pragma once

#include <string>
#include <vector>

class P2PNetwork {
public:
    std::vector<std::string> peerList;

    void ConnectToPeer(const std::string& peer);
    void BroadcastTransaction(const std::string& txData);
    void BroadcastBlock(const std::string& blockData);
};
