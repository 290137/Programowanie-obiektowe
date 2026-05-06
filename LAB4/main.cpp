#include <iostream>
#include <string>

#define N 10
using namespace std;

//dodac klase student i stazysta które są specjalnymi przypadkami klasy osoba. numer indeksu dodac do studenta a id pracownika do stażysta
//dodaj metode drukuj ktora drukuje osobe i typ osoby

//zadanie domowe
//lista obecnosci musi zawierac studentow i stazystow. wprowadzanie do listy i studentow i stazystow jak i dodawanie ich do bazy
class osoba {
    private:
        string imie;
        string nazwisko;
    public:
        string getImie() {
            return imie;
        }

        string getNazwisko() {
            return nazwisko;
        }

        void setImie(string wartosc) {
            if (wartosc.length() >= 2) imie = wartosc;
            else imie = "";
        }

        void setNazwisko(string wartosc) {
            if (wartosc.length() >= 2) nazwisko = wartosc;
            else nazwisko = "";
        }

        virtual void drukuj() {
            cout << "OSOBA: " << getImie() << " " << getNazwisko();
        }

        osoba(string tImie, string tNazwisko) {
            setImie(tImie);
            setNazwisko(tNazwisko);
        }
};

class student: public osoba {
    private:
        int indeks;
    public:
        int getIndeks() {
            return indeks;
        }

        void setIndeks(int wartosc) {
            indeks = wartosc;
        }

        virtual void drukuj(){
            cout << "STUDENT: " << getImie() << " " << getNazwisko() << " " << getIndeks();
        }

        student(string tImie, string tNazwisko, int tIndeks) : osoba(tImie, tNazwisko) {
            setIndeks(tIndeks);
        }

        
};

class stazysta: public osoba {
    private:
        int id;
    public:
        int getId() {
            return id;
        }

        void setId(int wartosc) {
            id = wartosc;
        }

        virtual void drukuj() {
            cout << "STAZYSTA: " << getImie() << " " << getNazwisko() << " " << getId();
        }
        stazysta(string tImie, string tNazwisko, int tId) : osoba(tImie, tNazwisko) {
            setId(tId);
        }
};

class lista {
    private:
        osoba *tabOsobyLista[N];
        bool tabObecnoscLista[N];
    public:
    lista() {
            for (int i = 0; i < N; i++) {
                    tabOsobyLista[i] = nullptr;
                    tabObecnoscLista[i] = false;
                }
            }
            
        void wyswietlListe() {
            cout << "====================" << endl;
            bool czyPusta = true;
            for (int i = 0; i < N; i++) {
                if (tabOsobyLista[i] != nullptr) {
                    czyPusta = false;
                    cout << i + 1 << ". "; 
                    tabOsobyLista[i]->drukuj();
                    cout << (tabObecnoscLista[i] ? "TAK" : "NIE") << endl;
                }
            } 
            if (czyPusta) {
                cout << "Lista jest pusta." << endl;
            }
            return;
        }
        
        void dodajDoListy(osoba* osoba) {
            if (osoba == nullptr) return;
            
            for (int i = 0; i < N; i++) {
                if (tabOsobyLista[i] == nullptr) {
                    tabOsobyLista[i] = osoba;
                    tabObecnoscLista[i] = false;
                    cout << "Dodano do listy." << endl;
                    return; 
                }
            }
            cout << "Brak miejsca na liscie" << endl;
        }
    
        void usunZListy(string nazwisko) {
            for (int i = 0; i < N; i++) {
                if (tabOsobyLista[i] != nullptr && tabOsobyLista[i]->getNazwisko() == nazwisko) {
                    tabOsobyLista[i] = nullptr; 
                    tabObecnoscLista[i] = false;
                    cout << "Usunieto z listy." << endl;
                    return;
                }
            }
            cout << "Nie znaleziono osoby." << endl;
        }
    
