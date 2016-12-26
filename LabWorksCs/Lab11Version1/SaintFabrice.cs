using Staff;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SaintNicholas
{
    class SaintFabrice : Edem
    {
        public override BadThing MakeBadPresents(int number)
        {
            return new Food(10);
        }

        public override CoolThing MakeCoolPresents(int number)
        {
            return new Machinery(10);
        }
    }
}
