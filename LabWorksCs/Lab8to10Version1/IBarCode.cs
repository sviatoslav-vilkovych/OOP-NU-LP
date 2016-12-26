using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8to10Version1
{
    interface IBarcode
    {
       Tuple<int,int,int> get_Barcode();
    }
}
