//  Created by Paulina Podgaiska.
//

#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <chrono>
#include <random>
#include <unordered_map>
#include <cmath>
#include <numeric>
#include <algorithm>
using namespace std;

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

vector<uint32_t> hashblokai(const vector<string> &blocks) {
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

    vector<uint32_t> hashResult = hashblokai(blocks);
    cout << "Hash: ";
    printHash(hashResult);
}

void failogeneratorius(string failopav, int simboliukiek) {
    ofstream F(failopav);
    if (!F.is_open()) {
        cout << "Nepavyko sukurti failo: " << failopav << endl;
        return;
    }

    srand(time(0));
    for (int i = 0; i < simboliukiek; i++) {
        char randsimb = rand() % 93 + 33;
        F << randsimb;
    }

    F.close();
    cout << "Sugeneruotas failas: " << failopav << endl;
}

string failoskaitytuvas(string failopav) {
    ifstream failas(failopav);
    if (!failas.is_open()) {
        cout << "Nepavyko atidaryti failo: " << failopav << endl;
        return "";
    }

    string eil;
    stringstream ss;
    while (getline(failas, eil)) {
        ss << eil;
    }
    failas.close();
    return ss.str();
}

void failai1simbdiff(string failas1, string failas2, int simboliukiek) {
    ofstream F1(failas1);
    ofstream F2(failas2);
    if (!F1.is_open() || !F2.is_open()) {
        cout << "Ivyko klaida." << endl;
        return;
    }

    srand(time(0));

    for (int i = 0; i < simboliukiek; i++) {
        char randsimb = rand() % 93 + 33;
        F1 << randsimb;
        F2 << randsimb;
    }
    int r = rand() % 92 + 33;
    char randsimb = r;
    F1 << randsimb;
    F2 << "~";
    F1.close();
    F2.close();
    cout << "Failai su vienu simbolio skirtumu: " << failas1 << ", " << failas2 << endl;
}

vector<string> skaitytieil(const string& fileName) {
    ifstream file(fileName);
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}

void konstitucijatestas(const vector<string>& lines) {
    float lineCount = 1;
    int totalLines = lines.size();
    float k=0;

    while (lineCount <= totalLines) {
        string inputData = "";
        for (int i = 0; i < lineCount; ++i) {
            inputData += lines[i];
        }
        auto start = chrono::high_resolution_clock::now();

        char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        skaiciavimas(inputData, H,b,N,L);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << endl;
        cout << "Eiluciu skaicius: " << lineCount << ", Hash laikas: " << elapsed.count() << " s." << endl;
        lineCount = lineCount*2;
        if(lineCount>totalLines && k!=1){
            lineCount = totalLines;
            k++;
        }
    }

}

string generuojamrandstring(int length) {
    const string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string result;
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, characters.size() - 1);

    for (int i = 0; i < length; ++i) {
        result += characters[distribution(generator)];
    }

    return result;
}

vector<pair<string, string>> generuojamrandporas() {
    vector<pair<string, string>> pora;
    vector<int> lengths = {10, 100, 500, 1000};
    int numPairs = 25000;
    for (int length : lengths) {
        for (int i = 0; i < numPairs; ++i) {
            string pora1 = generuojamrandstring(length);
            string pora2 = generuojamrandstring(length);
            pora.emplace_back(pora1, pora2);
        }
    }

    return pora;
}

void porosfailiukas(const vector<pair<string, string>>& pora, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Nepavyko irasyti i faila: " << filename << endl;
        return;
    }

    for (const auto& pair : pora) {
        outFile << pair.first << "," << pair.second << endl;
    }

    outFile.close();
    cout << "Poros irasytos i faila " << filename << endl;
}

void hashkolizijos(const vector<pair<string, string>>& pora) {
    unordered_map<string, vector<int>> hashMap;
    int collisionCount = 0;

    for (size_t i = 0; i < pora.size(); ++i) {
        const auto& pair = pora[i];
        string inputData = pair.first + pair.second;
        vector<uint32_t> hashResult = hashblokai({inputData});
        string hashString;
        for (uint32_t part : hashResult) {
            hashString += to_string(part);
        }

        if (hashMap.find(hashString) != hashMap.end()) {
            collisionCount++;
            cout << "Koliziju rasta : " << i << " su hashu: " << hashString << endl;
        } else {
            hashMap[hashString].push_back(i);
        }
    }
    cout << "Is viso koliziju: " << collisionCount << endl;
}

vector<pair<string, string>> generuojamporas1simbdiff(int numPairs, int maxLength) {
    vector<pair<string, string>> pora;

    for (int i = 0; i < numPairs; ++i) {
        string original = generuojamrandstring(maxLength);
        int charIndex = rand() % maxLength;
        char newChar = generuojamrandstring(1)[0];
        string modified = original;
        modified[charIndex] = newChar;

        pora.emplace_back(original, modified);
    }

    return pora;
}

double bitskirtumasproc(uint32_t hash1, uint32_t hash2) {
    uint32_t diff = hash1 ^ hash2;
    int bitDifference = __builtin_popcount(diff);
    return (static_cast<double>(bitDifference) / (sizeof(uint32_t) * 8)) * 100;
}

double hexskirtumasproc(const string& hex1, const string& hex2) {
    int length = min(hex1.size(), hex2.size());
    int diffCount = 0;
    for (int i = 0; i < length; ++i) {
        if (hex1[i] != hex2[i]) {
            diffCount++;
        }
    }
    return (static_cast<double>(diffCount) / length) * 100;
}

