#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

void bitaiKeiciasiVietomis(bitset<64> bitai) {
    int binarinis_ilgis = bitai.size(); 
    for (int i = 0; i < binarinis_ilgis; i++) 
    {
        bitai[binarinis_ilgis - i - 1] = bitai[i]; 
    }
    
    cout << "Bitukas: " << bitai << endl;

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
        bitaiKeiciasiVietomis(binarinis_kodas);

/*
        unsigned long atgal_i_ascii_1 = binarinis_kodas.to_ulong();
        // Zodis antra akrta isverciamas i ASCII
        cout << "Binarinis kodas pavaizduotas kaip ascii: " << atgal_i_ascii_1 << endl;

        cout << "-----------------------------------------" << endl;

        //Bandymas sukurti hash koda
        int ascii_sukeista = ascii_suma * ilgis + (ilgis / 2);
        cout << "Sukeisto ASCII pavaizdavimas: " << ascii_sukeista << endl;
        bitset<64> binarinis_kodukas((int)ascii_sukeista);
        cout << "Sukeisto ASCII binarinis kodas: " << binarinis_kodukas << endl;
*/
        // Gaunamas kitoks binarinis kodas. 
        // PROBLEMA PATAISYMUI: jeigu ivesti zodzius su tokiom paciomis ascii reiksmemis, tai gausis tas pats rezultatas - pataisyta
        // Hex'ui reikia 256 bitu binary code'o
            
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

