#include <iostream>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <vector>
#include <algorithm>
#include <numeric>   
#include "sha256.h"

double laikoMatavimas(vector<string>& linijos) {
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < 5; i++)
    {
        for (const auto& linija : linijos) {
            sha256(linija);
        }
    }
    auto pabaiga = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> skirtumas = pabaiga - start;
    return skirtumas.count() / 5; 
}

void failuNuskaitymasIrHashavimas(const string& filename) {
    ifstream file(filename);
    vector<string> linijos; // Cia issaugomi duomenys
    string linija;

    while (getline(file, linija)) {
        linijos.push_back(linija);
    }

    int linijuKiekis;
    cout << "Kiek eiluciu norite hashuoti? (Max: " << linijos.size() << "): "; cin >> linijuKiekis;

    vector<string> hashuojamos_eilutes(linijos.begin(), linijos.begin() + linijuKiekis);

    double vidutinis_laikas = laikoMatavimas(hashuojamos_eilutes);
    cout << "Vidutinis hashavimo laikas: " << vidutinis_laikas << " milisekundziu." << endl;
}

string randomSimboliuGeneravimas() {
    char simboliukai[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string sukurtasStringas;
    
    for (int i = 0; i < 10; i++) {
        sukurtasStringas += simboliukai[rand() % (sizeof(simboliukai) - 1)]; 
    }

    return sukurtasStringas;
} 

void kurtiFailiuka(string failiukas, int linijuKiekis) {
    ofstream a(failiukas);

    if (linijuKiekis > 0) {
        for (int i = 0; i < linijuKiekis; ++i) {
            a << randomSimboliuGeneravimas() << endl; 
        }
    }
    
    a.close();
    cout << "Failas sukurtas: " << failiukas << " su " << linijuKiekis << " eilutemis." << endl;
}
 
int main(int argc, char *argv[])
{   
    int pasirinkimas;
    cout << "1. Konstitucijos nuskaitymas." << endl;
    cout << "2. Failu nuskaitymas." << endl;
    cin >> pasirinkimas;

    switch(pasirinkimas) {
        case 1:
        {
            failuNuskaitymasIrHashavimas("konstitucija.txt"); 
            break;
        }

        case 2:
        {
            int pasirinkimas2;
            int pasirinkimas3;
            /*
            cout << "Ar norite sukurti naujus failus? 1 jei taip" << endl;
            cin >> pasirinkimas2;
            if (pasirinkimas2 == 1) {
                kurtiFailiuka("kurti_10000.txt", 10000);
                kurtiFailiuka("kurti_50000.txt", 50000);
                kurtiFailiuka("kurti_100000.txt", 100000);
                kurtiFailiuka("kurti_250000.txt", 250000);
                kurtiFailiuka("kurti_500000.txt", 500000);
            } else break;
            */

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
                failuNuskaitymasIrHashavimas("tuscias.txt");
                break;
            }
            case 2:
            {
                failuNuskaitymasIrHashavimas("kurti_10000.txt");
                break;
            }
            case 3:
            {
                failuNuskaitymasIrHashavimas("kurti_50000.txt");
                break;
            }
            case 4:
            {
                failuNuskaitymasIrHashavimas("kurti_100000.txt");
                break;
            }
            case 5:
            {
                failuNuskaitymasIrHashavimas("kurti_250000.txt");
                break;
            }
            case 6:
            {
                failuNuskaitymasIrHashavimas("kurti_500000.txt");
                break;
            }
            
            default:
                break;
            }
        }
    } 
}