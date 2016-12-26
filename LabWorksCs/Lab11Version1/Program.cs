using Identification;
using System.IO;
using Staff;
using System.Collections;
using System;
using SaintNicholas;

class EntryPoint
{
    static void Main(string[] args)
    {

        Children children = new Children(10);
        SaintNicol saintNicolas = SaintNicol.getNicol();


        IEnumerator enumerator = children.GetEnumerator();
        while(enumerator.MoveNext())
        {
            saintNicolas.sendPresent(((Child)(enumerator.Current)));
            Console.WriteLine(((Child)enumerator.Current).Machines.Size());
        }


    }
}

