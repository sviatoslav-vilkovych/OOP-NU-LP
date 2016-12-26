using Staff;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SaintNicholas
{
    class Child
    {
        public int GoodDeeds { get; protected set; }
        public int BadDeeds { get; protected set; }
        public Child()
        {
            Random rand = new Random();
            int good = 1 + (int)(rand.NextDouble() * 100000);
            int bad = 1 + (int)(rand.NextDouble() * 100000);
            GoodDeeds = good;
            BadDeeds = bad;
        }
        public void GetPresent(Machinery goodPresents, Food badPresents) { Machines = goodPresents; Foods = badPresents; }
        public Machinery Machines { get; set; }
        public Food Foods { get; set; }
    }
}
