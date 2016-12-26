using SaintNicholas;
using Staff;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SaintNicholas
{
    class SaintNicol
    {
        private static SaintNicol Nicol;
        private SaintNicol() { }

        public static SaintNicol getNicol()
        {
            if (Nicol == null)
                Nicol = new SaintNicol();
            return Nicol;
        }

        public void sendPresent(Child child)
        {
           Edem fabrica = new SaintFabrice();
            Random rand = new Random();
            if (child.BadDeeds > child.GoodDeeds)
                child.GetPresent(null, (Food)fabrica.MakeBadPresents(10));
            else child.GetPresent((Machinery)fabrica.MakeCoolPresents(10), null);
        }
    }
}
