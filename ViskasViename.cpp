#include "bendras_hash.h"

int main() {
    string ivestis;
    cout << "Iveskite simboliu seka: ";
    getline(cin, ivestis);
    string hexas = bendrasHash(ivestis);
    cout << "Simboliu sekos hash: " << hexas << endl;
    return 0;
}