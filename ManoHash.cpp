#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

void bitaiKeiciasiVietomis(bitset<64>& bitai) {
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

    // Pataisyta
    // Keiciasi 1-4 bitai su 60-64
    for (int i = 0; i < 4; i++) {
        bool laikinas = bitai[i];
        bitai[i] = bitai[60 + i]; 
        bitai[60 + i] = laikinas;  
    }

    // Keiciasi 8-12 bitai su 52-56
    for (int i = 0; i < 4; i++) {
        bool laikinas = bitai[8 + i];
        bitai[8 + i] = bitai[52 + i]; 
        bitai[52 + i] = laikinas;  
    }

    // Keiciasi 16-20 bitai su 44-48
    for (int i = 0; i < 4; i++) {
        bool laikinas = bitai[16 + i];
        bitai[16 + i] = bitai[44 + i]; 
        bitai[44 + i] = laikinas;  
    }

    // Keiciasi 24-28 bitai su 36-40
    for (int i = 0; i < 4; i++) {
        bool laikinas = bitai[24 + i];
        bitai[24 + i] = bitai[36 + i]; 
        bitai[36 + i] = laikinas;  
    }

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
        bitset<64> binarinis_kodas((int)ascii_suma);
        cout << "Padauginta ASCII suma pavaizduota kaip binarinis kodas: " << binarinis_kodas << endl;
        for (int i = 0; i < 7; i++)
        {
            bitaiKeiciasiVietomis(binarinis_kodas);
        }

        // Atsakymas hex pavidalu
        unsigned long long hexKodas = binarinis_kodas.to_ullong(); 
        cout << "Hash kodo atvaizdavimas hex pavidalu: " << hex << hexKodas << endl;
            
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
