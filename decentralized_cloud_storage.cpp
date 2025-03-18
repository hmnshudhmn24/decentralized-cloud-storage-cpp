#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <fstream>
#include <openssl/sha.h>

using namespace std;

// Function to compute SHA-256 hash
string sha256(const string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)data.c_str(), data.size(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << (int)hash[i];
    }
    return ss.str();
}

// Block structure
struct Block {
    int index;
    string previousHash;
    string data;
    time_t timestamp;
    string hash;

    Block(int idx, string prevHash, string fileData) {
        index = idx;
        previousHash = prevHash;
        data = fileData;
        timestamp = time(0);
        hash = sha256(to_string(index) + previousHash + data + to_string(timestamp));
    }
};

// Blockchain class
class Blockchain {
private:
    vector<Block> chain;

public:
    Blockchain() {
        chain.push_back(Block(0, "0", "Genesis Block"));
    }

    void addBlock(string fileData) {
        Block newBlock(chain.size(), chain.back().hash, fileData);
        chain.push_back(newBlock);
        cout << "Block added: " << newBlock.hash << endl;
    }

    void displayChain() {
        for (const auto& block : chain) {
            cout << "Index: " << block.index << "\nPrevious Hash: " << block.previousHash
                 << "\nData: " << block.data << "\nTimestamp: " << block.timestamp
                 << "\nHash: " << block.hash << "\n-----------------------\n";
        }
    }
};

// Decentralized Storage System
class DecentralizedStorage {
private:
    map<string, string> fileStorage; // filename -> block hash
    Blockchain blockchain;

public:
    void uploadFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "File not found!\n";
            return;
        }
        string fileData((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        file.close();

        blockchain.addBlock(fileData);
        cout << "File uploaded successfully: " << filename << endl;
    }

    void showStoredFiles() {
        blockchain.displayChain();
    }
};

int main() {
    DecentralizedStorage storage;
    string filename;
    cout << "Enter file name to upload: ";
    cin >> filename;
    storage.uploadFile(filename);
    storage.showStoredFiles();
    return 0;
}
