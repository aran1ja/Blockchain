#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>   
#include <unordered_map>     
#include <unordered_set>
#include <random>   
#include <array>
#include <cctype>  // isupper()

//#include "rugiles_hash.h"      

using namespace std;

//////////////////////MANO KODAS////////////////////////////////////////

string hexPadarymas(bitset<256>& bitai) {
    stringstream ss;

    for (int i = 0; i < 256; i += 4) // Paemame po 4 bitus is 256 tam, kad konvertuoti 4 bitus i 1 hex
    {
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
    for (int i = 0; i < binarinis_ilgis / 2; i++) 
    {
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
            bitai[i] = 1; // Jeigu taip - rasome 1
        } else {
            bitai[i] = 0; // Jeigu ne - rasome 0
        }
    }
    
    pakeitimasPo16bitus(bitai,  0, 256);
    pakeitimasPo16bitus(bitai, 16, 240);
    pakeitimasPo16bitus(bitai, 32, 224);
    pakeitimasPo16bitus(bitai, 48, 208);
    pakeitimasPo16bitus(bitai, 64, 192);
    pakeitimasPo16bitus(bitai, 80, 176);
    pakeitimasPo16bitus(bitai, 96, 160);
    pakeitimasPo16bitus(bitai, 112, 144);

    for (int i = 0; i < binarinis_ilgis / 2; i++) {
        if (bitai[i] == bitai[binarinis_ilgis - i - 1]) {
            bitai[i] = 1; // Jeigu taip - rasome 1
        } else {
            bitai[i] = 0; // Jeigu ne - rasome 0
        }
    }
    
    //cout << "Binarinis kodas: " << bitai << endl;
}

string hashFunkcija(string simboliu_seka) {
        int ascii_suma = 0; // Naudojama ascii reiksmiu sumai
        int daugiklis = 1; 
    
        int ilgis = 8 * simboliu_seka.size(); // Simboliu sekos ilgis bitais

        // Zodis isverciamas i ASCII
        for (char simbolis : simboliu_seka) {
            ascii_suma += (int)simbolis * daugiklis;
            daugiklis++;
        }

        // Ascii_suma isverciama i binary
        bitset<256> binarinis_kodas((int)ascii_suma);
        bitset<256> binarinis_kodas_kopija = binarinis_kodas; // Kuriama kopija
        for (int i = 0; i < 3; i++)
        {
            bitaiKeiciasiVietomis(binarinis_kodas_kopija);
        }
        
        string hexKodas = hexPadarymas(binarinis_kodas_kopija);
        //cout << "Hash kodo atvaizdavimas hex pavidalu: " << hex << hexKodas << endl;
        return hexKodas;
}

//////////////////////RUGILES////////////////////////////////////////
class nuu{

    public:
        nuu();
        nuu(int nr);
        inline ~nuu() {}

        string skaitymas (const string &ivestis);
        double laiko_matavimas( string& ivestis);
        void tikrinti_hash_kolizijas();
        void lavinos_testavimas();


    private:
        int nr;
        string ivestis;
        string uzhashuotas;
        int ilgis;
        string hashRugile (string &ivestis );
        string konvertavimas(const array<unsigned long long, 4>& hashRugile);
        
};
nuu::nuu(){
}

string nuu::hashRugile(string &ivestis){

    unsigned long long randomas = 9999854665226455ULL;
    unsigned long long randomas2 = 98880025054544054ULL;

    array<unsigned long long, 4> hashRugile = {0, 0, 0, 0};
    int j = 0;
    char temp = 'n';


    for (char simbolis : ivestis) { 

        for (int i = 0; i < 4; ++i) {
            
            hashRugile[i] ^= (randomas + simbolis );
            hashRugile[i] *= (randomas2 ^ hashRugile[i] * hashRugile[i] );
        }
        
        
        if (j % 3 == 0) {
            swap(hashRugile[0], hashRugile[3]);
            hashRugile[1] += hashRugile[2] * temp * simbolis;
        }
        else if (j % 3 == 1) {
            hashRugile[1] += hashRugile[2] * simbolis;
            swap(hashRugile[1], hashRugile[2]);
        }
        temp = simbolis;

        ++j;
    }
    return uzhashuotas = konvertavimas(hashRugile);
       
    
}
string nuu::konvertavimas(const array<unsigned long long, 4>& hashRugile){

    vector <unsigned long long> druska = {192837645ULL, 1098765432ULL, 123456789ULL, 987654321ULL};
    vector<char> druska1 = {'-','$','#','@'};
    vector<char> druska2 = {'&','/','*',','};
    stringstream ss;
    int i = 0;

    for (const auto& n : hashRugile) {
        
        unsigned long long druskintas = n * druska[3 - i] + druska1[3 - i] * druska2[3 - i];
        // 64 bits -> 16 hex 
        ss << setw(16) << setfill('5') << hex << druskintas; 
        ++i;
    }
    return ss.str();

}

//////////////////////KAMILES////////////////////////////////////////

