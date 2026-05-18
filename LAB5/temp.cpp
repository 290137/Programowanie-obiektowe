#include <iostream>
#include <string>

#define N 10
using namespace std;

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

         void drukuj() override {
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

        void drukuj() override {
            cout << "STAZYSTA: " << getImie() << " " << getNazwisko() << " " << getId();
        }
        stazysta(string tImie, string tNazwisko, int tId) : osoba(tImie, tNazwisko) {
            setId(tId);
        }
};

int main(void) {
    osoba* tablicaOsob[N];
    for(int i = 0; i < N; i++) tablicaOsob[i] = nullptr;

    tablicaOsob[0] = new osoba("Jan", "Kowalski");
    tablicaOsob[1] = new student("Janusz", "Nowak", 10002000);
    tablicaOsob[2] = new stazysta("Pawel", "Duda", 23);

    tablicaOsob[0]->drukuj();
    cout << endl;
    tablicaOsob[1]->drukuj();
    cout << endl;
    tablicaOsob[2]->drukuj();
    cout << endl;
    

    return 0;
}