/*
Zadanie 5.1 
  Napisz program który obliczy sumę n liczb naturalnych. Liczbę n oraz wszystkie składniki sumy podaje użytkownik.
Zadanie 5.2 
  Napisz program który policzy średnią 7 ocen studentów. Oceny studentów podaje kolejno użytkownik.
Zadanie 5.3 
  Napisz program który w kolejnych wierszach na ekranie wyświetli wartości n! dla wczytanej wartości n (n!=1*2*3*...*(n-1)*n). Wynikiem wykonania programu dla n = 8 powinno być:
Zadanie 5.4 
  Napisz program wyświetlający kolejne liczby całkowite od n do m. Liczby n i m podaje użytkownik.
Zadanie 5.5 
  Napisz program wyświetlający iloczyn kolejnych par liczb naturalnych od 1 do n (1*2 = 2, 2*3 = 6, 3*4=12 ....).
Zadanie 5.6 
  Napisz program wyświetlający w pierwszej kolumnie wartości od 1 n rosnąco a w drugiej malejąco. Przykładowo dla n=30 otrzymamy:
1 30
2 29
3 28
...
Zadanie 5.7
  Napisz program, w którym użytkownik po podaniu dowolnej liczby naturalnej może wybrać z MENU następującą operację:
a. Sprawdzenie czy liczba jest parzysta;
b. Sprawdzenie czy liczba jest podzielna przez inną – wskazaną przez użytkownika;
c. Wypisanie wszystkich dzielników liczby oraz określenie czy liczba jest liczbą pierwszą;
d. Wypisanie wszystkich dzielników liczby oraz sprawdzenie czy liczba jest doskonała.

Po wybraniu i wykonaniu jednej z operacji użytkownik ponownie wraca do MENU i może wybrać opcje 1-5
*/
#include <iostream>
using namespace std;

void zad51() {
    int n, suma = 0;
    cout << "Podaj liczbe liczb naturalnych: ";
    cin >> n;

    cout << "Podaj " << n << " liczb naturalnych: ";
    for (int i = 0; i < n; i++) {
        int liczba;
        cin >> liczba;

        suma += liczba;
    }

    cout << "Suma " << n << " liczb naturalnych wynosi: " << suma << endl;
}

void zad52() {
    double ocena, suma = 0;

    cout << "Podaj 7 ocen studentow: ";
    for (int i = 0; i < 7; i++) {
        cin >> ocena;
        suma += ocena;
    }

    double srednia = suma / 7;
    cout << "Srednia 7 ocen studentow wynosi: " << srednia << endl;
}

void zad53() {
    int n;
    cout << "Podaj liczbe naturalna n: ";
    cin >> n;

    cout << "n" << "\t" << "n!" << endl;
    cout << "---------------" << endl;

    long long faktoria = 1;

    for (int i = 1; i <= n; i++) {
        faktoria *= i;
        cout << i << "\t" << faktoria << endl;
    }
}

void zad54() {
    int n, m;
    
    cout << "Podaj liczbe n: ";
    cin >> n;
    cout << "Podaj liczbe m: ";
    cin >> m;

    if (n > m) {
        cout << "Liczba m nie moze byc mniejsza od liczby n" << endl;
        return;
    }

    for (int i = n; i <= m; i++) {
        cout << i << " ";
    }
}

void zad55() {
    int n;
    cout << "Podaj liczbe naturalna n: ";
    cin >> n;

    int iloczyn = 1;
    for (int i = 1; i <= n; i++) {
        iloczyn *= i;
        cout << i << " * " << i + 1 << " = " << iloczyn << endl;
    }
}

void zad56() {
    int n;
    cout << "Podaj liczbe naturalna n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << i << " " << n - i + 1 << endl;
    }
}

//zad57
bool isPrime(int liczba) {
    if (liczba <= 1) {
        return false;
    }
    for (int i = 2; i * i <= liczba; i++) {
        if (liczba % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPerfect(int liczba) {
    int suma = 1;
    for (int i = 2; i * i <= liczba; i++) {
        if (liczba % i == 0) {
            if (i * i != liczba) {
                suma = suma + i + liczba / i;
            }
            else {
                suma = suma + i;
            }
        }
    }
    return suma == liczba;
}

void findDivisors(int liczba) {
    cout << "Dzielniki liczby " << liczba << " sa:" << endl;
    for (int i = 1; i <= liczba / 2; i++) {
        if (liczba % i == 0) {
            cout << i << endl;
        }
    }
    cout << endl;
}

void zad57() {
    int liczba;
    cout << "Podaj liczbe naturalna n: ";
    cin >> liczba;

    while (true) {
        int wybor;
        cout << "1. Sprawdzenie czy liczba jest parzysta" << endl;
        cout << "2. Sprawdzenie czy liczba jest podzielna przez inna" << endl;
        cout << "3. Wypisanie wszystkich dzielnikow liczby oraz okreslenie czy liczba jest liczbą pierwsza" << endl;
        cout << "4. Wypisanie wszystkich dzielnikow liczby oraz sprawdzenie czy liczba jest doskonala" << endl;
        cout << "0. Zakonczenie programu" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
        case 1:
            if (liczba % 2 == 0) {
                cout << "Liczba " << liczba << " jest parzysta." << endl;
            }
            else {
                cout << "Liczba " << liczba << " jest nieparzysta." << endl;
            }
            break;
        case 2:
            int dzielnik;
            cout << "Podaj liczbe, przez ktora chcesz sprawdzic czy " << liczba << " jest podzielna: ";
            cin >> dzielnik;

            if (liczba % dzielnik == 0) {
                cout << "Liczba " << liczba << " jest podzielna przez " << dzielnik << "." << endl;
            }
            else {
                cout << "Liczba " << liczba << " nie jest podzielna przez " << dzielnik << "." << endl;
            }
            break;
        case 3:
            findDivisors(liczba);
            if (isPrime(liczba)) {
                cout << "Liczba " << liczba << " jest liczba pierwsza." << endl;
            }
            else {
                cout << "Liczba " << liczba << " nie jest liczba pierwsza." << endl;
            }
            break;
        case 4:
            findDivisors(liczba);
            if (isPerfect(liczba)) {
                cout << "Liczba " << liczba << " jest doskonala." << endl;
            }
            else {
                cout << "Liczba " << liczba << " nie jest doskonala." << endl;
            }
            break;
        case 0:
            return;
        default:
            cout << "Niepoprawna opcja!" << endl;
        }
    }
}

int main()
{
    cout << "Hello World!\n";
    //zad51();
    //zad52();
    //zad53();
    //zad54();
    //zad55();
    //zad56();
    zad57();
  
    return 0;
}
