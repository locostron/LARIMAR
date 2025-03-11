CTransaction::CTransaction(std::string sender, std::string receiver, double amount)
    : sender(sender), receiver(receiver), amount(amount) {}

void CTransaction::SignTransaction(const std::string& privateKey) {
    std::string data = sender + receiver + std::to_string(amount);
    signature = Crypto::SignTransaction(privateKey, data);
}

bool CTransaction::IsValid() const {
    if (sender.empty()) return true; // Transacciones de recompensa no requieren firma
    std::string data = sender + receiver + std::to_string(amount);
    return Crypto::VerifySignature(sender, data, signature);
}
