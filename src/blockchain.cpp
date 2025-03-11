void Blockchain::SaveToDisk() {
    Storage::SaveBlockchain(*this);
}

void Blockchain::LoadFromDisk() {
    Storage::LoadBlockchain(*this);
}
