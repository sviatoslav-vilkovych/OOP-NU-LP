using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Threading;
using Identification;
using SaintNicholas;

namespace Staff
{
    class Machinery : CoolThing, Goods
    {
        //реалізація інтерфейсу IEnumerable

        

        public     IEnumerator GetEnumerator()
        {
            return new Iterator(this);
        }
        private    class Iterator : IEnumerator
        {
            private Machinery machine;
            private int current;
            public Iterator(Machinery machine)
            {
                this.machine = machine;
                this.current = -1;
            }
            public void Reset()
            {
                current = -1;
            }
            public bool MoveNext()
            {
                ++current;
                if (current < machine.machines.Count)
                    return true;
                else return false;
            }
            public object Current
            {
                get
                {
                    return machine.machines[current];
                }
            }

        }
        // закінчення реалізації інтерфейсу




        private    ArrayList machines;

        public     Machinery(int quantity = 0)
        {
            machines = new ArrayList(quantity);
        }

        public     void Sort()
        {
            machines.Sort(); 
        }




        public     void Add(Unit unit)
        {
            machines.Add(unit);
        }


        public     void loadGoodsFromFile(FileStream file)
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


                //Thread thread = new Thread()
                //можна тут запустити Thread щоб ще считувало для класу Їжа
                if (!Enum.IsDefined(typeof(Technique), arr[0])) continue; 
                Unit unit = new Unit((Product)Enum.Parse(typeof(Product), arr[0]));
                //Unit unit = new Unit();
                unit.Info.Type = (Product)Enum.Parse(typeof(Product), arr[0]);
                unit.Info.Code = int.Parse(arr[1]);
                if (unit.Info.Code > 10000) unit.Info.IsDiscount = true;
                unit.Price = double.Parse(arr[2]);
                unit.Termin = double.Parse(arr[3]);


                machines.Add(unit);
            }
            reader.Close(); //закрываем поток
        }
        public     Goods CreateGroupOfDiscont()
        {
            List<int> arr = new List<int>(); // цей List буде зберігати номери unit які ми схочемо видалити
            Machinery dis_machines = new Machinery();
            bool PR = false;
            foreach (Unit unit in machines)
                if (unit.Info.IsDiscount)
                { PR = true; dis_machines.Add(unit); arr.Add(machines.IndexOf(unit));}
     
            foreach(int unit in arr)
                machines.RemoveAt(unit);

            if (PR) return dis_machines;
            return null;
        }

        public override string Love()
        {
            return "I love u! ";
        }

        public static Machinery operator *(Machinery m, Technique tech) // bad work
        {
            Machinery dis_machines = new Machinery();
            bool PR = false;
            foreach (Unit unit in m)
                if (unit.Info.Type == ((Product)tech))
                { PR = true; dis_machines.Add(unit); }

            if (PR) return dis_machines;
            return null;
        }

        public int Size()
        {
            return size;
        }
        public int size = 0;
  
    }
}
