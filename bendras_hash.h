#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <string>
#include <array>
#include <vector>

using namespace std;

class nuu {
public:
    string hashRugile(string &ivestis);
private:
    string konvertavimas(const array<unsigned long long, 4>& hashRugile);
};

string hexPadarymas(bitset<256>& bitai) {
    stringstream ss;
    for (int i = 0; i < 256; i += 4) {
        int reiksme = 0;
        reiksme += bitai[i] * 8;
        reiksme += bitai[i + 1] * 4;
        reiksme += bitai[i + 2] * 2;
        reiksme += bitai[i + 3] * 1;
        ss << hex << reiksme;
    }
    return ss.str();
}

void pakeitimasPo16bitus(bitset<256>& bitai, int reiksme_1, int reiksme_2) {
    for (int i = 0; i < 16; i++) {
        bool laikinas = bitai[reiksme_1 + i];
        bitai[reiksme_1 + i] = bitai[reiksme_2 + i];
        bitai[reiksme_2 + i] = laikinas;
    }
}

void bitaiKeiciasiVietomis(bitset<256>& bitai) {
    int binarinis_ilgis = bitai.size();
    for (int i = 0; i < binarinis_ilgis / 2; i++) {
        int laikinas = bitai[i];
        bitai[i] = bitai[binarinis_ilgis - i - 1];
        bitai[binarinis_ilgis - i - 1] = laikinas;
    }

    for (int i = 0; i < binarinis_ilgis; i++) {
        if (bitai[i] == 1) {
            bitai[(i + 15) % 256].flip();
        }
    }

    for (int i = 0; i < binarinis_ilgis / 2; i++) {
        if (bitai[i] == bitai[binarinis_ilgis / 2 + i]) {
            bitai[i] = 1;
        } else {
            bitai[i] = 0;
        }
    }

    pakeitimasPo16bitus(bitai, 0, 256);
    pakeitimasPo16bitus(bitai, 16, 240);
    pakeitimasPo16bitus(bitai, 32, 224);
    pakeitimasPo16bitus(bitai, 48, 208);
    pakeitimasPo16bitus(bitai, 64, 192);
    pakeitimasPo16bitus(bitai, 80, 176);
    pakeitimasPo16bitus(bitai, 96, 160);
    pakeitimasPo16bitus(bitai, 112, 144);

    for (int i = 0; i < binarinis_ilgis / 2; i++) {
        if (bitai[i] == bitai[binarinis_ilgis - i - 1]) {
            bitai[i] = 1;
        } else {
            bitai[i] = 0;
        }
    }
}

string hashFunkcija(string simboliu_seka) {
    int ascii_suma = 0;
    int daugiklis = 1;
    int ilgis = 8 * simboliu_seka.size();

    for (char simbolis : simboliu_seka) {
        ascii_suma += (int)simbolis * daugiklis;
        daugiklis++;
    }

    bitset<256> binarinis_kodas((int)ascii_suma);
    bitset<256> binarinis_kodas_kopija = binarinis_kodas;
    for (int i = 0; i < 3; i++) {
        bitaiKeiciasiVietomis(binarinis_kodas_kopija);
    }

    string hexKodas = hexPadarymas(binarinis_kodas_kopija);
    
    if (hexKodas.length() < 64) {
        hexKodas.insert(0, 64 - hexKodas.length(), '0'); 
    } else {
        hexKodas = hexKodas.substr(0, 64); 
    }
    return hexKodas;
}

string nuu::hashRugile(string &ivestis) {
    unsigned long long randomas = 9999854665226455ULL;
    unsigned long long randomas2 = 98880025054544054ULL;

    array<unsigned long long, 4> hashRugile = {0, 0, 0, 0};
    int j = 0;
    char temp = 'n';

    for (char simbolis : ivestis) {
        for (int i = 0; i < 4; ++i) {
            hashRugile[i] ^= (randomas + simbolis);
            hashRugile[i] *= (randomas2 ^ hashRugile[i] * hashRugile[i]);
        }

        if (j % 3 == 0) {
            swap(hashRugile[0], hashRugile[3]);
            hashRugile[1] += hashRugile[2] * temp * simbolis;
        } else if (j % 3 == 1) {
            hashRugile[1] += hashRugile[2] * simbolis;
            swap(hashRugile[1], hashRugile[2]);
        }
        temp = simbolis;
        ++j;
    }
    return konvertavimas(hashRugile);
}

string nuu::konvertavimas(const array<unsigned long long, 4>& hashRugile) {
    vector<unsigned long long> druska = {192837645ULL, 1098765432ULL, 123456789ULL, 987654321ULL};
    vector<char> druska1 = {'-', '$', '#', '@'};
    vector<char> druska2 = {'&', '/', '*', ','};
    stringstream ss;
    int i = 0;

    for (const auto& n : hashRugile) {
        unsigned long long druskintas = n * druska[3 - i] + druska1[3 - i] * druska2[3 - i];
        ss << setw(16) << setfill('5') << hex << druskintas;
        ++i;
    }
    return ss.str();
}

