//  Created by Roberta Jurpalytė.
//

#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <random>
#include <vector>
#include <unordered_set>
#include <utility>
#include <functional> 
#include <chrono> 
#include <numeric>

using namespace std;

//ivesties pakeitimas
string keiciaIvesti(const string& input, char key, int shift, bool invert, bool useNand) {
    string result = input;

    // Seed a random generator with the input to introduce randomness
    mt19937 rng(hash<string> () (input)); 
    uniform_int_distribution<int> randShift(1, 7); // Random shift tarp 1 and 7

    // XOR su dinamiškai kintančiu raktu pagal įvestį ir padėtį
    for (size_t i = 0; i < result.length(); ++i) {
        result[i] ^= (key + result[i] + i * 7) % 256;
    }

    
    for (size_t i = 0; i < result.length(); ++i) {
        int dynamicShift = (randShift(rng) + result[i] + i) % 8;  // Combine randomness, ASCII value, and position
        result[i] = (result[i] << dynamicShift) | (result[i] >> (8 - dynamicShift));
    }

    // Invert bits based on a combination of randomness and character position
    if (invert) {
        for (size_t i = 0; i < result.length(); ++i) {
            if ((result[i] + rng() % 100) % 2 == 0) {  // Introduce randomness into inversion decision
                result[i] = ~result[i];
            }
        }
    }

    // Apply NAND operation using both key, position, and randomness
    if (useNand) {
        for (size_t i = 0; i < result.length(); ++i) {
            result[i] = ~(result[i] & ((key + result[i] + rng() % 100) % 256));
        }
    }

    // Introduce a final mixing step by XORing adjacent characters
    for (size_t i = 1; i < result.length(); ++i) {
        result[i] ^= result[i - 1];
    }

    // Fold the result onto itself by XORing the first half with the second half
    for (size_t i = 0; i < result.length() / 2; ++i) {
        result[i] ^= result[result.length() - 1 - i];
    }

    return result;
}


string ivestis_i_bitus(string input, int minLength, char padChar) {
    // Paddingas
    while (input.length() < minLength) {
        input += padChar;  // 
    }

    // Convert to binary
    string binaryString = "";
    for (size_t i = 0; i < input.length(); ++i) {
    char c = input[i];
    binaryString += bitset<8>(c).to_string();  // Convert each character to 8-bit binary
}

    return binaryString;
}

char hexas(char hexChar, int step) {
    if (isdigit(hexChar)) {
        int num = hexChar - '0';  // verciam i int
        num = (num + step) % 10;  // pridedam per kiek pakeist ir  mod 10
        return '0' + num;         // atgal i char
    } else if (hexChar >= 'A' && hexChar <= 'F') {
        int num = hexChar - 'A';  // i int range af
        num = (num + step) % 6;   // pridedam per kiek pakeist plius mod 6
        return 'A' + num;         // atgal i char
    } else if (hexChar >= 'a' && hexChar <= 'f') {
        int num = hexChar - 'a';  // int range af
        num = (num + step) % 6;   // pridedam per kiek pakeist plius mod 6
        return 'a' + num;         // atgal i char
    }
    return hexChar;  // grazina nekeista jei ne validus hexas
}


string sesiolika_bitu(string& bits, const string& originalInput) {
    // ziurim kad dvejetainės eilutes ilgis butu 4 kartotinis, jei ne, uzpildom nuliais kol bus
    while (bits.size() % 4 != 0) {
        bits = '0' + bits;
    }

    stringstream hexiukai;

    // ar turi didziuju arba -
    bool didzioji = any_of(originalInput.begin(), originalInput.end(), ::isupper);
    bool zenklas = originalInput.find('-') != string::npos;

    // daugiklis
    int daugiklis = 9;
    if (didzioji) {
        daugiklis = originalInput.length();
    } else if (zenklas) {
        daugiklis = originalInput.length() / 2;
    }

    srand(time(0));
    int pakaitine_reiksme = 1;

    // gabalus dorojam
    for (size_t i = 0; i < bits.size(); i += 4) {
        string gabalas = bits.substr(i, 4);
        int value = stoi(gabalas, nullptr, 2);  // bnr to int

        int kiek_originalus = originalInput[i / 4] % 16;
        pakaitine_reiksme += (kiek_originalus + 1);

        int randomShift = rand() % daugiklis;
        value *= (pakaitine_reiksme + randomShift);  
        value = abs(value % 16);  // ar hex range

        hexiukai << hex << value;  // atvaizduoti
    }

    string hexo_rezas = hexiukai.str();

    // per kiek keliam
    int step = 5;
    for (size_t i = 0; i < hexo_rezas.length(); ++i) {
        hexo_rezas[i] = hexas(hexo_rezas[i], step);  // pritaikom kiekvienam simboliui
    }

    // kad butu 64 ilgio
    if (hexo_rezas.length() > 64) {
        hexo_rezas = hexo_rezas.substr(0, 64);  // trumpinam
        while (hexo_rezas.length() < 64) {
            hexo_rezas += '0';  // dedam nuliuku
        }
    }

    return hexo_rezas;
}

