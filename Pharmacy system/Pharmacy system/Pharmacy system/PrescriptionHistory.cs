using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class PrescriptionHistory
    {
        private DoublyLinkedListNode head;
        private DoublyLinkedListNode tail;

        public void AddPrescription(string prescription)
        {
            DoublyLinkedListNode newNode = new DoublyLinkedListNode(prescription);
            if (head == null)
            {
                head = tail = newNode;
            }
            else
            {
                tail.Next = newNode;
                newNode.Prev = tail;
                tail = newNode;
            }
        }

        public void DisplayHistory()
        {
            DoublyLinkedListNode temp = head;
            while (temp != null)
            {
                Console.WriteLine(temp.Prescription);
                temp = temp.Next;
            }
        }

        public void DisplayHistoryReverse()
        {
            DoublyLinkedListNode temp = tail;
            while (temp != null)
            {
                Console.WriteLine(temp.Prescription);
                temp = temp.Prev;
            }
        }
    }
}
