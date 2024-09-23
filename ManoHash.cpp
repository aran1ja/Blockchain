#include <iostream>
#include <iomanip>

using namespace std;

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
        string simboliu_seka;
        int ascii_suma = 0;

        cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: "; cin >> simboliu_seka;
        int ilgis = 8 * simboliu_seka.size();
        cout << "Jusu zodis susideda is " << ilgis << " bitu." << endl;

        // Zodis isverciamas i ASCII
        for (char simbolis : simboliu_seka) {
            cout << "Simbolis " << simbolis << " uzkoduotas kaip " << (int)simbolis << " pagal ASCII" << endl;
            ascii_suma += (int)simbolis;
            
        }

        cout << "ASCII suma yra: " << ascii_suma;

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