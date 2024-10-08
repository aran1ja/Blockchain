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
    case 1: //done
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
        
    case 2: //iskyla problemu
    {
        cout << "Robertos kodas." << endl;
        cout << "'Konstitucija.txt' eiluciu nuskaitymas ir laiko matavimas." << endl;
        konstitucijaR("konstitucija.txt");
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamos kolizijos." << endl;
        generuotiPorasR("poros.txt");
        apdorotiPorasIrTikrinimasR("poros.txt", "kolizijosRoberta.txt");
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamas lavinos efektas: skirtumas bit'u ir hex'u lygmenyje." << endl;
        lavinosEfektasR("lavinosEfektasRoberta.txt", "lavinosRezultatasRoberta.txt");
        break;
    }

    case 3: //done
    {
        cout << "Rugiles kodas." << endl;
        cout << "'Konstitucija.txt' eiluciu nuskaitymas ir laiko matavimas." << endl;
        testavimas("konstitucija.txt");
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamos kolizijos." << endl;
        nuu().tikrinti_hash_kolizijas();
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamas lavinos efektas: skirtumas bit'u ir hex'u lygmenyje." << endl;
        lavinos_failas();
        nuu().lavinos_testavimas();
        break;
    }

    case 4: //done
    {
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

    case 5: //done
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

    case 6:
    {
        cout << "Bendras kodas." << endl;
        cout << "'Konstitucija.txt' eiluciu nuskaitymas ir laiko matavimas." << endl;
        
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamos kolizijos." << endl;
        
        cout << "----------------------------------------------------------" << endl;
        cout << "Patikrinamas lavinos efektas: skirtumas bit'u ir hex'u lygmenyje." << endl;
        
        break;
    }
    
    default:
        cout << "Neteisingas pasirnkimas." << endl;
        break;
    }

}