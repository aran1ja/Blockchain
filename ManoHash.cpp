#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>

using namespace std;

void pakeitimasPo4bitus(bitset<256>& bitai, int reiksme_1, int reiksme_2) {
    for (int i = 0; i < 4; i++) {
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

    pakeitimasPo4bitus(bitai,  0, 256);
    pakeitimasPo4bitus(bitai,  8, 248);
    pakeitimasPo4bitus(bitai, 16, 240);
    pakeitimasPo4bitus(bitai, 24, 232);
    pakeitimasPo4bitus(bitai, 32, 224);
    pakeitimasPo4bitus(bitai, 40, 216);
    pakeitimasPo4bitus(bitai, 48, 208);
    pakeitimasPo4bitus(bitai, 56, 200);
    pakeitimasPo4bitus(bitai, 64, 192);
    pakeitimasPo4bitus(bitai, 72, 184);
    pakeitimasPo4bitus(bitai, 80, 176);
    pakeitimasPo4bitus(bitai, 88, 168);
    pakeitimasPo4bitus(bitai, 96, 160);
    pakeitimasPo4bitus(bitai, 104, 152);
    pakeitimasPo4bitus(bitai, 112, 144);
    pakeitimasPo4bitus(bitai, 120, 136);

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
    cout << "-----------------------------------------------------" << endl;
}

int main() {

int pasirinkimas;
cout << "Sita programa yra skirta SHA256 generavimui." << endl;
cout << "Paspaudus skaiciu issirinkite ka norite padaryti." << endl;
cout << "1. Ivesti zodi arba simboli rankiniu budu." << endl;
cout << "2. Atidaryti failus, sudarytus tik is vieno simbolio." << endl;
cout << "3. Atidaryti programos sugeneruotus failus, kuriuose yra > 1000 simboliu." << endl;
cout << "4. Atidaryti faila tekstas_1000.txt, kuriame yra > 1000 simboliu." << endl;
cout << "5. Atidaryti faila tekstas_1000_kitas.txt, kuris skiriasi nuo tekstas_1000.txt tik vienu simboliu." << endl;
cout << "6. Atidaryti tuscia faila 'tuscias.txt'." << endl;
cout << "7. Baigti darba." << endl;
cout << "Jusu pasirinkimas: "; cin >> pasirinkimas;

switch (pasirinkimas) {
    case 1:
    {
        string simboliu_seka; // Naudojama tam, kad butu ivesta simboliu seka, kuria reikia isversti
        int ascii_suma = 0; // Naudojama ascii reiksmiu sumai
        int daugiklis = 1; // Bandysiu didinti daugiklio skaiciu ir dauginti ascii_suma per ji
    
        cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: "; cin >> simboliu_seka;
        int ilgis = 8 * simboliu_seka.size(); // Simboliu sekos ilgis bitais
        cout << "Jusu zodis susideda is " << ilgis << " bitu." << endl;

        // Zodis isverciamas i ASCII
        for (char simbolis : simboliu_seka) {
            cout << "Simbolis " << simbolis << " uzkoduotas kaip " << (int)simbolis << " pagal ASCII" << endl;
            ascii_suma += (int)simbolis * daugiklis;
            daugiklis++;
        }

        cout << "Padauginta ASCII suma yra: " << ascii_suma << endl;

        // Ascii_suma isverciama i binary
        bitset<256> binarinis_kodas((int)ascii_suma);
        cout << "Padauginta ASCII suma pavaizduota kaip binarinis kodas: " << binarinis_kodas << endl;
        for (int i = 0; i < 7; i++)
        {
            bitaiKeiciasiVietomis(binarinis_kodas);
        }

        // Atsakymas hex pavidalu
        // terminate called after throwing an instance of 'std::overflow_error'
        // what():  _Base_bitset::_M_do_to_ullong
        cout << "Hash kodo atvaizdavimas hex pavidalu: " << hex << binarinis_kodas << endl;
            
        return 0;
    }


    case 2:
    {
        
    }
    case 3:
    {
        
    }
    case 4:
    {
        
    }
    case 5:
    {
        
    }
    case 6:
    {
        
    }
    case 7:
    {
        cout << "Darbas baigtas." << endl;
        break;
    }
    default: 
    {
        cout << "Ivedete neteisinga skaiciu. Bandykite dar karta." << endl;
        break;
    }
}

}