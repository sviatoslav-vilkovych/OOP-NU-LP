using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8to10Version1
{
    class LimitedGoods : Goods
    {
        DateTime date;  


        public bool isShelfLifeLeft(DateTime date)
        {
            return ((this.date <= date) ? true : false);
        }
    }
}