int priebalses(const string& input) {
    int sum = 0;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        c = tolower(c);  // Normalize case
        if (isalpha(c) && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            sum += c - 'a' + 1;
        }
    }
    return sum;
}


string daugyba (string bits, int wordSum, bool invert) {
    for (size_t i = 0; i < bits.size(); ++i) {
        if (bits[i] == '1') {
            bits[i] = (invert ? !(wordSum % 2) : (wordSum % 2)) ? '1' : '0';
        } else {
            bits[i] = (invert ? !(wordSum % 2) : (wordSum % 2)) ? '0' : '1';
        }
        wordSum /= 2;
        if (wordSum == 0) break;
    }
    return bits;
}

void apdoroja(const string& input, ofstream& outputFile) {
    string pakeista_ivestis = input + to_string(input.length());
    pakeista_ivestis = keiciaIvesti(pakeista_ivestis, 'j', 2, true, false);
    string binaryResult = ivestis_i_bitus(pakeista_ivestis, 32, 'i');
    int wordSum = priebalses(pakeista_ivestis);
    string pakeisti_bitai = daugyba(binaryResult, wordSum, true);
    string hashResult = sesiolika_bitu(pakeisti_bitai, pakeista_ivestis);

    outputFile << "hash'as: " << hashResult << endl;
}


///////////////////////////////////////////////////////////////////////////////////////////
// failas su viena raide
void failiukas(const string& filename, char c, size_t size) {
    ofstream file(filename);
    if (file.is_open()) {
        for (size_t i = 0; i < size; ++i) {
            file << c << '\n';
        }
        file.close();
    }
}

// random kratinys
void kratinukas(const string& filename, size_t size) {
    ofstream file(filename);
    if (file.is_open()) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(32, 126);  // ascii

        for (size_t i = 0; i < size; ++i) {
            file << static_cast<char>(dis(gen));  
        }
        file.close();
    }
}

// vienodi bet viena raide skiriasi
void nevienodi(const string& filename1, const string& filename2, size_t size) {
    ofstream file1(filename1);
    ofstream file2(filename2);

    if (file1.is_open() && file2.is_open()) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(32, 126);  

        string content(size, ' ');
        for (size_t i = 0; i < size; ++i) {
            content[i] = static_cast<char>(dis(gen));  
        }

        // cia kad vienam faile pakeistu raide
        file1 << content;
        content[size / 2] = static_cast<char>(dis(gen));  // vidurine pakeicia
        file2 << content;

        file1.close();
        file2.close();
    }
}


