using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SaintNicholas
{
    abstract class  CoolThing
    {
        public void MakeHappy()
        {
            Love();
        }
        public abstract string Love();
    }
}