unsigned long long int rightRotate(unsigned long long int reiksme, unsigned long long int d) {
    return (reiksme >> d) | (reiksme << (64 - d));
}

unsigned long long int leftRotate(unsigned long long int reiksme, unsigned long long int d) {
    return (reiksme << d) | (reiksme >> (64 - d));
}

string hashFunkcijaK(string input) {
    const unsigned long long sk1 = 0x100000001b3;
    const unsigned long long sk2 = 0xab5351bc652b4e61;
    vector<unsigned long long> outputHash(4, 0);
    for (int i = 0; i < input.length(); i++) {
        char dabSimb = input[i];
        unsigned long long reiksme = static_cast<unsigned long long>(dabSimb);
        for (int j = 0; j < 4; j++) {
            outputHash[j] ^= reiksme;
            outputHash[j] *= sk1;
            outputHash[j] = leftRotate(outputHash[j], 13);
            outputHash[j] ^= rightRotate(outputHash[(j + 1) % 4], 17);
            reiksme *= sk2;
        }
    }
    stringstream ss;
    for (const auto& val : outputHash) {
        ss << setw(16) << setfill('0') << hex << val; 
    }
    return ss.str();
}

uint32_t rightRotatee(uint32_t n, unsigned int d) {
    return (n >> d) | (n << (32 - d));
}

string padMessage(string input) {
    size_t originalByteLen = input.size();
    size_t originalBitLen = originalByteLen * 8;

    input += static_cast<char>(0x80);

    while ((input.size() * 8) % 512 != 448) {
        input += static_cast<char>(0x00);
    }

    for (int i = 0; i < 8; ++i) {
        input += static_cast<char>((originalBitLen >> (56 - i * 8)) & 0xff);
    }

    return input;
}

array<uint32_t, 4> computeHash(string input) {
    const uint32_t sk1 = 0x6a09e667;
    const uint32_t sk2 = 0xbb67ae85;
    const uint32_t sk3 = 0x3c6ef372;
    const uint32_t sk4 = 0xa54ff53a;
    const uint32_t sk5 = 0x510e527f;
    const uint32_t sk6 = 0x9b05688c;
    const uint32_t sk7 = 0x1f83d9ab;
    const uint32_t sk8 = 0x5be0cd19;

    input = padMessage(input);
    array<uint32_t, 4> hash = {sk1, sk2, sk3, sk4};

    for (size_t i = 0; i < input.size(); i += 64) {
        array<uint32_t, 16> w = {};
        for (size_t j = 0; j < 16; ++j) {
            w[j] = (static_cast<uint32_t>(input[i + j * 4]) << 24) |
                   (static_cast<uint32_t>(input[i + j * 4 + 1]) << 16) |
                   (static_cast<uint32_t>(input[i + j * 4 + 2]) << 8) |
                   (static_cast<uint32_t>(input[i + j * 4 + 3]));
        }

        uint32_t a = hash[0];
        uint32_t b = hash[1];
        uint32_t c = hash[2];
        uint32_t d = hash[3];

        for (size_t j = 0; j < 64; ++j) {
            uint32_t f = (j < 16) ? (b & c) | (~b & d) : (b ^ c ^ d);
            uint32_t k = (j < 16) ? sk5 + j : sk6 + j;
            uint32_t temp = rightRotatee(a, 5) + f + d + k + w[j % 16];
            d = c;
            c = b;
            b += temp;
            a = temp + f + b;
        }

        hash[0] += a;
        hash[1] += b;
        hash[2] += c;
        hash[3] += d;
    }

    return hash;
}

string hashPaulina(string input) {
    array<uint32_t, 4> hash = computeHash(input);
    stringstream ss;
    for (const auto& val : hash) {
        ss << hex << setfill('0') << setw(8) << val; 
    }
    
    string hashString = ss.str();
    if (hashString.length() < 64) {
        hashString.insert(0, 64 - hashString.length(), '0');
    } else {
        hashString = hashString.substr(0, 64); 
    }
    return hashString;
}

string bendrasHash(string simboliu_seka) {
    string hash1 = hashFunkcija(simboliu_seka);    
    string hash2 = nuu().hashRugile(simboliu_seka);  
    string hash3 = hashFunkcijaK(simboliu_seka);    
    string hash4 = hashPaulina(simboliu_seka);      

    string bendras = hash1 + hash2 + hash3 + hash4;
    if (bendras.length() < 64) {
        bendras.insert(0, 64 - bendras.length(), '0'); 
    } else {
        bendras = bendras.substr(0, 64);
    }
    
    return bendras;
}
