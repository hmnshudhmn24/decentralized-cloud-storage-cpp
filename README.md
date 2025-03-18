# Decentralized Cloud Storage

A C++ implementation of a decentralized cloud storage system using blockchain principles to securely store files.

## Features
- Implements a simple blockchain structure to store file data securely.
- Uses SHA-256 hashing for integrity verification.
- Provides a decentralized storage mechanism.

## Requirements
- g++ compiler
- OpenSSL library (for SHA-256 hashing)

## Installation & Usage

### 1. Compile the Program
```sh
g++ decentralized_cloud_storage.cpp -o storage -lssl -lcrypto
```

### 2. Run the Program
```sh
./storage
```

## How It Works
- Users can upload files, which are stored as hashed blocks in a blockchain.
- Each block contains the file data, timestamp, and a unique hash for integrity.
- The blockchain maintains the sequence of stored files, preventing unauthorized modifications.

## Future Enhancements
- Implement a peer-to-peer network for true decentralization.
- Add encryption for file security.
- Introduce access control and authentication mechanisms.
