using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab8to10Version1
{
    class Goods : Good
    {
        private ArrayList goods;

        private class Iterator : IEnumerator
        {
            private Goods iGoods;
            private int current;
            public Iterator(Goods iGoods)
            {
                this.iGoods = iGoods;
                this.current = -1;
            }
            public object Current
            {
                get
                {
                    return iGoods.goods[current];
                }
            }
            public bool MoveNext()
            {
                ++current;
                return ((current < iGoods.goods.Count) ? true : false);
            }
            public void Reset()
            {
                current = -1;
            }

        }
        public IEnumerator GetEnumerator()
        {
            return new Iterator(this);
        }
        

        public Goods(int goodsCount = 1)
        {
            goods = new ArrayList();
            for(int i = 0; i < goodsCount;++i)
                goods.Add(new Good());
        }
        public Good this[int index]
        {
            get { return (Good)goods[index]; }
        }
        
       
    }
}
