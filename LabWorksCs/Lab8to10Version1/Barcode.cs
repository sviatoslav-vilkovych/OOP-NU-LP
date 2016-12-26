using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8to10Version1
{
    class Barcode : IBarcode
    {
        int manufacturerCode;
        int goodsCode;

        int controlSum;

        public Barcode(int manufacturerCode, int goodsCode)
        {
            this.manufacturerCode = manufacturerCode;
            this.goodsCode = goodsCode;
            int manCodeForCtrlSum = 0, goodsCodeForCtrlSum = 0;

            int bits = Program.getCountsOfDigits(manufacturerCode);

            for (int i = 0; i < bits; i += 2) 
                manCodeForCtrlSum += Convert.ToInt32(manufacturerCode / (Math.Pow(10, bits-i)));
            bits = Program.getCountsOfDigits(goodsCode);
            for (int i = 1; i < bits; i += 2)
                goodsCodeForCtrlSum += Convert.ToInt32(goodsCode / (Math.Pow(10, bits - i)));

            controlSum = Math.Abs(goodsCodeForCtrlSum - manCodeForCtrlSum);
        }

        public Tuple<int, int, int> get_Barcode()
        {
            return Tuple.Create(manufacturerCode, goodsCode, controlSum);
        }

       
    }
}
