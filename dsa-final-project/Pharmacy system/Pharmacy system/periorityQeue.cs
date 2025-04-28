using System;

namespace Pharmacy_system
{
    public class PriorityQueue
    {
        private QueueNode head;

        public void Enqueue(string customerName, string medicineName, int quantity, int priority)
        {
            QueueNode newNode = new QueueNode(customerName, medicineName, quantity, priority);

            if (head == null || priority < head.Priority)
            {
                newNode.Next = head;
                head = newNode;
            }
            else
            {
                QueueNode temp = head;
                while (temp.Next != null && temp.Next.Priority <= priority)
                {
                    temp = temp.Next;
                }
                newNode.Next = temp.Next;
                temp.Next = newNode;
            }
        }
        public QueueNode Dequeue()
        {
            if (head == null) return null;
            QueueNode temp = head;
            head = head.Next;
            return temp;
        }

        public bool HasOrders()
        {
            return head != null;
        }

        public void DisplayQueue()
        {
            if (head == null)
            {
                Console.WriteLine("No orders in the queue.");
                return;
            }

            QueueNode temp = head;
            while (temp != null)
            {
                Console.WriteLine($"Customer: {temp.CustomerName}, Medicine: {temp.MedicineName}, Quantity: {temp.Quantity}, Priority: {temp.Priority}");
                temp = temp.Next;
            }
        }
    }
}
