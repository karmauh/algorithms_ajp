using System;
using System.Collections.Generic;

public class Statystyki
{
    public static double SredniaArytmetyczna(List<double> liczby)
    {
        var suma = liczby.Sum();

        return liczby.Count > 0 ? suma / liczby.Count : 0;
    }

    public static double SredniaGeometryczna(List<double> liczby)
    {
        var iloczyn = liczby.Aggregate<double, double>(1, (current, liczba) => current * liczba);

        return liczby.Count > 0 ? Math.Pow(iloczyn, 1.0 / liczby.Count) : 0;
    }

    public static double SredniaWazona(List<(double wartosc, double waga)> dane)
    {
        double sumaWazona = 0, sumaWag = 0;
        foreach (var (wartosc, waga) in dane)
        {
            sumaWazona += wartosc * waga;
            sumaWag += waga;
        }

        return sumaWag != 0 ? sumaWazona / sumaWag : 0;
    }

    public static (double min, double max) MinMax(List<double> liczby)
    {
        if (liczby.Count == 0)
            return (0, 0);

        double min = liczby[0], max = liczby[0];

        foreach (var liczba in liczby)
        {
            if (liczba < min) min = liczba;
            if (liczba > max) max = liczba;
        }

        return (min, max);
    }

    public static double Mediana(List<double> liczby)
    {
        var posortowane = BubbleSort(new List<double>(liczby));
        var n = posortowane.Count;

        if (n == 0) return 0;

        return n % 2 == 0
            ? (posortowane[n / 2 - 1] + posortowane[n / 2]) / 2
            : posortowane[n / 2];
    }

    public static double Dominanta(List<double> liczby)
    {
        var czestosc = new Dictionary<double, int>();
        foreach (var liczba in liczby.Where(liczba => !czestosc.TryAdd(liczba, 1)))
        {
            czestosc[liczba]++;
        }

        var maxCzestosc = 0;
        var dominanta = liczby[0];

        foreach (var para in czestosc.Where(para => para.Value > maxCzestosc))
        {
            maxCzestosc = para.Value;
            dominanta = para.Key;
        }

        return dominanta;
    }

    private static List<double> BubbleSort(List<double> liczby)
    {
        var n = liczby.Count;
        for (var i = 0; i < n - 1; i++)
        {
            for (var j = 0; j < n - i - 1; j++)
            {
                if (liczby[j] > liczby[j + 1])
                {
                    (liczby[j], liczby[j + 1]) = (liczby[j + 1], liczby[j]);
                }
            }
        }
        return liczby;
    }
}
