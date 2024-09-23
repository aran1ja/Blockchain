#include "ManoHash.h"

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
        string simboliai;
        cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: "; cin >> simboliai;
        hashFunkcija(simboliai);
        break;
    }

    case 2:
    {
        // logic errors
        cout << "Nuskaitomi 3 failai su vienu simboliu kiekviename. " << endl;
        string simbolis1 = nuskaitymasIsFailo("simbolis_1.txt");
        hashFunkcija(simbolis1);
        cout << "-----------------------------------------------------------------" << endl;
        string simbolis2 = nuskaitymasIsFailo("simbolis_2.txt");
        hashFunkcija(simbolis2);
        cout << "-----------------------------------------------------------------" << endl;
        string simbolis3 = nuskaitymasIsFailo("simbolis_3.txt");
        hashFunkcija(simbolis3);
        break;
    }
    case 3:
    {
        nuskaitymasIsFailo("simbolis_1.txt");
        nuskaitymasIsFailo("simbolis_1.txt");
    }
    case 4:
    {
        nuskaitymasIsFailo("tekstas_1000.txt");
    }
    case 5:
    {
        nuskaitymasIsFailo("tekstas_1000_kitas.txt");
    }
    case 6:
    {
        nuskaitymasIsFailo("tuscias.txt");
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