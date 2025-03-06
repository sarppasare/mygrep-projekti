// Saara Pisilä, Ohjelmoinnin edistyneet piirteet 2025 kevät
// 2 inkrementtiä, 3 pistettä

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//1. inkrementti
void etsiTekstista(const string& teksti, const string& etsittavaTeksti) {
    size_t loytyi = teksti.find(etsittavaTeksti);
    if (loytyi != string::npos) {
        cout << "\"" << etsittavaTeksti << "\" löytyi tekstistä \"" << teksti << "\" kohdasta " << (loytyi + 1) << endl;
    }
    else {
        cout << "\"" << etsittavaTeksti << "\" Ei löytynyt tekstistä \"" << teksti << "\"" << endl;
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

    setlocale(LC_ALL, "fi_FI"); //ääkköset näkyviin

    if (argc == 1) {
        //1. inkrementti
        string teksti;
        string etsittavaTeksti;

        cout << "Anna teksti, josta etsitään: ";
        getline(cin, teksti);

        cout << "Anna tekstin pätkä, joka etsitään: ";
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
        cerr << "Käyttö: ./mygrep [etsittavaTeksti] [tiedostonimi]" << endl;
    }

    return 0;
}