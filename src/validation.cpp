#include "validation.h"
#include <iostream>

bool TransactionValidator::IsValid(const CTransaction& tx) {
    if (tx.sender.empty() || tx.receiver.empty()) {
        std::cerr << "Error: Transacción inválida, remitente o receptor vacío." << std::endl;
        return false;
    }

    if (tx.amount <= 0) {
        std::cerr << "Error: La cantidad debe ser mayor a 0." << std::endl;
        return false;
    }

    return true;
}
