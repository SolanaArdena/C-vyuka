#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Otazka {
    string textOtazky;
    string moznosti[3];
    char spravnaMoznost;
};

void nactiOtazkyZeSouboru(const string& nazevSouboru, vector<Otazka>& otazky) {
    ifstream soubor(nazevSouboru);
    if (!soubor.is_open()) {
        cerr << "Nepodařilo se otevřít soubor s otázkami." << endl;
        exit(1);
    }

    string radek;
    while (getline(soubor, radek)) {
        Otazka otazka;

        // Oddělení otázky a odpovědí na základě středníků
        size_t oddelovac = radek.find(";");
        otazka.textOtazky = radek.substr(0, oddelovac);
        radek = radek.substr(oddelovac + 1);

        for (int i = 0; i < 3; i++) {
            oddelovac = radek.find(";");
            otazka.moznosti[i] = radek.substr(0, oddelovac);
            radek = radek.substr(oddelovac + 1);
        }

        otazka.spravnaMoznost = radek[0]; // Poslední znak určuje správnou odpověď
        otazky.push_back(otazka);
    }

    soubor.close();
}

int main() {
    srand(time(0)); // Inicializace generátoru náhodných čísel

    vector<Otazka> otazky;
    nactiOtazkyZeSouboru("otazky.txt", otazky);

    int skore = 0;
    char odpoved;

    for (const Otazka& otazka : otazky) {
        cout << otazka.textOtazky << endl;
        for (int i = 0; i < 3; i++) {
            cout << char('a' + i) << ") " << otazka.moznosti[i] << endl;
        }

        cout << "Zadejte odpověď (a/b/c): ";
        cin >> odpoved;

        if (odpoved == otazka.spravnaMoznost) {
            cout << "Správně!" << endl;
            skore++;
        } else {
            cout << "Špatně..." << otazka.spravnaMoznost << endl;
        }
    }

    cout << "Konec kvízu. Celkový počet bodů: " << skore << "/" << otazky.size() << endl;

    return 0;
}
