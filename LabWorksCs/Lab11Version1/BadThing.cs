using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SaintNicholas
{
    abstract class BadThing
    {
        public void MakeCry()
        {
            Hurt();
        }
        public abstract string Hurt();

    }
}
