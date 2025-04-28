using System;
using System.Collections.Generic;

namespace Pharmacy_system
{
    public class PriorityQueue
    {
        private Queue<CustomerOrder> queue;
        private static PriorityQueue instance;
        private PriorityQueue()
        {
            queue = new Queue<CustomerOrder>();
        }
        public static PriorityQueue Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new PriorityQueue();
                }
                return instance;
            }
        }

        public void Enqueue(string customerName, string medicineName, int quantity, int priority)
        {
            var order = new CustomerOrder(customerName, medicineName, quantity, priority);
            if (queue.Count == 0 || priority < queue.Peek().Priority)
            {
                queue.Enqueue(order);
            }
            else
            {
                var tempQueue = new Queue<CustomerOrder>();
                while (queue.Count > 0 && queue.Peek().Priority <= priority)
                {
                    tempQueue.Enqueue(queue.Dequeue());
                }
                queue.Enqueue(order);
                while (tempQueue.Count > 0)
                {
                    queue.Enqueue(tempQueue.Dequeue());
                }
            }
        }

        public CustomerOrder Dequeue()
        {
            return queue.Count > 0 ? queue.Dequeue() : null;
        }

        public bool HasOrders()
        {
            return queue.Count > 0;
        }

        public List<CustomerOrder> GetOrders()
        {
            return new List<CustomerOrder>(queue);
        }

        public void DisplayQueue()
        {
            var orderList = GetOrders();
            int orderIndex = 1;
            foreach (var order in orderList)
            {
                Console.WriteLine($"{orderIndex}. {order.CustomerName}: {order.MedicineName}, Quantity: {order.Quantity}, Priority: {order.Priority}");
                orderIndex++;
            }
        }
    }
}
