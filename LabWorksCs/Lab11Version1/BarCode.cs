using System;
using System.IO;
using System.Collections.Generic;


namespace Identification // зробити статичний конструктор
{

    enum Product { JediStaff, LightSword, Spaceship, Weapon, R2_D2, Food, Pineapple, Orange, Apple, Potato }
    enum Technique { LightSword, Spaceship, Weapon, R2_D2 }
    enum Edible { Food, Pineapple, Orange, Apple, Potato }

    internal class Barcode
    {
        //public delegate bool setDefault();
        //public event setDefault switchDefault;

        private static Dictionary<Technique, int> mechanicStorage = new Dictionary<Technique, int>();
        //public int GetQuantityOfItemInMechanicStorage(Technique item) { return mechanicStorage[item]; }
        public static void IncreaseQuantityOfItemInMechanicStorage(Technique item) { mechanicStorage[item]++; }
        //public static void DecreaseQuantityOfItemInMechanicStorage(Technique item) { mechanicStorage[item]--; }

        private static Dictionary<Edible, int> edibleStorage = new Dictionary<Edible, int>();
        private static Dictionary<Product, int> Storage = new Dictionary<Product, int>();

        public static void GetAllProducts() 
        {
            foreach (var i in Storage)
                Console.WriteLine("{0, -20}: {1,-5}", i.Key, i.Value);
        }

        private Product type;
        public Product Type
        {
            get { return type; }
            set { type = value; }
        }
        private int code;
        public int Code
        {
            get { return code; }
            set { code = value; }
        }

        public bool IsDiscount;


        public override string ToString()
        {
            return type.ToString() + code.ToString();
        }

        public Barcode(Product type = Product.JediStaff, bool IsDiscount = false)
        {
            string a = type.ToString();
            if (System.Enum.IsDefined(typeof(Technique), a)) // якшо в техніку то шей в техніку добавимо
            {
                if (!mechanicStorage.ContainsKey((Technique)type))
                    mechanicStorage.Add((Technique)type, 1);
                else mechanicStorage[(Technique)type]++;
            }
            else if (System.Enum.IsDefined(typeof(Edible), a)) // якщо їстівне тоді в їстівну карту добавляємо
            {
                if (!edibleStorage.ContainsKey((Edible)type))
                    edibleStorage.Add((Edible)type, 1);
                else edibleStorage[(Edible)type]++;
            }

            if (!Storage.ContainsKey(type)) // полюбому всьо на склад добавляємо
                Storage.Add(type, 1);
            else Storage[type]++;

            this.type = type;
            this.IsDiscount = IsDiscount;
            Random rand = new Random();
            if (!this.IsDiscount) code = rand.Next(1000, 10000);
            else code = rand.Next(10001, 20001);
        }

        public void CreateDiscountCode()
        {
            Random rand = new Random();
            code = rand.Next(10001, 20001);
            IsDiscount = true;
        }
    }
}