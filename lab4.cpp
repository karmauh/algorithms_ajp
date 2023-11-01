/*
Zadanie 4.1
  Napisz program wypisujący wielokrotności podanej przez użytkownika liczby w zakresie do 1000.
Zadanie 4.2 
  Napisz program rozbudowujący program 2.3 z listy zadań Lab_2 o opcję 0 – koniec. 
  Program należy zapętlić tak, by powtarzał obliczenia, aż do momentu wybrania 0. 
Zadanie 4.3 
  Napisz program realizujący wypłatę reszty z automatu. 
  Program pobiera od użytkownika kwotę rachunku i kwotę wpłaconą, a następnie 
  przedstawia jakie banknoty / monety zostaną wydane jako reszta. 
  Przykładowo: rachunek: 140,55 zł wpłacono: 200 zł reszta: 50 zł, 5 zł, 2 zł, 2 zł, 0,20 zł, 0,20 zł, 0,05 zł
Zadanie 4.4 
  Napisz program realizujący grę „papier – kamień – nożyce” pomiędzy użytkownikiem i komputerem. 
  Użytkownik podaje swój wybór (papier – kamień – nożyce), a komputer losuje swoją odpowiedź. 
  Gra powinna mieć przynajmniej dwa tryby – do trzech zwycięstw i n-prób (n podaje użytkownik).
*/
#include <iostream>
#include <vector>
using namespace std;

void zad41() {
    int liczba;
    cout << "Podaj liczbe: ";
    cin >> liczba;

    for(int i=1; i<=1000; i++) {
        if(i % liczba == 0)
            cout << i << " ";
    }
  
    cout << endl;
}

void zad42() {
    int a, b;
    char wybor;

    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    cout << "Podaj +; -; *; /): ";
    cin >> wybor;

    while(wybor != 0) {
        switch (wybor) {
        case `+`:
            cout << "a+b: " << a+b << endl;
            break;
        case `-`:
            cout << "a-b: " << a-b << endl;
            break;
        case `*`:
            cout << "a*b: " << a*b << endl;
            break;
        case `/`:
            if(a == 0 or b == 0) {
                cout << "Nie dzielimy przez 0!";
                break;
            }
            cout << "a/b: " << a/b << endl;
            break;
        
        default:
            cout << "Zly wybor";
            break;
        }
    
        cout << "Podaj +; -; *; /):  ";
        cin >> wybor;
    }
}

void zad43() {
    double rachunek, wplacono;

    cout << "Podaj rachunek: ";
    cin >> rachunek;
    cout << "Podaj wplacona kwote: ";
    cin >> wplacono;

    double reszta = wplacono - rachunek;
    vector<double> nominaly = {500, 200, 100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.05, 0.02, 0.01};

    for (int i = 0; i < nominaly.size(); i++) {
        while (nominaly[i] <= reszta) {
            reszta -= nominaly[i];
            cout << nominaly[i] << " zl" << endl;
        }
    }

    return 0;
}

void zad44() {
    int uzytkownik_wygrane = 0, komputer_wygrane = 0;
    bool do_trzech_wygranych = false;
    int wybor, wygrane_do_wyboru, n;

    cout << "Wybierz tryb gry:\n"
        "1. Do trzech zwycięstw\n"
        "2. Do N gier (podaj N)" << endl;
    cin >> wybor;

    if(wybor == 1) {
        do_trzech_wygranych = true;
        wygrane_do_wyboru = 3;
    }
    else if(wybor == 2) {
        do_trzech_wygranych = false;
        cout << "Podaj ilość gier do rozegrania: ";
        cin >> n;
        wygrane_do_wyboru = n;
    }
    else {
        cout << "Niepoprawny wybór trybu gry.";
        return 1;
    }

    while (uzytkownik_wygrane < wygrane_do_wyboru && komputer_wygrane < wygrane_do_wyboru) {
        cout << "Podaj swoj wybor:\n"
            "(kamien - papier - nozyce)" << endl;
        string uzytkownik;
        cin >> uzytkownik;
         
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(0, 2);
        int komputer = dist(gen);

        string komputer_str;

        switch(komputer) {
        case 0:
            komputer_str = "papier";
            break;
        case 1:
            komputer_str = "kamien";
            break;
        case 2:
            komputer_str = "nozyce";
            break;
        }

        cout << "Uzytkownik: " << uzytkownik << endl;
        cout << "Komputer: " << komputer_str << endl;

        if (uzytkownik == komputer_str)
            cout << "Remis.";
        else if ((uzytkownik == "papier" && komputer_str == "kamien") ||
            (uzytkownik == "kamień" && komputer_str == "nozyce") ||
            (uzytkownik == "nożyce" && komputer_str == "papier")) {
            cout << "Uzytkownik wygral.";
            uzytkownik_wygrane++;
        }
        else {
            cout << "Komputer wygrywa!\n";
            komputer_wygrane++;
        }

        if (uzytkownik_wygrane > komputer_wygrane)
            cout << "Uzytkownik zwyciezyl w grze!";
        else
            cout << "Komputer zwyciezyl w grze!";

    }
    return 0;
}

int main() {

    zad41();
    zad42();
    zad43();
    zad44();

    reutrn 0;
}
