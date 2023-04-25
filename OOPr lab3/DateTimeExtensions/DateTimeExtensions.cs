namespace DateTimeExtensions
{
    public static class DateTimeExtensions
    {
        public static string ToFormattedString(this DateTime dateTime) 
        {
            return dateTime.ToString("dd.MM.yyyy HH:mm");    
        }
    }
}