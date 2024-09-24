#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void pakeitimasPo16bitus(bitset<256>& bitai, int reiksme_1, int reiksme_2) {
    for (int i = 0; i < 16; i++) {
        bool laikinas = bitai[reiksme_1 + i];
        bitai[reiksme_1 + i] = bitai[reiksme_2 + i]; 
        bitai[reiksme_2 + i] = laikinas;  
    }
}

// Pakeisti, nes veikia ne taip kaip reikia
void bitaiKeiciasiVietomis(bitset<256>& bitai) {
    int binarinis_ilgis = bitai.size(); 
    for (int i = 0; i < binarinis_ilgis / 2; i++) 
    // Dalinu is 2, nes jei turime 10 bitu, tai sukeiciama pagal toki principa: 1-10, 2-9, 3-8, 4-7, 5-6
    {
        int laikinas = bitai[i];
        bitai[i] = bitai[binarinis_ilgis - i - 1]; 
        bitai[binarinis_ilgis - i - 1] = laikinas;
    }
    
    cout << "Bitukas: " << bitai << endl;

    // Bandymas sugeneruoti daugiau 1 ir 0
    for (int i = 0; i < binarinis_ilgis / 2; i++) {
        if (bitai[i] == bitai[binarinis_ilgis / 2 + i]) { // Patikriname ar pirmoji puse kodo lygi su kitaja
            bitai[i] = 1; // Jeigu taip - rasome 1
        } else {
            bitai[i] = 0; // Jeigu ne - rasome 0
        } // Gaudavosi per daug 1
    }
    
    cout << "Bam bam: " << bitai << endl;

    pakeitimasPo16bitus(bitai,  0, 256);
    pakeitimasPo16bitus(bitai, 16, 240);
    pakeitimasPo16bitus(bitai, 32, 224);
    pakeitimasPo16bitus(bitai, 48, 208);
    pakeitimasPo16bitus(bitai, 64, 192);
    pakeitimasPo16bitus(bitai, 80, 176);
    pakeitimasPo16bitus(bitai, 96, 160);
    pakeitimasPo16bitus(bitai, 112, 144);

    cout << "Bit bit: " << bitai << endl;

    // Bandymas sugeneruoti daugiau 1 ir 0
    for (int i = 0; i < binarinis_ilgis / 2; i++) {
        if (bitai[i] == bitai[binarinis_ilgis - i - 1]) { // Patikriname ar pirmoji puse kodo lygi su kitaja
            bitai[i] = 1; // Jeigu taip - rasome 1
        } else {
            bitai[i] = 0; // Jeigu ne - rasome 0
        }
    }
    
    cout << "Iui Iui: " << bitai << endl;
    cout << "-----------------------------------------------------------------" << endl;
}

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

string nuskaitymasIsFailo(string failoPavadinimas) {
    ifstream failas(failoPavadinimas);
    if (!failas.is_open()) { 
        cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return " "; 
    }

    string turinys;
    while (getline(failas, turinys))
    
    failas.close();

    return turinys;
}

void hashFunkcija(string simboliu_seka) {
        int ascii_suma = 0; // Naudojama ascii reiksmiu sumai
        int daugiklis = 1; // Bandysiu didinti daugiklio skaiciu ir dauginti ascii_suma per ji
    
        int ilgis = 8 * simboliu_seka.size(); // Simboliu sekos ilgis bitais
        cout << "Simboliu seka yra: " << simboliu_seka << endl;
        cout << "Jusu zodis susideda is " << ilgis << " bitu." << endl;

        // Zodis isverciamas i ASCII
        for (char simbolis : simboliu_seka) {
            //cout << "Simbolis " << simbolis << " uzkoduotas kaip " << (int)simbolis << " pagal ASCII" << endl;
            ascii_suma += (int)simbolis * daugiklis;
            daugiklis++;
        }

        cout << "Padauginta ASCII suma yra: " << ascii_suma << endl;

        // Ascii_suma isverciama i binary
        bitset<256> binarinis_kodas((int)ascii_suma);
        cout << "Padauginta ASCII suma pavaizduota kaip binarinis kodas: " << binarinis_kodas << endl;
        for (int i = 0; i < 5; i++)
        {
            bitaiKeiciasiVietomis(binarinis_kodas);
        }

        // Gautas binary kodas isverciamas i ASCII tolimesniems skaiciavimams
        int reiksmiu_suma = 0;
        for (int i = 0; i < 256; i += 8) {   
            int reiksme = 0; 

            reiksme += binarinis_kodas[i] * 128; 
            reiksme += binarinis_kodas[i + 1] * 64;
            reiksme += binarinis_kodas[i + 2] * 32;
            reiksme += binarinis_kodas[i + 3] * 16;
            reiksme += binarinis_kodas[i + 4] * 8;
            reiksme += binarinis_kodas[i + 5] * 4;
            reiksme += binarinis_kodas[i + 6] * 2;
            reiksme += binarinis_kodas[i + 7] * 1;
            reiksmiu_suma += reiksme + i; // Truputi paivairnta suma
        }

        cout << "Ascii suma: " << reiksmiu_suma << endl;

        string hexKodas = hexPadarymas(binarinis_kodas);
        cout << "Hash kodo atvaizdavimas hex pavidalu: " << hex << hexKodas << endl;
}

string failoGeneravimas (string failoPavadinimas, int simboliu_sk) {
    ofstream fail(failoPavadinimas);
    string random_simboliai;
    
    for (int i = 0; i < simboliu_sk; i++) {
        random_simboliai = rand() % 95 + 32; 
        fail << random_simboliai;
    }
    
    fail.close();
    cout << "Sugeneruoto failo pavadinimas: " << failoPavadinimas << endl;
}