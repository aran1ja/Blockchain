#include "bendras_hash.h"

int main() {
    int iuiu;
    cout << "Si programa turi maisos funkcija, sudaryta is 4 maisos funkciju." << endl;
    cout << "Ar norite: " << endl;
    cout << "1. Rankiniu budu parasyti ivesti.\n2. Paleisti numatyta programa?" << endl;
    cout << "Jusu pasirinkimas: "; cin >> iuiu;
    switch (iuiu)
    {
    case 1:
    {   
        string ivestis;
        cout << "Iveskite simboliu seka: "; cin >> ivestis;
        getline(cin, ivestis);
        string hexas = bendrasHash(ivestis);
        cout << "Simboliu sekos hash: " << hexas << endl;
        break;
    }

    case 2:
    {
        cout << "Bendras kodas." << endl;
        cout << "'Konstitucija.txt' eiluciu nuskaitymas ir laiko matavimas." << endl;
        konstitucija("konstitucija.txt");
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamos kolizijos." << endl;
        //kolizijosTestavimas();
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamas lavinos efektas: skirtumas bit'u ir hex'u lygmenyje." << endl;
        //AvalancheTestavimas();
        break;
    }
        
    default:
        break;
    }
}