void lavinosteastas(const vector<pair<string, string>>& pora) {
    vector<double> bitDifferences;
    vector<double> hexDifferences;
    for (const auto& pair : pora) {
        uint32_t hash1 = static_cast<uint32_t>(std::hash<string>{}(pair.first));
        uint32_t hash2 = static_cast<uint32_t>(std::hash<string>{}(pair.second));
        string hex1 = to_string(hash1);
        string hex2 = to_string(hash2);
        bitDifferences.push_back(bitskirtumasproc(hash1, hash2));
        hexDifferences.push_back(hexskirtumasproc(hex1, hex2));
    }
    double bitMin = *min_element(bitDifferences.begin(), bitDifferences.end());
    double bitMax = *max_element(bitDifferences.begin(), bitDifferences.end());
    double bitAvg = accumulate(bitDifferences.begin(), bitDifferences.end(), 0.0) / bitDifferences.size();

    double hexMin = *min_element(hexDifferences.begin(), hexDifferences.end());
    double hexMax = *max_element(hexDifferences.begin(), hexDifferences.end());
    double hexAvg = accumulate(hexDifferences.begin(), hexDifferences.end(), 0.0) / hexDifferences.size();
    cout << fixed << setprecision(2);
    cout << "Bit skirtingumas - Min: " << bitMin << "%, Max: " << bitMax << "%, Avg: " << bitAvg << "%" << endl;
    cout << "Hex skirtingumas - Min: " << hexMin << "%, Max: " << hexMax << "%, Avg: " << hexAvg << "%" << endl;
}

int main() {
    int variantas;

    cout << "Pasirinkite norima veiksma: " << endl;
    cout << "1. Ivesti ranka." << endl;
    cout << "2. Tikrinti failus, sudarytus tik is vieno simbolio." << endl;
    cout << "3. Tikrinti failus, kuriuose yra > 1000 simboliu." << endl;
    cout << "4. Tikrinti failus su 1000 simboliais, kurie skiriasi tik 1 simboliu." << endl;
    cout << "5. Atlikti testa su konstitucija.txt failu." << endl;
    cout << "6. Generuoti faila su 100 000 atsitiktiniu simboliu poru ir tikrinti ar hash nesutampa." << endl;
    cout << "7. Generuoti 100 000 atsitiktiniu simboliu poru su vienu skirtumu ir atlikti testus." << endl;
    cout << "8. Nuskaityti faila tuscias.txt." << endl;
    cout << "9. Baigti darba." << endl;
    cout << "Jusu pasirinkimas: ";
    cin >> variantas;

    switch (variantas) {
        case 1: {
            string h;
            cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: ";
            cin >> h;
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            skaiciavimas(h, H, b, N, L);
            break;
        }
        case 2: {
            cout << "Nuskaitomi failai su vienu simboliu." << endl;
            string simbolis1 = failoskaitytuvas("simbolis1.txt");
            cout << "Failo simbolis1.txt hashas: " << endl;
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            skaiciavimas(simbolis1, H, b, N, L);
            string simbolis2 = failoskaitytuvas("simbolis2.txt");
            cout << endl << "Failo simbolis2.txt hashas: " << endl;
            skaiciavimas(simbolis2, H, b, N, L);
            break;
        }
        case 3: {
            int pasirinkimas;
            cout << "Ar norite sugeneruoti du naujus failus? Spauskite 1, jei taip. Bet koks kitas skaicius - ne." << endl;
            cin >> pasirinkimas;
            if (pasirinkimas == 1) {
                failogeneratorius("1random1000.txt", 1050);
                failogeneratorius("2random1000.txt", 1050);
            }
            string failas1 = failoskaitytuvas("1random1000.txt");
            string failas2 = failoskaitytuvas("2random1000.txt");
            cout << "Failo 1random1000.txt hashas: " << endl;
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            skaiciavimas(failas1, H, b, N, L);
            cout << endl << "Failo 2random1000.txt hashas: " << endl;
            skaiciavimas(failas2, H, b, N, L);
            break;
        }
        case 4: {
            cout << "Generuojami du failai, kurie skiriasi tik vienu simboliu." << endl;
            failai1simbdiff("1001simboliai1.txt", "1001simboliai2.txt", 1000);
            string failas1 = failoskaitytuvas("1001simboliai1.txt");
            string failas2 = failoskaitytuvas("1001simboliai2.txt");
            cout << "Failo 1001simboliai1.txt hashas: " << endl;
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            skaiciavimas(failas1, H, b, N, L);
            cout << endl << "Failo 1001simboliai2.txt hashas: " << endl;
            skaiciavimas(failas2, H, b, N, L);
            break;
        }
        case 5: {
            vector<string> fileName = skaitytieil("konstitucija.txt");
            konstitucijatestas(fileName);
            break;
        }
        case 6:{
            vector<pair<string, string>> randompora = generuojamrandporas();
            string filename = "randomporos.txt";
            porosfailiukas(randompora, filename);
            hashkolizijos(randompora);
            break;
            }
        case 7: {
            const int numPairs = 100000;
            const int maxLength = 1000;
            vector<pair<string, string>> randompora = generuojamporas1simbdiff(numPairs, maxLength);
            lavinosteastas(randompora);
            break;
        }
        case 8:{
            ofstream tuscias("tuscias.txt");
            tuscias.close();
            string tusciasf = failoskaitytuvas("tuscias.txt");
            cout<<"Hash:"<<endl;
            char H[64], L[64], N[1200], b[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
            skaiciavimas(tusciasf, H, b, N, L);
            break;
        }
        case 9:
            return 0;
        default:
            cout << "Tokio pasirinkimo nera." << endl;
            return 0;
    }

    return 0;
}