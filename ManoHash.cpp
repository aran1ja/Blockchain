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
cout << "6. Baigti darba." << endl;
cout << "Jusu pasirinkimas: "; cin >> pasirinkimas;

switch (pasirinkimas) {
    case 1:
    {

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