string hashFunkcijaK(string input) 
{
    const unsigned long long sk1 = 0x100000001b3; //1099511628211 pirminis
    const unsigned long long sk2 = 0xab5351bc652b4e61;
    //12345300873145699937 pirminis sk
    vector<unsigned long long> outputHash(4, 0);
    for(int i = 0; i < input.length(); i++)
    {
        char dabSimb = input[i];
        unsigned long long reiksme = static_cast<unsigned long long>(dabSimb);
        for(int j = 0; j < 4; j++)
        {
//            cout << (std::bitset<64>) outputHash[j] << endl;
            outputHash[j] ^= reiksme;
//           cout << (std::bitset<64>) outputHash[j] << endl;
            outputHash[j]*= sk1;
           // cout << (std::bitset<64>) outputHash[j] << endl;
            outputHash[j] = leftRotate(outputHash[j], 13);
           // cout << (std::bitset<64>) outputHash[j] << endl;
            outputHash[j]^=rightRotate(outputHash[(j+1)%4], 17);
//            cout << (std::bitset<64>) outputHash[j] << endl;
//            cout << endl;
            reiksme *= sk2;
        }
    }
    std::stringstream ss;
    for (const auto& val : outputHash) {
            ss << std::hex << std::setfill('0') << std::setw(16) << val;
        }
    
        return ss.str();
    
}

unsigned long long int rightRotate (unsigned long long int reiksme, unsigned long long int d) {
    return (reiksme >> d) | (reiksme << (64 - d));
}
unsigned long long int leftRotate (unsigned long long int reiksme, unsigned long long int d) {
    return (reiksme << d) | (reiksme >> (64 - d));
}

//////////////////////PAULINOS////////////////////////////////////////

uint32_t rightRotate(uint32_t n, unsigned int d) {
    return (n >> d) | (n << (32 - d));
}

string padMessage(string input) {
    uint64_t messageLength = input.size() * 8;
    input += (char)0x80;
    while ((input.size() * 8) % 512 != 448) {
        input += (char)0x00;
    }

    for (int i = 7; i >= 0; --i) {
        input += (char)((messageLength >> (i * 8)) & 0xFF);
    }

    return input;
}

vector<uint32_t> hashPaulina(const vector<string> &blocks) {
    uint32_t H[8] = {
        0x6A09E667, 0xBB67AE85, 0x3C6EF372, 0xA54FF53A,
        0x510E527F, 0x9B05688C, 0x1F83D9AB, 0x5BE0CD19
    };

    const uint32_t K[64] = {
        0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5, 0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
        0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3, 0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
        0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC, 0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
        0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7, 0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
        0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13, 0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
        0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3, 0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
        0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5, 0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
        0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208, 0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
    };

    for (const string &block : blocks) {
        uint32_t W[64];
        for (int i = 0; i < 16; ++i) {
            W[i] = 0;
            for (int j = 0; j < 4; ++j) {
                W[i] = (W[i] << 8) | (unsigned char)block[i * 4 + j];
            }
        }
        for (int i = 16; i < 64; ++i) {
            uint32_t s0 = rightRotate(W[i - 15], 7) ^ rightRotate(W[i - 15], 18) ^ (W[i - 15] >> 3);
            uint32_t s1 = rightRotate(W[i - 2], 17) ^ rightRotate(W[i - 2], 19) ^ (W[i - 2] >> 10);
            W[i] = W[i - 16] + s0 + W[i - 7] + s1;
        }

        uint32_t a = H[0], b = H[1], c = H[2], d = H[3];
        uint32_t e = H[4], f = H[5], g = H[6], h = H[7];

        for (int i = 0; i < 64; ++i) {
            uint32_t S1 = rightRotate(e, 6) ^ rightRotate(e, 11) ^ rightRotate(e, 25);
            uint32_t ch = (e & f) ^ (~e & g);
            uint32_t temp1 = h + S1 + ch + K[i] + W[i];
            uint32_t S0 = rightRotate(a, 2) ^ rightRotate(a, 13) ^ rightRotate(a, 22);
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint32_t temp2 = S0 + maj;

            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        H[0] += a;
        H[1] += b;
        H[2] += c;
        H[3] += d;
        H[4] += e;
        H[5] += f;
        H[6] += g;
        H[7] += h;
    }

    return vector<uint32_t>(H, H + 8);
}

void printHash(const vector<uint32_t>& hash) {
    for (uint32_t part : hash) {
        cout << hex << setw(8) << setfill('0') << part;
    }
    cout << endl;
}

void skaiciavimas(string h, char H[], char b[], char N[], char L[]) {
    string paddedInput = padMessage(h);

    vector<string> blocks;
    for (size_t i = 0; i < paddedInput.size(); i += 64) {
        blocks.push_back(paddedInput.substr(i, 64));
    }

    vector<uint32_t> hashResult = hashPaulina(blocks);
    cout << "Hash: ";
    printHash(hashResult);
}