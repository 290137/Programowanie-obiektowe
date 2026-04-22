#include <iostream>
#include <string>

#define N 10
using namespace std;

// stworzyc klase lista obecnosci skladajaca sie z wskaznika na obiekt osoby i obecnosci bool


class osoba {
    private:
        string imie;
        string nazwisko;
        int indeks;
    public:
        string getImie() {
            return imie;
        }

        string getNazwisko() {
            return nazwisko;
        }

        int getIndeks() {
            return indeks;
        }

        void setImie(string wartosc) {
            if (wartosc.length() >= 2) imie = wartosc;
            else imie = "";
        }

        void setNazwisko(string wartosc) {
            if (wartosc.length() >= 2) nazwisko = wartosc;
            else nazwisko = "";
        }

        void setIndeks(int wartosc) {
            indeks = wartosc;
        }

    };

void dodajOsobe(osoba** tabOsoby, string imie, string nazwisko, int indeks);
void ustawObecnosc(osoba** tabOsoby, bool* obecnosc, string nazwisko, bool stan);
void edytujOsobe(osoba** tabOsoby, int indeks);
void usunOsobe(osoba** tabOsoby, bool* obecnosci, int indeks);
void wyswietlListe(osoba** tabOsoby, bool* obecnosc);

int main(void) {
    osoba *tabOsoby[N];
    bool tabObecnosc[N] = {1, 0, 1};

    for(int i = 0; i < N; ++i) {
        tabOsoby[i] = new osoba();
    }
    
    tabOsoby[0]->setImie("Jan");
    tabOsoby[0]->setNazwisko("nowak");
    tabOsoby[0]->setIndeks(10000001);

    tabOsoby[1]->setImie("Adam");
    tabOsoby[1]->setNazwisko("Kowalski");
    tabOsoby[1]->setIndeks(10000002);

    tabOsoby[2]->setImie("Andrzej");
    tabOsoby[2]->setNazwisko("Duda");
    tabOsoby[2]->setIndeks(10000003);


    int input = 0;
    string t_imie, t_nazwisko;
    int t_indeks;
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
            dodajOsobe(tabOsoby, t_imie, t_nazwisko, t_indeks);
            break;
        case 2:
            cout << "Wprowadz nazwisko: "; cin >> t_nazwisko;
            cout << "Obecnosc (0/1): "; cin >> t_bool;
            ustawObecnosc(tabOsoby, tabObecnosc, t_nazwisko, t_bool);
            break;
        case 3:
            wyswietlListe(tabOsoby, tabObecnosc);
            break;
        case 4:
            cout << "Podaj indeks osoby do edycji: "; cin >> t_indeks;
            edytujOsobe(tabOsoby, t_indeks);
            break;
        case 5:
            cout << "Podaj indeks osoby do usuniecia: "; cin >> t_indeks;
            usunOsobe(tabOsoby, tabObecnosc, t_indeks);
            break;
        case 0:
            input = -1;
            break;
        default:
            cout << "\nNiepoprawna opcja.";
            break;
        }
    }

    for(int i = 0; i < N; ++i) {
        delete tabOsoby[i];
    }

    return 0;
}


void dodajOsobe(osoba** tabOsoby, string imie, string nazwisko, int indeks) {
    for (int i = 0; i < N; i++) {
        if (tabOsoby[i]->getNazwisko() == "") {
            tabOsoby[i]->setImie(imie);
            tabOsoby[i]->setNazwisko(nazwisko);
            tabOsoby[i]->setIndeks(indeks);
            cout << "\nDodano osobe do listy.";
            return; 
        }
    }
    cout << "\nBrak miejsca w tablicy.";
}

void ustawObecnosc(osoba** tabOsoby, bool* obecnosc, string nazwisko, bool stan) {
    for (int i = 0; i < N; i++) {
        if (tabOsoby[i]->getNazwisko() == nazwisko) {
            obecnosc[i] = stan;
            cout << "\nZaktualizowano obecnosc.";
            return;
        }
    }
    cout << "\nNie znaleziono osoby o takim nazwisku.";
}

void edytujOsobe(osoba** tabOsoby, int indeks) {
    for (int i = 0; i < N; i++) {
        if (tabOsoby[i]->getIndeks() == indeks && indeks != 0) {
            string t_str = "";
            cout << "Nowe imie: "; 
            cin >> t_str;
            tabOsoby[i]->setImie(t_str);
            cout << "Nowe nazwisko: "; 
            cin >> t_str;
            tabOsoby[i]->setNazwisko(t_str);
            cout << "Dane zaktualizowane.";
            return;
        }
    }
    cout << "\nOsoba o podanym indeksie nie istnieje.";
}

void usunOsobe(osoba** tabOsoby, bool* obecnosci, int indeks) {
    for (int i = 0; i < N; i++) {   
        if (tabOsoby[i]->getIndeks() == indeks && indeks != 0) {
            tabOsoby[i]->setImie("");
            tabOsoby[i]->setNazwisko("");
            tabOsoby[i]->setIndeks(0);
            obecnosci[i] = 0;
            cout << "\nOsoba zostala usunieta.";
            return;
        }
    }
    cout << "\nNie znaleziono osoby o takim indeksie.";
}

void wyswietlListe(osoba** tabOsoby, bool* obecnosc) {
    cout << "\n====================";
    for (int i = 0; i < N; i++) {
        if (tabOsoby[i]->getNazwisko() != "") {
            cout << "\n" << i + 1 << ". " << tabOsoby[i]->getIndeks() << " " << tabOsoby[i]->getImie() << " " << tabOsoby[i]->getNazwisko() << " " << (obecnosc[i] ? "TAK" : "NIE");
            return;
        }
    }
    cout << "\nLista jest pusta.";
    return;
}