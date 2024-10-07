#include "ManoHash.h"

int main(int argc, char* argv[]) {
    srand(12456);
    int pasirinkimas;

    cout << "Pasirinkite:\n";
    cout << "1. Rankiniu budu ivesti simboliu seka." << endl;
    cout << "2. Nurodyti failo pavadinima." << endl;
    cout << "3. Sugeneruoti ir nuskaityti du failus." << endl;
    cout << "4. Nuskaityti konstitucija faila." << endl;
    cout << "5. Generuoti failus." << endl;
    cout << "6. Generuoti skirtingas poras." << endl;
    cout << "7. Nuskaityti failus - palyginimas su SHA256." << endl;
    cout << "8. Druskos kolizijos - identiskos poros." << endl; 
    cout << "9. Puzzle-friendliness kolizijos." << endl;  
    cout << "Jusu pasirinkimas: "; cin >> pasirinkimas;

    string ivestis;

    if (pasirinkimas == 1) {
        cout << "Iveskite simboliu seka, kuria noretumete uzkoduoti: ";
        cin >> ivestis;
        hashFunkcija(ivestis);
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
        hashFunkcija(ivestis);

    } else if (pasirinkimas == 3) {
        if (argc < 4) {
            cout << "Pateikite du failo pavadinimus ir simboliu ilgi." << endl;
            return 1;
        }

        string failoPavadinimas1 = argv[1];
        string failoPavadinimas2 = argv[2];
        int simboliuIlgis = atoi(argv[3]);

        failoGeneravimas(failoPavadinimas1, simboliuIlgis);
        failoGeneravimas(failoPavadinimas2, simboliuIlgis);

        string vienas = nuskaitymasIsFailo(failoPavadinimas1);
        cout << "Pirmo failo hash: " << hashFunkcija(vienas) << endl;

        string du = nuskaitymasIsFailo(failoPavadinimas2);
        cout << "Antro failo hash: " << hashFunkcija(du) << endl;

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
        cout << "Kiek eiluciu norite hashuoti? Max: " << linijos.size() << ". Jusu pasirinkimas: "; 
        cin >> linijuKiekis;

        if (linijuKiekis < 1 || linijuKiekis > linijos.size()) {
            cout << "Neteisingas eiluciu skaicius. Pasirinkite skaiciu tarp 1 ir " << linijos.size() << "." << endl;
            return 1;
        }

        vector<string> hashuojamos_eilutes(linijos.begin(), linijos.begin() + linijuKiekis);
        double vidutinis_laikas = laikoMatavimas(hashuojamos_eilutes);
        cout << "Vidutinis hashavimo laikas: " << vidutinis_laikas << " milisekundziu." << endl;

    } else if (pasirinkimas == 5) {
        if (argc < 3) {
            cout << "Pateikite failo pavadinimus." << endl;
            return 1;
        }

        string failoPavadinimas = argv[1];
        failuKurimas(failoPavadinimas);

    } else if (pasirinkimas == 6) {
        if (argc < 2) {
            cout << "Pateikite failo pavadinima." << endl;
            return 1;
        }

        string failoPavadinimas = argv[1];
        generuotiPoras(failoPavadinimas);

    } else if (pasirinkimas == 7) {
        if (argc < 2) {
            cout << "Pateikite failo pavadinima." << endl;
            return 1;
        }

        string failoPavadinimas = argv[1];
        konstitucija(failoPavadinimas);  

    } else if (pasirinkimas == 8) { 
        if (argc < 2) {
            cout << "Pateikite failo pavadinima." << endl;
            return 1;
        }

        string failoPavadinimas = argv[1];
        druskosKolizijos(failoPavadinimas);

    } else if (pasirinkimas == 9) { 
        if (argc < 3) {
            cout << "Pateikite failo pavadinima ir skaiciu." << endl;
            return 1;
        }

        string failoPavadinimas = argv[1];
        int skaicius = atoi(argv[2]);
        puzzleFriendlinessKolizijos(failoPavadinimas, skaicius);

    } else {
        cout << "Neteisingas pasirinkimas." << endl;
        return 1;
    }

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
// ./ManoHashCLA tekstas.txt
// ./ManoHashCLA tekstas.txt 100000
