#include "ManoHash.h"

int main(int argc, char* argv[]) {
    srand(12456);
    int pasirinkimas;
    cout << "Pasirinkite:\n";
    cout << "1. Rankiniu budu ivesti simboliu seka." << endl;
    cout << "2. Nurodyti failo pavadinima." << endl;
    cout << "3. Sugeneruoti ir nuskaityti du failus." << endl; // Pakeistas pasirinkimas
    cout << "4. Nuskaityti konstitucija faila." << endl; // Pridėtas pasirinkimas
    cout << "Jusu pasirinkimas: "; cin >> pasirinkimas;

    string ivestis;

    if (pasirinkimas == 1) {
        cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: "; cin >> ivestis;
        getline(cin, ivestis);
    } else if (pasirinkimas == 2) {
        if (argc < 2) {
            cout << "Pateikite failo pavadinima." << endl;
            return 1; 
        }

        string failoPavadinimas = argv[1];

        ifstream inputFile(failoPavadinimas);
        if (!inputFile.is_open()) {
            cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
            return 1; 
        }

        getline(inputFile, ivestis); 
        inputFile.close();
    } else if (pasirinkimas == 3) {
        if (argc < 4) {
            cout << "Pateikite du failo pavadinimus ir simboliu ilgi." << endl;
            return 1; 
        }

        string failoPavadinimas1 = argv[1]; // Pirmo failo pavadinimas
        string failoPavadinimas2 = argv[2]; // Antro failo pavadinimas
        int simboliuIlgis = atoi(argv[3]); // Simboliu ilgis

        failoGeneravimas(failoPavadinimas1, simboliuIlgis);
        failoGeneravimas(failoPavadinimas2, simboliuIlgis);

        string vienas = nuskaitymasIsFailo(failoPavadinimas1);
        //cout << "Pirmo failo hash: " << hashFunkcija(vienas) << endl;

        string du = nuskaitymasIsFailo(failoPavadinimas2);
        //cout << "Antro failo hash: " << hashFunkcija(du) << endl;

        return 0;
    } else if (pasirinkimas == 4) {
        cout << "Nuskaitomas konstitucija failas." << endl;
        
        string failoPavadinimas = "konstitucija.txt"; 
        ifstream inputFile(failoPavadinimas);
        if (!inputFile.is_open()) {
            cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
            return 1; 
        }

        vector<string> linijos;
        string linija;
        while (getline(inputFile, linija)) {
            linijos.push_back(linija);
        }
        inputFile.close();

        int linijuKiekis;
        cout << "Kiek eiluciu norite hashuoti? Max: " << linijos.size() << ". Jusu pasirinkimas: "; cin >> linijuKiekis;

        if (linijuKiekis < 1 || linijuKiekis > linijos.size()) {
            cout << "Neteisingas eiluciu skaicius. Pasirinkite skaiciu tarp 1 ir " << linijos.size() << "." << endl;
            return 1;
        }

        vector<string> hashuojamos_eilutes(linijos.begin(), linijos.begin() + linijuKiekis);
        double vidutinis_laikas = laikoMatavimas(hashuojamos_eilutes);
        cout << "Vidutinis hashavimo laikas: " << vidutinis_laikas << " milisekundziu." << endl;

        return 0;
    } else {
        cout << "Neteisingas pasirinkimas." << endl;
        return 1; 
    }

    hashFunkcija(ivestis); 

    return 0;
}

// g++ ManoHashCLA.cpp -o ManoHashCLA
// ./ManoHashCLA 
// ./ManoHashCLA simbolis_1.txt
// ./ManoHashCLA simbolis_2.txt
// ./ManoHashCLA simbolis_3.txt
// ./ManoHashCLA tekstas_1000_kitas.txt
// ./ManoHashCLA tekstas_1000.txt
// ./ManoHashCLA tuscias.txt
// ./ManoHashCLA failas1.txt failas2.txt 1000