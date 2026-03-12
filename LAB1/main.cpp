#include <iostream>
#include <string>
#define N 10
using namespace std;

// dodaj numer indeksu, imie - rozbudowa modelu danych
// mozliwosc wprowadzania zmian w wprowadzonych wczesniej danych, usuwanie z listy - rozbudowa funkcjonalności: imie nazwisko ...

void dodajOsobe(string* tablica, string osoba);
void ustawObecnosc(string* tab1, bool* tab2, string nazwisko, bool obecnosc);
int wyswietlListe(string* tab1, bool* tab2);


int main(void) {
    string tabNazwisko[N] = {"Nowak", "Kowalski", "Duda"};
    bool tabObecnosc[N] = {1, 0, 1};

    int input = 0;
    string temp_string;
    bool temp_bool;

    while (input != -1) { 
        cout << "\n==========";
        cout << endl;
        cout << "\n1. Dodaj nowa osobe";
        cout << "\n2. Ustaw obecnosc";
        cout << "\n3. Wyswietl liste";
        cout << "\n0. Zakoncz";
        cout << endl;
        cin >> input;
        switch (input)  {
        case 1:
            cout << endl; 
            cout << "Wprowadz nazwisko: ";
            cin >> temp_string;
            dodajOsobe(tabNazwisko, temp_string);
            break;
        case 2:
            cout << endl; 
            cout << "Wprowadz nazwisko: ";
            cin >> temp_string;
            cout << endl;
            cout << "Wprowadz obecnosc (0/1): ";
            cin >> temp_bool;
            ustawObecnosc(tabNazwisko, tabObecnosc, temp_string, temp_bool);
            break;
        case 3:
            wyswietlListe(tabNazwisko, tabObecnosc);
            break;
        default:
            input = -1;
            break;
        }
    }
        
    
    return 0;
}

void dodajOsobe(string* tablica, string osoba) {
    for (int i = 0; i < N; i++) {
        if (tablica[i] == "") {
            tablica[i] = osoba;
            break;
        } else {
            cout << "\nBrak miejsca.";
        }
    }
}

void ustawObecnosc(string* tab1, bool* tab2, string nazwisko, bool obecnosc) {
        for (int i = 0; i < N; i++) {
        if (tab1[i] == nazwisko) {
            tab2[i] = obecnosc;
            cout << "\nUstawiono obecnosc.";
        }
    }
}

int wyswietlListe(string* tab1, bool* tab2) {
    cout << "\n================";
    cout << endl;
    cout << "\nLp. Nazwisko Obecny";
    for (int i = 0; i < N; i++) {
        if (tab1[i] == "") {
            return 0;
        }
        cout << endl;
        cout << i + 1 << ". " << tab1[i] << " " << tab2[i];
    }
    return 1;
}