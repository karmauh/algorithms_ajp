using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;

public class IOHelper
{
    public static List<double> WczytajLiczbyZPliku(string sciezka)
    {
        var liczby = new List<double>();

        try
        {
            var linia = File.ReadAllText(sciezka);
            foreach (var item in linia.Split(' ', '\n', '\r'))
            {
                if (double.TryParse(item, NumberStyles.Any, CultureInfo.InvariantCulture, out var liczba))
                {
                    liczby.Add(liczba);
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Błąd podczas wczytywania pliku: {ex.Message}");
        }

        return liczby;
    }

    public static void ZapiszWynikDoPliku(string sciezka, string tresc)
    {
        try
        {
            File.WriteAllText(sciezka, tresc);
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Błąd podczas zapisu do pliku: {ex.Message}");
        }
    }
}
