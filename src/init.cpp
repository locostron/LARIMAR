#include "init.h"
#include "chainparams.h"

bool AppInit() {
    // Inicia la cadena de bloques con los parámetros correctos
    SelectParams(CBaseChainParams::MAIN);
    // Otros ajustes para iniciar la red
    return true;
}
