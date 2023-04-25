using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class NameComparer : IComparer<Osoba>
    {
        public int Compare(Osoba a, Osoba b)
        {
            return a.Ime[0].CompareTo(b.Ime[0]);
        }
    }
    
    public class SurnameComparer : IComparer<Osoba>
    {
        public int Compare(Osoba a, Osoba b)
        {
            return a.Prezime[0].CompareTo(b.Prezime[0]);
        }
    }

    public class BirthdayComparer : IComparer<Osoba>
    {
        public int Compare(Osoba a, Osoba b)
        {
            String[] rodjA = a.DatumRodjenja.Split(".");
            String[] rodjB = b.DatumRodjenja.Split(".");
            DateOnly date1 = new DateOnly(Int32.Parse(rodjA[2]), Int32.Parse(rodjA[1]), Int32.Parse(rodjA[0]));
            DateOnly date2 = new DateOnly(Int32.Parse(rodjB[2]), Int32.Parse(rodjB[1]), Int32.Parse(rodjB[0]));

            return date1.CompareTo(date2);
        }
    }
}