        void ustawObecnosc(string nazwisko, bool obecnosc) {
            for (int i = 0; i < N; i++) {
                if (tabOsobyLista[i] != nullptr && tabOsobyLista[i]->getNazwisko() == nazwisko) {
                    tabObecnoscLista[i] = obecnosc;
                    cout << "Zmieniono obecnosc." << endl;
                    return;
                }
            }
            cout << "Nie znaleziono osoby." << endl;
        }
}; 

class interfejsUzytkownika {
    private:
        osoba **tablicaOsob;
        int iloscOsob;
        lista **tablicaList;
        int iloscList;

        void dodajOsobe(int typ, string imie, string nazwisko, int indeks, int id) {
            for (int i = 0; i < iloscOsob; i++) {
                if (tablicaOsob[i] == nullptr ) {
                    switch (typ)
                    {
                    case 1:
                        tablicaOsob[i] = new student(imie, nazwisko, indeks);
                        break;
                    case 2:
                        tablicaOsob[i] = new stazysta(imie, nazwisko, id);
                        break;
                    default:
                        tablicaOsob[i] = new osoba(imie, nazwisko);
                    }
                    cout << "Dodano osobe do bazy." << endl;
                    return; 
                }
            }
            cout << "Brak miejsca w bazie." << endl;
        }

        void dodajListe() {
            for (int i = 0; i < iloscList; i++) {
                if (tablicaList[i] == nullptr) { 
                    tablicaList[i] = new lista(); 
                    
                    cout << "Dodano liste nr " << i << " do bazy." << endl;
                    return;
                }
            }
            cout << "Brak miejsca w bazie." << endl;
        } 

        void edytujOsobe(string nazwisko) {
            for (int i = 0; i < iloscOsob; i++) {
                if (tablicaOsob[i] != nullptr && tablicaOsob[i]->getNazwisko() == nazwisko) {
                    string t_str = "";
                    cout << "Nowe imie: "; 
                    cin >> t_str;
                    tablicaOsob[i]->setImie(t_str);
                    cout << "Nowe nazwisko: "; 
                    cin >> t_str;
                    tablicaOsob[i]->setNazwisko(t_str);
                    cout << "Dane zaktualizowane." << endl;
                    return;
                }
            }
            cout << "Osoba nie istnieje." << endl;
        }

        void wyswietlOsobyWBazie() {
            cout << "====================" << endl;
            for (int i = 0; i < N; i++) {
                if (tablicaOsob[i] != nullptr) {
                    cout << i + 1 << ". ";
                    tablicaOsob[i]->drukuj(); 
                    cout << endl;

                }
            } 
            return;
        }
        

        osoba* znajdzOsobeWBazie(string nazwisko) {
            for (int i = 0; i < iloscOsob; i++) {
                if (tablicaOsob[i] != nullptr && tablicaOsob[i]->getNazwisko() == nazwisko) {
                    return tablicaOsob[i];
                }
            }
            return nullptr;
        }

    public:
        interfejsUzytkownika(osoba **tOsob, int iOsob, lista **tlist, int iList) {
            tablicaOsob = tOsob;
            iloscOsob = iOsob;
            tablicaList = tlist;
            iloscList = iList;
        }
        