void tuscias(const string& filename) {
    ofstream file(filename);
    file.close();
}
//////////////////////////////////////////////////////////////////////////
void testukas1(const string& filename, int lineCount) {
    ifstream inputFile(filename);
    ofstream outputFile("hashas_performance.txt");
    string line;

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "nepavyko atidaryti failo!" << endl;
        return;
    }

    chrono::time_point<chrono::high_resolution_clock> start = chrono::high_resolution_clock::now();

    int uzhashintoseil = 0;
    while (getline(inputFile, line) && uzhashintoseil < lineCount) {
        apdoroja(line, outputFile);
        uzhashintoseil++;
    }

   chrono::time_point<chrono::high_resolution_clock> end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "uzhashintos " << lineCount << " eilutes per " << elapsed.count() << " sekundziu." << endl;

    inputFile.close();
    outputFile.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////


    string poros_random(int length) {
    string simboliai = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string randomas;
    for (int i = 0; i < length; i++) {
        randomas += simboliai[rand() % simboliai.size()];
    }
    return randomas;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void kolizijos(const vector<pair<string, string> >& stringPairs) {
    unordered_set<size_t> hashSet;
    int collisionCount = 0;
    for (size_t i = 0; i < stringPairs.size(); ++i) {
        const pair<string, string>& pair = stringPairs[i];
        size_t hash1 = hash<string>()(pair.first);
        size_t hash2 = hash<string>()(pair.second);
        if (hash1 == hash2) {
            collisionCount++;
            //cout << "kolizija tarp: " << pair.first << " ir " << pair.second << endl;
        }
    }
    if (collisionCount > 0) {
        cout << "is viso koliziju: " << collisionCount << endl;
    } else {
        cout << "koliziju nerasta!" << endl;
    }
}

vector<pair<string, string> > loadStringPairsFromFile(const string& filename) {
    vector<pair<string, string> > stringPairs;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "nepavyko atidaryti failo " << filename << endl;
        return stringPairs;
    }
    string str1, str2;
    while (file >> str1 >> str2) {
        stringPairs.push_back(make_pair(str1, str2));
    }
    file.close();
    return stringPairs;
}
/////////////////////////////////////////////////////////////////////////

// Function to generate random strings with only printable ASCII characters
string generate_random_string(size_t length, const string& charSet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> distribution(0, charSet.size() - 1);

    string randomString;
    for (size_t i = 0; i < length; ++i) {
        randomString += charSet[distribution(generator)];
    }
    return randomString;
}


// Function to compute bit-level difference between two binary strings
double compute_bit_difference(const string &binary1, const string &binary2) {
    int differences = 0;
    for (size_t i = 0; i < binary1.size(); ++i) {
        if (binary1[i] != binary2[i]) {
            differences++;
        }
    }
    return (differences / (double)binary1.size()) * 100;
}

// Function to compute hex-level difference between two hexadecimal strings
double compute_hex_difference(const string &hex1, const string &hex2) {
    int differences = 0;
    for (size_t i = 0; i < hex1.size(); ++i) {
        if (hex1[i] != hex2[i]) {
            differences++;
        }
    }
    return (differences / (double)hex1.size()) * 100;
}

//////////////////is int main padarytos funkcijos//////////////////////////////

void konstitucijaR(const string& filename) {
    int lineCounts[] = {1, 2, 4, 8, 16, 32, 64, 128, 256}; 
    int size = sizeof(lineCounts) / sizeof(lineCounts[0]); 

    for (int i = 0; i < size; ++i) {
        int count = lineCounts[i]; 
        testukas1(filename, count); 
    }
}

void generuotiPorasR(const string& outputFilename) {
    srand(time(0)); 

    const int grupesDydis = 25000;  // Number of pairs for each length

    vector<pair<string, string>> stringPoros;

    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cerr << "klaida. nepavyko atidaryti failo." << endl;
        return;
    }

    // 10 ilgio
    for (int i = 0; i < grupesDydis; i++) {
        string str1 = poros_random(10);
        string str2 = poros_random(10);
        stringPoros.push_back(make_pair(str1, str2));
    }

    // 100 ilgio
    for (int i = 0; i < grupesDydis; i++) {
        string str1 = poros_random(100);
        string str2 = poros_random(100);
        stringPoros.push_back(make_pair(str1, str2));
    }

    // 500 ilgio
    for (int i = 0; i < grupesDydis; i++) {
        string str1 = poros_random(500);
        string str2 = poros_random(500);
        stringPoros.push_back(make_pair(str1, str2));
    }

    // 1000 ilgio
    for (int i = 0; i < grupesDydis; i++) {
        string str1 = poros_random(1000);
        string str2 = poros_random(1000);
        stringPoros.push_back(make_pair(str1, str2));
    }

    // Write the pairs to the output file
    for (const auto& pora : stringPoros) {
        outputFile << pora.first << ", " << pora.second << endl;
    }

    outputFile.close();
    cout << "sekmingai irasyta faile " << outputFilename << endl;
}

