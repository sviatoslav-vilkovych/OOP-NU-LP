using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8to10Version1
{
    class Good : IBarcode
    {
        static public Barcode uniqueBarcode;
        string strGoodsName;
        string strGoodsManufacturer;
        float fGoodsPrice;
        Barcode goodsBarCode;
        DateTime warrantyPeriod;

        public Good(Good obj)
        {
           // copy obj
        }
        public Good()
        {
            Console.WriteLine("Enter goods name: ");
            strGoodsName = Console.ReadLine();
            Console.WriteLine("Enter goods manufacturer: ");
            strGoodsManufacturer = Console.ReadLine();
            Console.WriteLine("Enter goods price: ");
            fGoodsPrice = float.Parse(Console.ReadLine());

            int intGoodsName = 0, intGoodsManufacturer = 0;

            goodsBarCode = new Barcode(intGoodsManufacturer, intGoodsName);
        }
        public Good(string strGoodsName, string strGoodsManufacturer, float fGoodsPrice)
        {
            this.strGoodsName = strGoodsName;
            this.strGoodsManufacturer = strGoodsManufacturer;
            this.fGoodsPrice = fGoodsPrice;
        }
        public Tuple<int, int, int> get_Barcode()
        {
            return goodsBarCode.get_Barcode();
        }
        public bool isAbleToReturn(DateTime date)
        {
            return ((warrantyPeriod < date) ? true : false);
        }

        public static Good operator+(Good ob1, Good ob2)
        {
            return new Good(ob1 + ob2);
        }
        public static Good operator-(Good ob1, Good ob2)
        {
            return new Good(ob1 - ob2);
        }
    }

}
