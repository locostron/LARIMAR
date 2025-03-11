#include "blockchain.h"
#include "explorer.h"

int main() {
    Blockchain larimar;
    larimar.LoadFromDisk();

    std::thread miningThread([&]() {
        larimar.StartMining();
    });

    std::thread explorerThread([&]() {
        Explorer::StartServer(larimar);
    });

    miningThread.join();
    explorerThread.join();

    return 0;
}
