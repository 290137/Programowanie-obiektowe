#include <iostream>
#include <string>

#define N 10
using namespace std;


void dodajOsobe(string* imiona, string* nazwiska, string* indeksy, string imie, string nazwisko, string indeks);
void ustawObecnosc(string* nazwiska, bool* obecnosc, string nazwisko, bool stan);
void edytujOsobe(string* imiona, string* nazwiska, string* indeksy, string indeks);
void usunOsobe(string* imiona, string* nazwiska, string* indeksy, bool* obecnosci, string indeks);
int wyswietlListe(string* imiona, string* nazwiska, string* indeksy, bool* obecnosc);

int main(void) {
    string tabImie[N] = {"Jan", "Adam", "Andrzej"};
    string tabNazwisko[N] = {"Nowak", "Kowalski", "Duda"};
    string tabIndeks[N] = {"12345", "23456", "34567"};
    bool tabObecnosc[N] = {1, 0, 1};

    int input = 0;
    string t_imie, t_nazwisko, t_indeks;
    bool t_bool;

    while (input != -1) {
        cout << "\n====================";
        cout << "\n1. Dodaj nowa osobe";
        cout << "\n2. Ustaw obecnosc (po nazwisku)";
        cout << "\n3. Wyswietl liste";
        cout << "\n4. Edytuj dane (po indeksie)";
        cout << "\n5. Usun osobe (po indeksie)";
        cout << "\n0. Zakoncz";
        cout << "\nWybor: ";
        cin >> input;

        switch (input) {
        case 1:
            cout << "Podaj imie: "; cin >> t_imie;
            cout << "Podaj nazwisko: "; cin >> t_nazwisko;
            cout << "Podaj numer indeksu: "; cin >> t_indeks;
            dodajOsobe(tabImie, tabNazwisko, tabIndeks, t_imie, t_nazwisko, t_indeks);
            break;
        case 2:
            cout << "Wprowadz nazwisko: "; cin >> t_nazwisko;
            cout << "Obecnosc (0/1): "; cin >> t_bool;
            ustawObecnosc(tabNazwisko, tabObecnosc, t_nazwisko, t_bool);
            break;
        case 3:
            wyswietlListe(tabImie, tabNazwisko, tabIndeks, tabObecnosc);
            break;
        case 4:
            cout << "Podaj indeks osoby do edycji: "; cin >> t_indeks;
            edytujOsobe(tabImie, tabNazwisko, tabIndeks, t_indeks);
            break;
        case 5:
            cout << "Podaj indeks osoby do usuniecia: "; cin >> t_indeks;
            usunOsobe(tabImie, tabNazwisko, tabIndeks, tabObecnosc, t_indeks);
            break;
        case 0:
            input = -1;
            break;
        default:
            cout << "\nNiepoprawna opcja.";
            break;
        }
    }
    return 0;
}

void dodajOsobe(string* imiona, string* nazwiska, string* indeksy, string imie, string nazwisko, string indeks) {
    for (int i = 0; i < N; i++) {
        if (nazwiska[i] == "") {
            imiona[i] = imie;
            nazwiska[i] = nazwisko;
            indeksy[i] = indeks;
            cout << "\nDodano osobe do listy.";
            return; 
        }
    }
    cout << "\nBrak miejsca w tablicy.";
}

void ustawObecnosc(string* nazwiska, bool* obecnosc, string nazwisko, bool stan) {
    bool znaleziono = false;
    for (int i = 0; i < N; i++) {
        if (nazwiska[i] == nazwisko) {
            obecnosc[i] = stan;
            znaleziono = true;
        }
    }
    if (znaleziono) cout << "\nZaktualizowano obecnosc.";
    else cout << "\nNie znaleziono osoby o takim nazwisku.";
}

void edytujOsobe(string* imiona, string* nazwiska, string* indeksy, string indeks) {
    for (int i = 0; i < N; i++) {
        if (indeksy[i] == indeks && indeks != "") {
            cout << "Nowe imie: "; cin >> imiona[i];
            cout << "Nowe nazwisko: "; cin >> nazwiska[i];
            cout << "Dane zaktualizowane.";
            return;
        }
    }
    cout << "\nOsoba o podanym indeksie nie istnieje.";
}

void usunOsobe(string* imiona, string* nazwiska, string* indeksy, bool* obecnosci, string indeks) {
    for (int i = 0; i < N; i++) {
        if (indeksy[i] == indeks && indeks != "") {
            imiona[i] = "";
            nazwiska[i] = "";
            indeksy[i] = "";
            obecnosci[i] = 0;
            cout << "\nOsoba zostala usunieta.";
            return;
        }
    }
    cout << "\nNie znaleziono osoby o takim indeksie.";
}

int wyswietlListe(string* imiona, string* nazwiska, string* indeksy, bool* obecnosc) {
    cout << "\n================================";
    int licznik = 0;
    for (int i = 0; i < N; i++) {
        if (nazwiska[i] != "") {
            cout << "\n" << i + 1 << ". " << indeksy[i] << " \t " << imiona[i] << " \t " << nazwiska[i] << " \t " << (obecnosc[i] ? "TAK" : "NIE");
            licznik++;
        }
    }
    if (licznik == 0) cout << "\nLista jest pusta.";
    cout << "\n=======================================" << endl;
    return licznik;
}