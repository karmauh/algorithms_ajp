//ĆW 1
//Napisz program, w którym utworzysz tablicę dynamiczną
//1-wymiarową, o rozmiarze podanym przez użytkownika. 
//Wypełnij tabelę wartościami losowymi z przedziału od -5 do +5. Wyświetl dane z tablicy. Usuń tablicę.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int rozmiar;
    cout << "Podaj rozmiar tablicy: ";
    cin >> rozmiar;
    int* tablica = new int[rozmiar];
  
    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = rand() % 11 - 5;
    }
  
    cout << "Zawartosc tablicy: ";
    for (int i = 0; i < rozmiar; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;
  
    delete[] tablica;
    return 0;
}


//ĆW 2
//Do zadania 11.1. dodaj zliczanie liczb ujemnych i wyświetlanie pozycji zera w tablicy.
    cout << "Liczba liczb ujemnych: " << licznikUjemnych << endl;
    if (pozycjaZera != -1) {
        cout << "Pozycja zera w tablicy: " << pozycjaZera << endl;
    }
    else {
        cout << "Brak zera w tablicy" << endl;
    }


//ĆW 3
//W programie utwórz tablicę dwuwymiarową 5x6. Wypełnij tablicę liczbami 0-10. Korzystając ze wskaźników:
//- wydrukuj tablicę,
//- zamień wartość w tablicy wskazaną przez użytkownika na nową,
//- ponownie wyświetl tablicę.
#include <iostream>
using namespace std;

int main() {
    const int ROW = 5;
    const int COL = 6;

    int array[ROW][COL];
    int* ptr = nullptr;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            array[i][j] = (i * COL) + j;
        }
    }

    cout << "Oryginalna tablica: " << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    int row, col;
    cout << "Wprowadz wiersz (0-4): ";
    cin >> row;
    cout << "Wprowadz kolumnę (0-5): ";
    cin >> col;

    if (row >= 0 && row < ROW && col >= 0 && col < COL) {
        int new_value;
        cout << "Wprowadz nową wartosc: ";
        cin >> new_value;

        ptr = &array[row][col];
        *ptr = new_value;

        cout << "Zaktualizowana tablica: " << endl;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Nieprawidlowy wiersz lub kolumna." << endl;
    }

    return 0;
}
