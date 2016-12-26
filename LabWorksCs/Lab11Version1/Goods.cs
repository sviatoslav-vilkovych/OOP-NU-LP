using System;
using Identification;
using System.Collections;
using System.IO;

namespace Staff
{
    interface Goods: IEnumerable   
    {

        
         void loadGoodsFromFile(FileStream file);


         Goods CreateGroupOfDiscont();

        new IEnumerator GetEnumerator();
        //public abstract void Sell();
        void Sort();

    }
}
