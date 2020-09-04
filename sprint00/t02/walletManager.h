#include <iostream>

struct Wallet {
    int septims;
};

Wallet* createWallet(int septims);
void destroyWallet(Wallet* wallet);
Wallet* createWallets(int amount);
void destroyWallets(Wallet* wallets);
