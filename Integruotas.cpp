#include "ManoHash.h"
//#include "robertos_hash.h"
#include "rugiles_hash.h"
#include "kamiles_hash.h"
#include "paulinos_hash.h"

int main() {
    int pasirinkti;
    cout << "Sioje programoje bus paleidziamos 4 programos atskirai." << endl;
    cout << "Paleidus programa, bus paleisti 3-6 eksperimentai." << endl;
    cout << "Tai yra: konstitucija.txt nuskaitymas, koliziju tikrinimas ir lavinos efekto patikrinimas" << endl;
    cout << "1. Paleisti Adrianos koda." << endl;
    cout << "2. Paleisti Rugiles koda." << endl;
    cout << "3. Paleisti Kamiles koda." << endl;
    cout << "4. Paleisti Paulinos koda." << endl;
    cout << "Kuria programa norite paleisti?" << endl;
    cout << "Jusu pasirinkimas: "; cin >> pasirinkti;

    switch (pasirinkti)
    {
    case 1: 
    {
        cout << "Adrianos kodas." << endl;
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
        cout << "Rugiles kodas." << endl;
        cout << "'Konstitucija.txt' eiluciu nuskaitymas ir laiko matavimas." << endl;
        testavimas("konstitucija.txt");
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamos kolizijos." << endl;
        nuu().tikrinti_hash_kolizijas(); //testas_kolizijos.txt
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamas lavinos efektas: skirtumas bit'u ir hex'u lygmenyje." << endl;
        lavinos_failas(); //lavinos.txt
        nuu().lavinos_testavimas();
        break;
    }

    case 3: 
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        cout << "Kamiles kodas." << endl;
        cout << "'Konstitucija.txt' eiluciu nuskaitymas ir laiko matavimas." << endl;
        konstitucijosTestavimas();
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamos kolizijos." << endl;
        kolizijosTestavimas(); //atsitiktinesporos.txt
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamas lavinos efektas: skirtumas bit'u ir hex'u lygmenyje." << endl;
        AvalancheTestavimas(); //inputForAvalanche.txt
        break;
    }

    case 4: 
    {
        cout << "Paulinos kodas." << endl;
        cout << "'Konstitucija.txt' eiluciu nuskaitymas ir laiko matavimas." << endl;
        vector<string> fileName = skaitytieil("konstitucija.txt");
        konstitucijatestas(fileName);
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamos kolizijos." << endl;
        vector<pair<string, string>> randompora = generuojamrandporas();
        string filename = "randomporos.txt";
        porosfailiukas(randompora, filename);
        hashkolizijos(randompora);
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamas lavinos efektas: skirtumas bit'u ir hex'u lygmenyje." << endl;
        const int numPairs = 100000;
        const int maxLength = 1000;
        vector<pair<string, string>> randomporampam = generuojamporas1simbdiff(numPairs, maxLength);
        lavinosteastas(randomporampam);
        break;
    }
    
    default:
        cout << "Neteisingas pasirnkimas." << endl;
        break;
    }

}