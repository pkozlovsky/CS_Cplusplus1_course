//Opis funkcjonalnosci:
// Napisz program który:
// a) pobierze liczbę z przedziału 4-24 reprezentującą sumę cyfr.
// b) będzie prosił uzytkownika o podanie liczby której suma cyfr jest równa liczbie z ptk a)
// liczby akceptowane w punkcie b) muszą spełniać warunek sumy cyfr,
// ponadto takie same liczby nie mogą być obok siebie, ale mogą być po przekątnej.
// (suma cyfr każdej z liczb musi być jednakowa i równa pierwszej zmiennej podanej)
// wynikiem działania programu ma być macierz wypełniona liczbami cyfrowymi
// np:
// wprowadzona liczba 6
// kolejne podane liczby:
// 105
// 123
// 402
// 123
// 321
// 222
// 312
// 204
// 600
// wynik działania programu:
// 105 123 402
// 123 321 222
// 312 204 600



#include <iostream> //biblioteka do obslugi wejsc/wyjsc
#include <random> //potrzebna do wygenerowania liczby losowej
using namespace std;

// funkcja pomocnicza obliczajaca sume cyfr podanej liczby:
class pomocnicze {
public:
    int obl_sume(int liczba)
    {
        int sum = 0;
        while (liczba != 0) {
            sum = sum + liczba % 10;
            liczba = liczba / 10;
        }
        return sum;
    }
};


int main()
{
    /*
    Porcje kodu do generowania liczby losowej podpatrzylem na stack overflow ;)
    */
    random_device rd;     // inicjalizacja "seed" dla generowania liczby lososwej
    mt19937 rng(rd());    // "silnik" Mersenne-Twister dla generowania liczby losowej
    uniform_int_distribution<int> uni(4,24); // rownomierny rozkad pradwopodobiesta, przedzial 4-24
    
    pomocnicze suma; //odwolanie sie do wczesniej zdefiniowanej funkcji

    auto liczba_losowa = uni(rng); //generowanie liczby losowej 
    cout << "wylosowana liczba to: " << liczba_losowa << endl;

    const int n {3}; //definicja rozmiaru tablicy
    int liczba_uzytkownika {0};      
    int tablica[n][n]{0}; //deklaracja i inicjalizacja tablicy (wszedzie zera)
    int counter {n*n-1}; //kosmetyczny licznik dla uzytkownika
    
    /*
    Ponizsza struktura to dwie petle for (druga zagniezdzona), ktore przechodza 
    przez tablice po kolei po elamentach zdefiniowanej tablicy nxn i sprawdzaja
    warunki poprawnosci liczby wprowadzonej przez uzytkownika. Jednym z warunkow 
    jest funkcja obl.sume sdefiniowana wyzej.

    Po wprowadzeniu poprawnej wartosci, liczba uzytkownika wprowadzona zostaje na odpowiednie miejsce
    tablicy. Tablica zostaje wyswietlona jako pomoc wizualna.
    */
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << "Podaj dowolna liczbe naturalna, ktorej suma cyfr jest rowna: " <<liczba_losowa<<endl;
            marker:
            cin >> liczba_uzytkownika;
            
            if(liczba_uzytkownika == tablica[i][j-1] && j != 0){

                cout<<"Blad! - ta liczba jest taka sama jak poprzednia.\nPodaj inna liczbe: "<<endl;
                
                goto marker;

            }else if(liczba_uzytkownika == tablica[i-1][j]){

                cout<<"Blad! - taka liczba znajduje sie rzad wyzej!\nPodaj inna liczbe: "<<endl;
                goto marker;

            }else if(liczba_losowa != suma.obl_sume(liczba_uzytkownika)){

                cout<<"Blad - suma cyfr nie zgadza sie!\nPodaj inna liczbe: "<<endl;
                goto marker;

            }else{
                tablica[i][j] = liczba_uzytkownika;
                cout<<"Pozostalo: "<<counter<<" elementow do wprowadzenia"<<endl;
                cout<<"Ok! Nastepny element."<<endl;
                counter = counter - 1;
                cout<<"##################"<<endl;
                for(int i = 0; i < 3; i++){
                    cout << tablica[i][0]<<"\t"<<tablica[i][1]<<"\t"<<tablica[i][2]<<endl;   
                    }
                cout<<"##################"<<endl;
                } 
        }       
    }
    /*
    Po uzupelnieniu tablicy poprawnymi liczbami zostaje wyswietlony wynik i pokrzepiajacy komunikat
    dla uzytkownika :)
    */
    cout<<"\n\n"<<endl;
    cout<<"BRAWO! Tablica uzupelniona: "<<endl; 
    cout<<"@@@@@@@@@@@@@@@@@@"<<endl;
    for(int i = 0; i < 3; i++){
        cout << tablica[i][0]<<"\t"<<tablica[i][1]<<"\t"<<tablica[i][2]<<endl;   
    }
    cout<<"@@@@@@@@@@@@@@@@@@"<<endl;
    
    return 0;
}


