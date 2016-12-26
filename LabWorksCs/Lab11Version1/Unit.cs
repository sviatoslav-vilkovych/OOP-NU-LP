using System;
using System.IO;
using System.Collections.Generic;
using Identification;

namespace Staff
{
    internal class Unit : IComparable
    {
        public Unit(Product type = Product.JediStaff) { info = new Barcode(type); }

        Barcode info;
        public Barcode Info
        {
            get { return info; }
            set { info = value; }
        }

        double price;
        public double Price
        {
            get { return price; }
            set { price = value; }
        }

        double termin;
        public double Termin
        {
            get { return termin; }
            set { termin = value; }
        }

        public void PrintUnit()
        {
            Console.WriteLine("{0, -20} {1,-5} {2, 20}", info, Price, Termin);
        }

        public void MakeDiscount()
        {
            info.CreateDiscountCode();
        }

        int IComparable.CompareTo(object obj) 
        {
            if (obj == null) return 1;
            Unit otherUnit = obj as Unit;
            if (otherUnit != null)
                return this.price.CompareTo(otherUnit.price);
            else
                throw new ArgumentException("Object is not a Unit");
        }
    }

    
}