using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Extensions
{
    public static class DateTimeExtensions
    {
        public static string ToFormattedString(this DateTime dateTime) 
        {
            return dateTime.ToString("dd.MM.yyyy");    
        }
    }

    public static class StringExtensions
    {
        public static String PostaviPrvoVelikoSlovo(this String s)
        {
            if (String.IsNullOrEmpty(s))
                return s;

            char[] charArray = s.ToCharArray();

            charArray[0] = Char.ToUpper(charArray[0]);

            for (int i = 1; i < charArray.Length; i++)
                charArray[i] = Char.ToLower(charArray[i]);


            String str;
            str = new String(charArray);

            return str;
        }

        public static DateTime toDateTime(this String s)
        {
            String[] values = s.Split('.');
            DateTime dt = new DateTime(Int32.Parse(values.ElementAt(0)),
                                       Int32.Parse(values.ElementAt(1)),
                                       Int32.Parse(values.ElementAt(2)));
            return dt;

        }
    }
}
