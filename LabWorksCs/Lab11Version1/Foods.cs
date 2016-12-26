using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using Identification;
using SaintNicholas;

namespace Staff
{
    class Food : BadThing, Goods
    {
        //реалізація інтерфейсу IEnumerable

        public  IEnumerator GetEnumerator()
        {
            return new Iterator(this);
        }
        private class Iterator : IEnumerator
        {
            private Food food;
            private int current;
            public Iterator(Food food)
            {
                this.food = food;
                this.current = -1;
            }
            public void Reset()
            {
                current = -1;
            }
            public bool MoveNext()
            {
                ++current;
                if (current < food.foods.Count)
                    return true;
                else return false;
            }
            public object Current
            {
                get
                {
                    return food.foods[current];
                }
            }

        }
        // закінчення реалізації інтерфейсу

        private ArrayList foods;
        public Food(int quantity = 0)
        {
            foods = new ArrayList(quantity);
        }

        public  void Sort()
        {
            foods.Sort();
        }

        public void Add(Unit unit)
        {
            foods.Add(unit);
        }

        public  void loadGoodsFromFile(FileStream file)
        {
            file.Seek(0, SeekOrigin.Begin);
            StreamReader reader = new StreamReader(file);
            reader.ReadLine();
            while (!reader.EndOfStream)
            {
                string temp = reader.ReadLine();
                if (temp == "") break;
                string[] arr = new string[4];
                arr = temp.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries); // другий параметр потрібний щоб не було пробілів


                //можна тут запустити Thread щоб ще считувало для класу Їжа
                if (!Enum.IsDefined(typeof(Edible), arr[0])) continue;
                Unit unit = new Unit((Product)Enum.Parse(typeof(Product), arr[0]));
                unit.Info.Type = (Product)Enum.Parse(typeof(Product), arr[0]);
                unit.Info.Code = int.Parse(arr[1]);
                if (unit.Info.Code > 10000) unit.Info.IsDiscount = true;
                unit.Price = int.Parse(arr[2]);
                unit.Termin = uint.Parse(arr[3]);


                foods.Add(unit);
            }
            reader.Close(); //закрываем поток
            //Console.ReadLine();
        }

        public  Goods CreateGroupOfDiscont()
        {
            List<int> arr = new List<int>();
            Food dis_foods = new Food();
            bool PR = false;
            foreach (Unit unit in foods)
                if (unit.Info.IsDiscount)
                { PR = true; dis_foods.Add(unit); arr.Add(foods.IndexOf(unit)); }

            foreach (int unit in arr)
                foods.RemoveAt(unit);

            if (PR) return dis_foods;
            return null;
        }

        public override string Hurt()
        {
            return "Fuck u";
        }

        public int Size()
        {
            return foods.Count;
        }
    }
}
