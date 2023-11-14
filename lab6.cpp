/*
Zadanie 6.1 
  Napisz program pobierający dane od użytkownika do tablicy, a następnie wypisujący jej zawartość (tablica 8-elementowa).
Zadanie 6.2 
  Napisz program obliczający sumę i średnią wszystkich liczb znajdujących się w tablicy 8-elementowej z zadania 6.1.
Zadanie 6.3 
  Napisz program generujący tablicę 15 elementową o wartościach z przedziału od -10 do +10, wyświetlający jej elementy oraz:
- obliczający sumę wszystkich liczb o indeksach parzystych znajdujących się w tablicy;
- obliczający sumę wszystkich liczb parzystych znajdujących się w tablicy;
- obliczający sumę wszystkich liczb ujemnych znajdujących się w tablicy;
- (*)generujący dwie dodatkowe tablice 15-elementowe, do których wpisane zostaną wartości z pierwszej tablicy z podziałem na dodatnie i ujemne.
Zadanie 6.4 
  dla dwóch tablic 10-elementowych obliczający w nowej tablicy sumy odpowiadających sobie elementów tablic.
Przykład:
t1=[1 3 4 2];
t2=[3 5 1 4];
Sumą tablic jest tablica: t3=[4 8 5 6]
Zadanie 6.5 
  Napisz program kopiujący zawartość jednej tablicy do drugiej w odwrotnej kolejności.
Przykład: t1=[1 3 4 2]
Wynik: t2=[2 4 3 1]
*/
#include <iostream>
using namespace std;

void zad61() {
    int tablica[8];

    for (int i = 0; i < 8; i++) {
        cout << "Podaj liczbe " << i + 1 << ": ";
        cin >> tablica[i];
    }

    cout << "Tablica: ";

    for (int i = 0; i < 8; i++) {
        cout << tablica[i] << " ";
    }
}

void zad62() {
    int tablica[8];
    int suma = 0;

    for (int i = 0; i < 8; i++) {
        cout << "Podaj liczbe " << i + 1 << ": ";
        cin >> tablica[i];
        suma += tablica[i];
    }

    cout << "Suma: " << suma << endl;
    cout << "Srednia: " << (double)suma / 8 << endl;
}

void zad63() {
    int tablica[15];
    int suma_dodatnich = 0;
    int suma_ujemnych = 0;

    for (int i = 0; i < 15; i++) {
        tablica[i] = (rand() % 21) - 10;
        cout << tablica[i] << " ";
        
        if (tablica[i] < 0) {
            suma_ujemnych += tablica[i];
        }
        else if (tablica[i] % 2 == 0) {
            suma_dodatnich += tablica[i];
        }
    }

    cout << endl;
    cout << "Suma wszystkich liczb o indeksach parzystych: " << suma_dodatnich << endl;
    cout << "Suma wszystkich liczb parzystych: " << suma_dodatnich + suma_ujemnych << endl;
    cout << "Suma wszystkich liczb ujemnych: " << suma_ujemnych << endl;
}

void zad64() {
    int t1[10], t2[10], t3[10];

    for (int i = 0; i < 10; i++) {
        cout << "Podaj element tablicy t1: ";
        cin >> t1[i];

        cout << "Podaj element tablicy t2: ";
        cin >> t2[i];
    }

    for (int i = 0; i < 10; i++) {
        t3[i] = t1[i] + t2[i];
    }

    cout << "Sumy tablic: ";

    for (int i = 0; i < 10; i++) {
        cout << t3[i] << " ";
    }
}

void zad65() {
    int t1[10], t2[10];

    for (int i = 0; i < 10; i++) {
        cout << "Podaj element tablicy t1: ";
        cin >> t1[i];
    }
    for (int i = 0; i < 10; i++) {
        t2[i] = t1[9 - i];
    }
    cout << "Tablica t2: ";
    for (int i = 0; i < 10; i++) {
        cout << t2[i] << " ";
    }
}

int main() {
    //zad61();
    //zad62();
    //zad63();
    //zad64();
    zad65();

    return 0;
}
