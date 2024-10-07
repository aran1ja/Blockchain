#include "ManoHash.h"

int main() {

//srand(12456);
int pasirinkimas;
cout << "Paspaudus skaiciu issirinkite ka norite padaryti." << endl;
cout << "1. Ivesti zodi arba simboli rankiniu budu." << endl;
cout << "2. Atidaryti failus, sudarytus tik is vieno simbolio." << endl;
cout << "3. Atidaryti programos sugeneruotus failus, kuriuose yra > 1000 simboliu." << endl;
cout << "4. Atidaryti du failus su 1000 simboliais, kurie tarpusavy skiriasi tik 1 simboliu." << endl;
cout << "5. Atidaryti tuscia faila 'tuscias.txt'." << endl;
cout << "6. Sukurtas tyrimui su konstitucija.txt atlikti." << endl;
cout << "7. Patikrinti kolizijas." << endl;
cout << "8. Patikrinti lavinos efekta." << endl;
cout << "9. Baigti darba." << endl;
cout << "10. Kodas palyginimui su SHA256." << endl;
cout << "11. Patikrinti hiding su druska tikrinant kolizijas." << endl;
cout << "Jusu pasirinkimas: "; cin >> pasirinkimas;

switch (pasirinkimas) {
    case 1:
    {
        string simboliai;
        cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: "; cin >> simboliai;
        hashFunkcija(simboliai);
        hashFunkcijaSuDruska(simboliai);
        break;
    }

    case 2:
    {
        cout << "Nuskaitomi 3 failai su vienu simboliu kiekviename. " << endl;
        string simbolis1 = nuskaitymasIsFailo("simbolis_1.txt");
        hashFunkcija(simbolis1);
        hashFunkcijaSuDruska(simbolis1);
        cout << "-----------------------------------------------------------------" << endl;
        string simbolis2 = nuskaitymasIsFailo("simbolis_2.txt");
        hashFunkcija(simbolis2);
        hashFunkcijaSuDruska(simbolis2);
        cout << "-----------------------------------------------------------------" << endl;
        string simbolis3 = nuskaitymasIsFailo("simbolis_3.txt");
        hashFunkcija(simbolis3);
        hashFunkcijaSuDruska(simbolis3);
        break;
    }
    case 3:
    {
        int pasirinkti, pasirinkti1;
        cout << "Ar norite sugeneruoti du naujus failus? Spauskite 1 - taip. Bet koks kitas skacius - ne." << endl; cin >> pasirinkti;
        if (pasirinkti == 1) {
            srand(time(0));
            failoGeneravimas("sugeneruotas1.txt", 1050);
            srand(time(0) + 1);
            failoGeneravimas("sugeneruotas2.txt", 1050);
        }

        cout << "Ar norite tu failo hash'o? Spauskite 1 - taip. Bet koks kitas skacius - ne." << endl; cin >> pasirinkti1;
        if (pasirinkti1 == 1) {
            string vienas = nuskaitymasIsFailo("sugeneruotas1.txt");
            hashFunkcija(vienas);
            string du = nuskaitymasIsFailo("sugeneruotas2.txt");
            hashFunkcija(du);
        } else break;
        break;
    }
    case 4:
    {
        cout << "Nuskaitomi du failuai su 1000 simboliais, kurie tarpusavy skiriasi tik 1 simboliu." << endl;
        string tekstas1 = nuskaitymasIsFailo("tekstas_1000.txt");
        hashFunkcija(tekstas1);
        cout << "-----------------------------------------------------------------" << endl;
        string tekstas2 = nuskaitymasIsFailo("tekstas_1000_kitas.txt");
        hashFunkcija(tekstas2);
        break;
    }
    case 5:
    {
        cout << "Nuskaitomas tuscias failas." << endl;
        string tuscias = nuskaitymasIsFailo("tuscias.txt");
        hashFunkcija(tuscias);
        break;
    }
    case 6:
    {
        konstitucija("konstitucija.txt"); 
        break;
    }
    case 7:
    {
        failuKurimas("100000.txt");
        break;
    }
    case 8:
    {
        generuotiPoras("lavina.txt");
        break;
    }
    case 9:
    {
        cout << "Darbas baigtas." << endl;
        break;
    }
    case 10:
    {
        int pasirinkimas3;

            cout << "Kuri faila norite nuskaityti?" << endl;
            cout << "1. Tuscia." << endl;
            cout << "2. 10.000 failu." << endl; 
            cout << "3. 50.000 failu." << endl; 
            cout << "4. 100.000 failu." << endl; 
            cout << "5. 250.000 failu." << endl; 
            cout << "6. 500.000 failu." << endl; 
            cout << "Jusu pasirinkimas: "; cin >> pasirinkimas3; 
            switch (pasirinkimas3)
            {
            case 1:
            {
                konstitucija("tuscias.txt");
                break;
            }
            case 2:
            {
                konstitucija("kurti_10000.txt");
                break;
            }
            case 3:
            {
                konstitucija("kurti_50000.txt");
                break;
            }
            case 4:
            {
                konstitucija("kurti_100000.txt");
                break;
            }
            case 5:
            {
                konstitucija("kurti_250000.txt");
                break;
            }
            case 6:
            {
                konstitucija("kurti_500000.txt");
                break;
            }
            
            default:
                break;
            }
            break;
    }

    case 11:
    {
        druskosKolizijos("druskosKolizijos.txt");
        break;
    }
    default: 
    {
        cout << "Ivedete neteisinga skaiciu. Bandykite dar karta." << endl;
        break;
    }
}
}
