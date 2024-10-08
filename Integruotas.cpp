#include "ManoHash.h"
#include "robertos_hash.h"
#include "rugiles_hash.h"
#include "kamiles_hash.h"
#include "paulinos_hash.h"

int main() {
    int pasirinkti;
    cout << "Sioje programoje bus paleidziamos 5 programos atskirai ir viena,kurioje bus visi hash'ai' vienoje progamoje." << endl;
    cout << "Paleidus programa, bus paleisti 3-6 eksperimentai." << endl;
    cout << "Tai yra: konstitucija.txt nuskaitymas, koliziju tikrinimas ir lavinos efekto patikrinimas" << endl;
    cout << "1. Paleisti Adrianos koda." << endl;
    cout << "2. Paleisti Robertos koda." << endl;
    cout << "3. Paleisti Rugiles koda." << endl;
    cout << "4. Paleisti Kamiles koda." << endl;
    cout << "5. Paleisti Paulinos koda." << endl;
    cout << "6. Paleisti bendra koda." << endl;
    cout << "Kuria programa norite paleisti?" << endl;
    cout << "Jusu pasirinkimas: "; cin >> pasirinkti;

    switch (pasirinkti)
    {
    case 1:
    {
        cout << "'Konstitucija.txt' eiluciu nuskaitymas ir laiko matavimas." << endl;
        konstitucija("konstitucija.txt");
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamos kolizijos." << endl;
        failuKurimas("100000.txt");
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamas lavinos efektas: skirtumas bit'u ir hex'u lygmenyje." << endl;
        generuotiPoras("lavina.txt");
        break;
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
    
    default:
        cout << "Neteisingas pasirnkimas." << endl;
        break;
    }

}