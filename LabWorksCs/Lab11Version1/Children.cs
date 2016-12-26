    using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SaintNicholas
{
    class Children : IEnumerable
    {
        private ArrayList children;


        private class Iterator : IEnumerator
        {
            private Children childr;
            private int current;
            public Iterator(Children childr)
            {
                this.childr = childr;
                this.current = -1;
            }
            public object Current
            {
                get
                {
                    return childr.children[current];
                }
            }

            public bool MoveNext()
            {
                ++current;
                if (current < childr.children.Count)
                    return true;
                else return false;
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

        public Children(int childCount)
        {
            children = new ArrayList();
            for (int i = 0; i < childCount; i++)
                children.Add(new Child());
        }

        public Child this[int index]
        {
            get
            {
                return (Child)children[index];
            }
        }


    }
}
