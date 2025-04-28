using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class DoublyLinkedListNode
    {
        public string Prescription;
        public DoublyLinkedListNode Next;
        public DoublyLinkedListNode Prev;

        public DoublyLinkedListNode(string prescription)
        {
            Prescription = prescription;
            Next = Prev = null;
        }
    }
}
