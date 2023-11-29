/*
Napisz program:
Zadanie 7.1 wpisujący do tablicy 30-elementowej wartości z przedziału (-10;10)
Zadanie 7.2 ustawiający kolejność elementów z zad. 7.1. w odwrotnej kolejności. Użyj tylko jednej tablicy!
Zadanie 7.3 przeszukujący tablicę z zad. 7.1. – użytkownik podaje szukaną wartość, w odpowiedzi otrzymuje wszystkie jej pozycje lub informację o braku wartości w tablicy.
Zadanie 7.4 sortujący elementy tablicy z zadania 7.1. rosnąco lub malejąco. 
  Użyj tylko jednej tablicy. Wykorzystaj przynajmniej dwie metody sortowania.
Zadanie 7.5 obliczający częstość występowania podanej przez użytkownika wartości.
Zadanie 7.6 znajdujący największą i najmniejszą wartość z wszystkich liczb w tablicy 15 elementowej.
Zadanie 7.7 znajdujący w tablicy 100 elementowej częstości występowania wszystkich wartości. 
  Tablica ma zawierać liczby naturalne z przedziału <1;10>.
Obliczone częstości zapisz w drugiej tablicy – 10 elementowej.
Zadanie 7.8 wpisujący do dwóch tablic jednowymiarowych wartości podawane przez użytkownika. 
  Większe od g do pierwszej tablicy, mniejsze – do drugiej, a równe nie wpisuje do żadnej. Liczbę g też podaje użytkownik. Użytkownik podaje 15 wartości.
Zadanie 7.9 Wygeneruj tablicę przechowującą 100 liczb z przedziału (0, 200). 
  Znajdź miejsce w tablicy, w którym znajduje się najdłuższy rosnący podciąg. Wypisz numer elementu, który go rozpoczyna i ilość jego elementów.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//zadanie 7.3
void searchValue(int tablica[], int n, int searchValue) {
    vector<int> foundIndices;

    for(int i = 0; i < n; i++) {
        if(tablica[i] == searchValue) {
            foundIndices.push_back(i);
        }
    }

    if(foundIndices.empty()) {
        cout << "Nie znaleziono wartości " << searchValue << " w tablicy." << endl;
    } else {
        cout << "Znaleziono wartość " << searchValue << " na pozycjach: ";
        for(int i = 0; i < foundIndices.size(); i++) {
            cout << foundIndices[i] << " ";
        }
        cout << endl;
    }
}

//zadanie 7.4
void sortAndDisplay(int tablica[], int n, bool ascending) {
    if(ascending) {
        sort(tablica, tablica + n);
    } else {
        sort(tablica, tablica + n, greater<int>());
    }

    cout << "Posortowana tablica: ";
    for(int i = 0; i < n; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;
}

//zadanie 7.5
int findFrequency(int tablica[], int n, int value) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(tablica[i] == value) {
            count++;
        }
    }
    return count;
}

//zadanie 7.7
void countFrequencies(int tablica[], int n, int frequencies[]) {
    for(int i = 0; i < n; i++) {
        frequencies[tablica[i] - 1]++;
    }
}

//zadanie 7.8
void readArrays(int firstTab[], int secondTab[], int &n1, int &n2) {
    int value, g;

    cout << "Podaj wartosc g: ";
    cin >> g;

    cout << "Podaj 15 wartosci: ";

    for(int i = 0; i < 15; i++) {
        cin >> value;

        if(value > g) {
            firstTab[n1++] = value;
        } else if(value < g) {
            secondTab[n2++] = value;
        }
    }
}

//zadanie 7.9
void findLongestIncreasingSubsequence(std::vector<int> &tab, int &startIndex, int &length) {
    startIndex = 0;
    length = 1;

    for(int i = 1; i < tab.size(); i++) {
        if(tab[i] > tab[i-1]) {
            length++;
        } else {
            if(length > 1) {
                if(length > startIndex) {
                    startIndex = i - length;
                }
                break;
            }
        }
    }
}


int main() {
//zadanie 7.1, 7.2, 7.3, 7.4, 7.5
cout << "ZADANIE 7.1/2/3/4/5" << endl;
    int tablica[30];
    int n = 30;
    srand(time(0));

    for (int i = 0; i < n; i++) {
        tablica[i] = -10 + rand() % (10 - (-10) + 1);
    }

    for (int i = 0; i < n; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    reverse(tablica, tablica + n);

    for (int i = 0; i < n; i++) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    int searchValue2;
    cout << "Podaj wartosc, ktora chcesz wyszukac: ";
    cin >> searchValue2;
    searchValue(tablica, n, searchValue2);

    int sortingChoice;
    cout << "Podaj 1, jesli chcesz posortowac rosnaco, lub 2, jesli chcesz posortowac malejaco: ";
    cin >> sortingChoice;

    bool ascending = false;
    if(sortingChoice == 1) {
        ascending = true;
    }

    sortAndDisplay(tablica, n, ascending);

    int value;
    cout << "Podaj wartosc, ktorej czestosc wystepowania chcesz zobaczyc: ";
    cin >> value;

    int frequency = findFrequency(tablica, n, value);
    cout << "Czestosc wystepowania wartosci " << value << " wynosi: " << frequency << endl;


//zadanie 7.6
cout << endl;
cout << "ZADANIE 7.6" << endl;
    int tab[15];
    int x = 15;

    srand(time(0));
    for(int i = 0; i < x; i++) {
        tab[i] = -10 + rand() % (10 - (-10) + 1);
    }

    cout << "Tablica przed sortowaniem: ";
    for(int i = 0; i < x; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    sortAndDisplay(tab, x, ascending);

    int min = tab[0];
    int max = tab[0];
    for(int i = 0; i < x; i++) {
        if(tab[i] < min) {
            min = tab[i];
        }
        if(tab[i] > max) {
            max = tab[i];
        }
    }

    cout << "Najmniejsza wartosc: " << min << endl;
    cout << "Najwieksza wartosc: " << max << endl;


//zadanie 7.7
cout << endl;
cout << "ZADANIE 7.7" << endl;
    int tabb[100];
    int xx = 100;
    int frequencies[10];
    srand(time(0));

    for(int i = 0; i < xx; i++) {
        tabb[i] = 1 + rand() % (10 - 1 + 1);
    }

    cout << "Tablica przed sortowaniem: ";
    for(int i = 0; i < xx; i++) {
        cout << tabb[i] << " ";
    }
    cout << endl;

    sortAndDisplay(tabb, xx, ascending);
    countFrequencies(tabb, xx, frequencies);

    cout << "Czestosci wystepowania wszystkich wartosci: ";
    for(int i = 0; i < 10; i++) {
        cout << frequencies[i] << " ";
    }
    cout << endl;


//zadanie 7.8
cout << endl;
cout << "ZADANIE 7.8" << endl;
    int firstTab[15];
    int secondTab[15];
    int n1 = 0;
    int n2 = 0;

    readArrays(firstTab, secondTab, n1, n2);
    sortAndDisplay(firstTab, n1, ascending);
    sortAndDisplay(secondTab, n2, ascending);


//zadanie 7.9
cout << endl;
cout << "ZADANIE 7.9" << endl;
    vector<int> tab9(100);
    for(int i = 0; i < tab9.size(); i++) {
        tab9[i] = rand() % 201;
    }
    
    for(int i = 0; i < 100; i++) {
        cout << tab9[i] << " ";
    }
    cout << endl;

    int startIndex, length;
    findLongestIncreasingSubsequence(tab9, startIndex, length);

    cout << "Numer elementu rozpoczynajacego najdluzszy rosnacy podciag: " << startIndex << endl;
    cout << "Ilosc elementow w najdluzszym rosnacym podciagu: " << length << endl;


    return 0;
}
