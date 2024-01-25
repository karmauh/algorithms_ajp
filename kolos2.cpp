#include <iostream>
#include <time.h>
#include <Windows.h>
using namespace std;

//zadanie1
float oblicz(float w, float h) {
	double bmi = w / (h * h);
	return bmi;
}

//zadanie2
int policz_delte(int a, int b, int c) {
    return b * b - 4 * a * c;
}

//zadanie3
void uzupelnij(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 21 - 5;
    }
}

void wyswietl(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int policz(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] >= 0 && arr[i] <= 5) {
            count++;
        }
    }
    return count;
}

void zamien(int arr[], int size, int number) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            arr[i] = number;
        }
    }
}

int main() {
    //zadanie1
    cout << "ZADANIE 1" << endl;
	float masa, wzrost;
	int wybor = 1;

	while (wybor) {
		cout << "Podaj mase:";
		cin >> masa;
		cout << "Podaj wzorst:";
		cin >> wzrost;
		float bmi = oblicz(masa, wzrost);
		cout << "Twoje bmi: " << bmi << endl;

		cout << "Czy chcesz obliczac dalej? (1-tak,0-nie):";
		cin >> wybor;
	}

    //-----------------------------------
    //zadanie3
    cout << "ZADANIE 3" << endl;
    const int size = 30;
    int tab[size];
    uzupelnij(tab, size);
    wyswietl(tab, size);
    cout << "Liczby z zakresu <0;5>: " << policz(tab, size) << endl;

    int liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;
    zamien(tab, size, liczba);
    wyswietl(tab, size);

    //-----------------------------------
    //zadanie2
    cout << "ZADANIE 2" << endl;
    int wsp[3][15];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 15; j++) {
            wsp[i][j] = rand() % 11 - 5;
        }
    }

    int delta[15];
    for (int i = 0; i < 15; i++) {
        delta[i] = 0;
    }

    for (int i = 0; i < 15; i++) {
        int a = wsp[0][i];
        int b = wsp[1][i];
        int c = wsp[2][i];
        delta[i] = policz_delte(a, b, c);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 15; j++) {
            cout << wsp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 15; i++) {
        cout << delta[i] << " ";
    }

    cout << endl;
    //-----------------------------------


	return 0;
}
