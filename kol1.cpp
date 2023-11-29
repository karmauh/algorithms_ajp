#include <iostream>
#include <math.h>
using namespace std;

//zadanie 1
void obliczBMI() {
    double waga, wzrost, bmi;

    cout << "Podaj swoja wage (w kg): ";
    cin >> waga;

    cout << "Podaj swoj wzrost (w m): ";
    cin >> wzrost;

    bmi = waga / pow(2, wzrost);

    cout << "Twoje BMI wynosi: " << bmi << endl;

    if (bmi < 18.5) {
        cout << "ponizej normy" << endl;
    }
    else if (bmi >= 18.5 && bmi <= 25) {
        cout << "norma" << endl;
    }
    else if (bmi >= 25) {
        cout << "powyzej normy" << endl;
    }
}

int main() {
    //zadanie1
    char kontynuuj;

    do {
        obliczBMI();
        cout << "Czy chcesz obliczyc BMI ponownie? (t/n): ";
        cin >> kontynuuj;
    } while (kontynuuj == 't' || kontynuuj == 'T');

//zadanie 2
    int num;
    cout << "Wprowadz dodatnia liczbe: ";
    cin >> num;

    if (num <= 0) {
        cout << "Wprowadzona liczba nie jest dodatnia." << endl;
        return 0;
    }

    cout << "Dzielniki liczby " << num << " sa:" << endl;

    for (int i = 1; i <= num; i++)
        if (num % i == 0)
            cout << i << endl;
          
    return 0;
}
