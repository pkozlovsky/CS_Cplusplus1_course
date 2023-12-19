#include <iostream>
#include <string>
using namespace std;

class Osoba {
public:
    Osoba(const string& imie, const string& nazwisko, int wiek, int wzrost, const string& pesel, const string& kolorOczu)
        : imie(imie), nazwisko(nazwisko), wiek(wiek), wzrost(wzrost), pesel(pesel), kolorOczu(kolorOczu) {}

    void pokazDane() {
        cout << "Imię: " << imie << "\n";
        cout << "Nazwisko: " << nazwisko << "\n";
        cout << "Wiek: " << wiek << "\n";
        cout << "Wzrost: " << wzrost << "\n";
        cout << "PESEL: " << pesel << "\n";
        cout << "Kolor oczu: " << kolorOczu << "\n";
    }

    void setNazwisko(const string& noweNazwisko) {
        nazwisko = noweNazwisko;
    }
    void setImie(const string& noweImie) {
        imie = noweImie;
    }
    void setWiek(int nowyWiek) {
        wiek = nowyWiek;
    }

    void setWzrost(int nowyWzrost) {
        wzrost = nowyWzrost;
    }

    void setPesel(const string& nowyPesel) {
        pesel = nowyPesel;
    }

    void ustawKolorOczu(const string& nowyKolorOczu) {
        kolorOczu = nowyKolorOczu;
    }
private:
    string imie;
    string nazwisko;
    int wiek;
    int wzrost;
    string pesel;
    string kolorOczu;
};

int main() {
    Osoba osoba1("Piotr", "Kozłowski", 30, 180, "73021212345", "Niebieski");

    osoba1.pokazDane();
    osoba1.setImie("Paweł");
    osoba1.setNazwisko("Nowak");
    osoba1.setWiek(35);
    osoba1.setWzrost(175);
    osoba1.setPesel("79051098765");
    osoba1.ustawKolorOczu("Zielony");
    osoba1.pokazDane();

    return 0;
}
