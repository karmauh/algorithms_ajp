//ĆW 1 
//Napisz program, w którym utworzona zostanie pusta tablica 30-elementowa liczb całkowitych.
//W programie, za pomocą funkcji możliwe będzie (do wyboru z menu):
//- losowe wczytanie liczb do tablicy jednowymiarowej;
//- wyświetlenie elementów tablicy;
//- zsumowanie elementy tablicy;
//- sprawdzenie czy element podany przez użytkownika występuje w tablicy (wyświetlenie jego pozycji);
//- wyznaczenie elementu maksymalnego i minimalnego w tablicy;
//- uporządkowanie elementów rosnąco;
//- zliczenie elementów parzystych;
//- zliczenie elementów z przedziału od 2 do 5.
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int MAX = 30;

void wczytaj(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 100 + 1;
    }
}

void wyswietl(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

int zsumuj(int tab[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += tab[i];
    }
    return suma;
}

int znajdz(int tab[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (tab[i] == x) {
            return i;
        }
    }
    return -1;
}

void minmax(int tab[], int n, int& min, int& max) {
    min = max = tab[0];
    for (int i = 1; i < n; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
        if (tab[i] > max) {
            max = tab[i];
        }
    }
}

void sortuj(int tab[], int n) {
    sort(tab, tab + n);
}

int parzystych(int tab[], int n) {
    int parzyste = 0;
    for (int i = 0; i < n; i++) {
        if (tab[i] % 2 == 0) {
            parzyste++;
        }
    }
    return parzyste;
}

int przedzial(int tab[], int n) {
    int licznik = 0;
    for (int i = 0; i < n; i++) {
        if (tab[i] >= 2 && tab[i] <= 5) {
            licznik++;
        }
    }
    return licznik;
}

int main() {
    srand(time(0));
    int tab[MAX];
    int opcja, x, n = MAX;

    do {
        cout << "Menu: " << endl;
        cout << "1. Losowe wczytanie liczb" << endl;
        cout << "2. Wyświetlenie elementów tablicy" << endl;
        cout << "3. Zsumowanie elementów tablicy" << endl;
        cout << "4. Sprawdzenie czy element występuje w tablicy" << endl;
        cout << "5. Wyznaczenie elementu maksymalnego i minimalnego" << endl;
        cout << "6. Uporządkowanie elementów rosnąco" << endl;
        cout << "7. Zliczenie elementów parzystych" << endl;
        cout << "8. Zliczenie elementów z przedziału od 2 do 5" << endl;
        cout << "0. Koniec" << endl;
        cout << "Wybierz opcję: ";
        cin >> opcja;

        switch (opcja) {
        case 1:
            wczytaj(tab, n);
            break;
        case 2:
            wyswietl(tab, n);
            break;
        case 3:
            cout << "Suma elementów tablicy: " << zsumuj(tab, n) << endl;
            break;
        case 4:
            cout << "Podaj liczbę: ";
            cin >> x;
            int pos = znajdz(tab, n, x);
            if (pos != -1) {
                cout << "Liczba " << x << " występuje na pozycji " << pos << endl;
            }
            else {
                cout << "Liczby " << x << " nie ma w tablicy" << endl;
            }
            break;
        case 5:
            int min, max;
            minmax(tab, n, min, max);
            cout << "Element minimalny: " << min << endl;
            cout << "Element maksymalny: " << max << endl;
            break;
        case 6:
            sortuj(tab, n);
            cout << "Tablica posortowana rosnąco: ";
            wyswietl(tab, n);
            break;
        case 7:
            cout << "Liczba elementów parzystych: " << parzystych(tab, n) << endl;
            break;
        case 8:
            cout << "Liczba elementów z przedziału od 2 do 5: " << przedzial(tab, n) << endl;
            break;
        case 0:
            cout << "Koniec" << endl;
            break;
        default:
            cout << "Nieprawidłowy wybór opcji" << endl;
            break;
        }
    } while (opcja != 0);


    return 0;
}

//ĆW 2
//Napisz program, w którym wszystkie operacje opisane poniżej będą realizowane na tablicy 5x6,
//przy pomocy funkcji (2 sposób przekazywania tablicy do funkcji, z instrukcji do ćwiczeń).
//- losowe wczytanie elementów,
//- wyświetlenie tablicy,
//- wpisanie do drugiej tablicy (6-elementowej) sum kolumn,
//- wypisanie pozycji elementów ujemnych.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void loadRandomData(int tab[5][6]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            tab[i][j] = rand() % 100 + 1;
        }
    }
}

void displayTable(int tab[5][6]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << tab[i][j] << "\t";
        }
        cout << endl;
    }
}

void calculateColumnSums(int tab[5][6], int colSums[6]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            colSums[j] += tab[i][j];
        }
    }
}

void displayNegativePositions(int tab[5][6]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (tab[i][j] < 0) {
                cout << "Pozycja elementu ujemnego: (" << i << ", " << j << ")" << endl;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int tab[5][6];
    int colSums[6];

    loadRandomData(tab);
    displayTable(tab);
    calculateColumnSums(tab, colSums);
    displayNegativePositions(tab);

    return 0;
}
