using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8to10Version1
{
    class Program
    {
        static void Main(string[] args)
        {
            Shop obj = new Shop();

        }










        public static int getCountsOfDigits(long number)
        {
            return (number == 0) ? 1 : (int)Math.Ceiling(Math.Log10(Math.Abs(number) + 0.5));
        }

    }

    
}
