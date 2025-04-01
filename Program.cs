using System;
using System.Collections.Generic;
using System.Globalization;

class Program
{
    private static void Main(string[] args)
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;
        Console.WriteLine("=== Aplikacja statystyczna ===\n");

        // Tryb plikowy
        if (args.Length >= 2)
        {
            var sciezkaWejscia = args[0];
            var sciezkaWyjscia = args[1];

            Console.WriteLine("Tryb plikowy: Wczytywanie danych z pliku.");

            Console.WriteLine("Wybierz operację (1-5):");
            Console.WriteLine("1. Średnia arytmetyczna");
            Console.WriteLine("2. Średnia geometryczna");
            Console.WriteLine("3. Średnia ważona – nieobsługiwana w trybie plikowym");
            Console.WriteLine("4. Minimum i maksimum");
            Console.WriteLine("5. Mediana");

            Console.Write("Twój wybór: ");
            var wybor = Console.ReadLine();

            var liczbyZPliku = IOHelper.WczytajLiczbyZPliku(sciezkaWejscia);
            string wynik = "";

            switch (wybor)
            {
                case "1":
                    wynik = $"Średnia arytmetyczna: {Statystyki.SredniaArytmetyczna(liczbyZPliku):F2}";
                    break;
                case "2":
                    wynik = $"Średnia geometryczna: {Statystyki.SredniaGeometryczna(liczbyZPliku):F2}";
                    break;
                case "4":
                    var (min, max) = Statystyki.MinMax(liczbyZPliku);
                    wynik = $"Minimum: {min}, Maksimum: {max}";
                    break;
                case "5":
                    wynik = $"Mediana: {Statystyki.Mediana(liczbyZPliku):F2}";
                    break;
                default:
                    Console.WriteLine("Nieobsługiwana opcja lub brak wsparcia dla ważonej w trybie plikowym.");
                    return;
            }

            if (!string.IsNullOrWhiteSpace(sciezkaWyjscia))
            {
                IOHelper.ZapiszWynikDoPliku(sciezkaWyjscia, wynik);
                Console.WriteLine($"Wynik zapisany do pliku: {sciezkaWyjscia}");
            }
            else
            {
                Console.WriteLine(wynik);
            }

            return;
        }

        // Tryb interaktywny
        while (true)
        {
            Console.WriteLine("Wybierz operację:");
            Console.WriteLine("1. Średnia arytmetyczna");
            Console.WriteLine("2. Średnia geometryczna");
            Console.WriteLine("3. Średnia ważona");
            Console.WriteLine("4. Wartość minimalna i maksymalna");
            Console.WriteLine("5. Mediana");
            Console.WriteLine("6. Dominanta");
            Console.WriteLine("0. Wyjście");

            Console.Write("\nTwój wybór: ");
            var wybor = Console.ReadLine();

            switch (wybor)
            {
                case "1":
                    var lista1 = WczytajLiczby();
                    Console.WriteLine($"Średnia arytmetyczna: {Statystyki.SredniaArytmetyczna(lista1):F2}\n");
                    break;

                case "2":
                    var lista2 = WczytajLiczby();
                    Console.WriteLine($"Średnia geometryczna: {Statystyki.SredniaGeometryczna(lista2):F2}\n");
                    break;

                case "3":
                    var dane = WczytajLiczbyZWagami();
                    Console.WriteLine($"Średnia ważona: {Statystyki.SredniaWazona(dane):F2}\n");
                    break;

                case "4":
                    var lista4 = WczytajLiczby();
                    var (min, max) = Statystyki.MinMax(lista4);
                    Console.WriteLine($"Minimum: {min}, Maksimum: {max}\n");
                    break;

                case "5":
                    var lista5 = WczytajLiczby();
                    Console.WriteLine($"Mediana: {Statystyki.Mediana(lista5):F2}\n");
                    break;

                case "6":
                    var lista6 = WczytajLiczby();
                    Console.WriteLine($"Dominanta: {Statystyki.Dominanta(lista6)}\n");
                    break;

                case "0":
                    Console.WriteLine("Zamykanie programu...");
                    return;

                default:
                    Console.WriteLine("Nieprawidłowy wybór. Spróbuj ponownie.\n");
                    break;
            }
        }
    }

    static List<double> WczytajLiczby()
    {
        Console.WriteLine("Wprowadź liczby oddzielone spacją:");
        var input = Console.ReadLine();
        var liczby = new List<double>();

        foreach (var item in input.Split(' '))
        {
            if (double.TryParse(item, NumberStyles.Any, CultureInfo.InvariantCulture, out var liczba))
            {
                liczby.Add(liczba);
            }
        }

        return liczby;
    }

    static List<(double wartosc, double waga)> WczytajLiczbyZWagami()
    {
        var dane = new List<(double, double)>();

        Console.WriteLine("Podaj liczbę elementów:");
        var n = int.Parse(Console.ReadLine());

        for (var i = 0; i < n; i++)
        {
            Console.Write($"Wartość #{i + 1}: ");
            var wartosc = double.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

            Console.Write($"Waga #{i + 1}: ");
            var waga = double.Parse(Console.ReadLine(), CultureInfo.InvariantCulture);

            dane.Add((wartosc, waga));
        }

        return dane;
    }
}
