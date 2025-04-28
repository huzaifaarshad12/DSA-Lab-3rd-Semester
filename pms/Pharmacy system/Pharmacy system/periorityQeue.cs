using System;
using System.Collections.Generic;

namespace Pharmacy_system
{
    public class PriorityQueue
    {
        private List<CustomerOrder> queue;
        private static PriorityQueue instance;

        private PriorityQueue()
        {
            queue = new List<CustomerOrder>();
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
            int index = queue.FindIndex(o => o.Priority > priority);
            if (index == -1)
            {
                queue.Add(order);
            }
            else
            {
                queue.Insert(index, order);
            }
        }

        public CustomerOrder Dequeue()
        {
            if (queue.Count > 0)
            {
                var order = queue[0];
                queue.RemoveAt(0);
                return order;
            }
            return null;
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
            int orderIndex = 1;
            foreach (var order in queue)
            {
                Console.WriteLine($"{orderIndex}. {order.CustomerName}: {order.MedicineName}, Quantity: {order.Quantity}, Priority: {order.Priority}");
                orderIndex++;
            }
        }
    }
}
