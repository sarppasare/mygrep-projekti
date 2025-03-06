// Saara Pisil�, Ohjelmoinnin edistyneet piirteet 2025 kev�t
// 2 inkrementti�, 3 pistett�

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//1. inkrementti
void etsiTekstista(const string& teksti, const string& etsittavaTeksti) {
    size_t loytyi = teksti.find(etsittavaTeksti);
    if (loytyi != string::npos) {
        cout << "\"" << etsittavaTeksti << "\" l�ytyi tekstist� \"" << teksti << "\" kohdasta " << (loytyi + 1) << endl;
    }
    else {
        cout << "\"" << etsittavaTeksti << "\" Ei l�ytynyt tekstist� \"" << teksti << "\"" << endl;
    }
}

//2. inkrementti
void etsiTiedostosta(const string& tiedostonimi, const string& etsittavaTeksti) {
    ifstream file(tiedostonimi);
    if (!file.is_open()) {
        cerr << "Tiedostoa ei voitu avata: " << tiedostonimi << endl;
        return;
    }

    string rivi;
    while (getline(file, rivi)) {
        if (rivi.find(etsittavaTeksti) != string::npos) {
            cout << rivi << endl;
        }
    }

    file.close();
}

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "fi_FI"); //��kk�set n�kyviin

    if (argc == 1) {
        //1. inkrementti
        string teksti;
        string etsittavaTeksti;

        cout << "Anna teksti, josta etsit��n: ";
        getline(cin, teksti);

        cout << "Anna tekstin p�tk�, joka etsit��n: ";
        getline(cin, etsittavaTeksti);

        etsiTekstista(teksti, etsittavaTeksti);
    }
    else if (argc == 3) {
        //2. inkrementti
        string etsittavaTeksti = argv[1];
        string tiedostonimi = argv[2];

        etsiTiedostosta(tiedostonimi, etsittavaTeksti);
    }
    else {
        cerr << "Virheelliset komentoriviargumentit." << endl;
        cerr << "K�ytt�: ./mygrep [etsittavaTeksti] [tiedostonimi]" << endl;
    }

    return 0;
}