        void loop() {
            int input = 0;
            int wybrana_lista = 0;
            string t_imie, t_nazwisko;
            int t_indeks, t_id, t_typ, t_lp;
            bool t_bool;

            while (input != -1) {
                cout << "====================" << endl;
                cout << "WYBRANA LISTA NR. " << wybrana_lista << endl;
                cout << "1. Dodaj osobe do bazy" << endl;
                cout << "2. Dodaj liste obecnosci do bazy" << endl;
                cout << "3. Wybierz liste z bazy" << endl;
                cout << "4. Dodaj osobe do listy nr. " << wybrana_lista << endl;
                cout << "5. Zmien obecnosc osoby na liscie nr. " << wybrana_lista << endl;
                cout << "6. Usun osobe z listy nr. " << wybrana_lista << endl;
                cout << "7. Edytuj dane osoby w bazie" << endl;
                cout << "8. Wyswietl liste nr. " << wybrana_lista << endl;
                cout << "9. Wyswietl wszystkie osoby w bazie" << endl;
                cout << "0. Zakoncz" << endl;
                cout << "Wybor: ";
                cin >> input;
                cout << endl;

                switch (input) {
                case 1:
                    cout << "Wprowadz imie: ";
                    cin >> t_imie;

                    cout << "Wprowadz nazwisko: ";
                    cin >> t_nazwisko;

                    cout << "Wprowadz typ osoby (1 - Student 2 - Stazysta): ";
                    cin >> t_typ;

                    if (t_typ == 1) {
                        cout << "Wprowadz indeks: ";
                        cin >> t_indeks;
                    } else if (t_typ == 2) 
                    {
                        cout << "Wprowadz id: ";
                        cin >> t_id;
                    }
                    dodajOsobe(t_typ, t_imie, t_nazwisko, t_indeks, t_id);
                    break;
                case 2:
                    dodajListe();
                    break;
                case 3:
                    cout << "Wybierz liste (nr. 0/ nr. 1): ";
                    cin >> t_lp;
                    if (t_lp == 0 || t_lp == 1) {
                        if (tablicaList[t_lp] != nullptr) {
                            wybrana_lista = t_lp;
                            cout << "Zmieniono liste na nr " << wybrana_lista << "." << endl;
                        } else {
                            cout << "Tablica nie istnieje." << endl;
                        }
                    } else {
                        cout << "Nieprawidlowy wybor." << endl;
                    }
                    break;
                case 4:
                    if (tablicaList[wybrana_lista] == nullptr) {
                        cout << "Lista nie istnieje." << endl;
                    } else {
                        cout << "Podaj nazwisko osoby do dodania: ";
                        cin >> t_nazwisko;
                        cout << endl;
                        
                        osoba* znalezionaOsoba = znajdzOsobeWBazie(t_nazwisko);
                        if (znalezionaOsoba != nullptr) {
                            tablicaList[wybrana_lista]->dodajDoListy(znalezionaOsoba);
                        } else {
                            cout << "Nie znaleziono osoby w bazie.." << endl;
                        }
                    }
                    break;
                case 5:
                    if (tablicaList[wybrana_lista] == nullptr) {
                        cout << "Lista nie istnieje." << endl;
                    } else {
                        cout << "Podaj nazwisko: ";
                        cin >> t_nazwisko;
                        cout << "Podaj obecnosc (0 / 1): ";
                        cin >> t_bool;
                        cout << endl;
                        tablicaList[wybrana_lista]->ustawObecnosc(t_nazwisko, t_bool);
                    }
                    break;
                case 6:
                    if (tablicaList[wybrana_lista] == nullptr) {
                        cout << "Lista nie istnieje." << endl;
                    } else {
                        cout << "Podaj nazwisko: ";
                        cin >> t_nazwisko;
                        cout << endl;
                        tablicaList[wybrana_lista]->usunZListy(t_nazwisko);
                    }
                    break;
                case 7:
                    cout << "Podaj nazwisko: ";
                    cin >> t_nazwisko;
                    cout << endl;
                    edytujOsobe(t_nazwisko);
                    break;
                case 8:
                    if (tablicaList[wybrana_lista] == nullptr) {
                        cout << "Lista nie istnieje." << endl;
                    } else {
                        tablicaList[wybrana_lista]->wyswietlListe();
                    }
                    break;
                case 9:
                    wyswietlOsobyWBazie();
                    break;
                case 0:
                    input = -1;
                    break;
                default:
                    cout << "Niepoprawna opcja." << endl;
                    break;
                }
            }
            
        }
};

int main(void) {
    osoba* tablicaOsob[N];
    for(int i = 0; i < N; i++) tablicaOsob[i] = nullptr;
    
    lista* tablicaList[2];
    for(int i = 0; i < 2; i++) tablicaList[i] = nullptr;

    interfejsUzytkownika ui(tablicaOsob, N, tablicaList, 2);
    ui.loop();

    return 0;
}