void apdorotiPorasIrTikrinimasR(const string& inputFilename, const string& outputFilename) {
    vector<pair<string, string>> stringPairs = loadStringPairsFromFile(inputFilename);

    if (stringPairs.empty()) {
        cerr << "Nepavyko nuskaityti failo." << endl;
        return;
    }

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Nepavyko atidaryti failo isvesties saugojimui." << endl;
        return;
    }

    // Process each pair and save their hash values
    for (const auto& pora : stringPairs) {
        apdoroja(pora.first, outputFile);
        apdoroja(pora.second, outputFile);
    }

    outputFile.close();

    // Check for collisions
    kolizijos(stringPairs);
}

void lavinosEfektasR(const string& pairFilename, const string& resultFilename, int num_pairs = 100000, int max_length = 500) {
    vector<double> bit_differences, hex_differences;

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<> length_dist(1, max_length);

    // Create files to save pairs and hash results
    ofstream pair_file(pairFilename);
    if (!pair_file.is_open()) {
        cerr << "nepavyko atidaryti failo!" << endl;
        return;
    }

    ofstream hash_file(resultFilename);
    if (!hash_file.is_open()) {
        cerr << "nepavyko atidaryti failo!" << endl;
        return;
    }

    // Generate string pairs, modify, hash, and calculate differences
    for (int i = 0; i < num_pairs; ++i) {
        int length = length_dist(generator);
        string str1 = generate_random_string(length);

        string str2 = str1;
        uniform_int_distribution<> char_pos_dist(0, length - 1);
        int pos = char_pos_dist(generator);

        // Modify str2 to differ by one character
        char original_char = str2[pos];
        char new_char;
        do {
            new_char = generate_random_string(1)[0];
        } while (new_char == original_char);
        str2[pos] = new_char;

        // Write the pair to file
        pair_file << str1 << " " << str2 << endl;

        // Hash both strings
        string modified_str1 = keiciaIvesti(str1, 'k', 2, true, false);
        string modified_str2 = keiciaIvesti(str2, 'k', 2, true, false);

        string binary_hash1 = ivestis_i_bitus(modified_str1, 32, 'i');
        string binary_hash2 = ivestis_i_bitus(modified_str2, 32, 'i');

        string hex_hash1 = sesiolika_bitu(binary_hash1, modified_str1);
        string hex_hash2 = sesiolika_bitu(binary_hash2, modified_str2);

        // Calculate the bit and hex differences
        double bit_diff = compute_bit_difference(binary_hash1, binary_hash2);
        double hex_diff = compute_hex_difference(hex_hash1, hex_hash2);

        bit_differences.push_back(bit_diff);
        hex_differences.push_back(hex_diff);

        // Write the results to file
        hash_file << "String pora: " << str1 << " " << str2 << endl;
        hash_file << "pirmo hashas hex: " << hex_hash1 << endl;
        hash_file << "antro hashas hex: " << hex_hash2 << endl;
        hash_file << "bitu skirtumas: " << bit_diff << "%" << endl;
        hash_file << "hexo skirtumas: " << hex_diff << "%" << endl;
        hash_file << "-------------------------------------------" << endl;
    }

    pair_file.close();
    hash_file.close();

    // Calculate min, max, and average differences
    double bit_min = *min_element(bit_differences.begin(), bit_differences.end());
    double bit_max = *max_element(bit_differences.begin(), bit_differences.end());
    double bit_avg = accumulate(bit_differences.begin(), bit_differences.end(), 0.0) / bit_differences.size();

    double hex_min = *min_element(hex_differences.begin(), hex_differences.end());
    double hex_max = *max_element(hex_differences.begin(), hex_differences.end());
    double hex_avg = accumulate(hex_differences.begin(), hex_differences.end(), 0.0) / hex_differences.size();

    // Output the results to the terminal
    cout << "bitu skirtumas: " << endl;
    cout << "min: " << bit_min << "%" << endl;
    cout << "max: " << bit_max << "%" << endl;
    cout << "vidutinis: " << bit_avg << "%" << endl;

    cout << "hexu skirtumas: " << endl;
    cout << "min: " << hex_min << "%" << endl;
    cout << "max: " << hex_max << "%" << endl;
    cout << "vidutinis: " << hex_avg << "%" << endl;
}