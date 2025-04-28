using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class QueueNode
    {
        public string CustomerName;
        public string MedicineName;
        public int Quantity;
        public int Priority;
        public QueueNode Next;

        public QueueNode(string customerName, string medicineName, int quantity, int priority)
        {
            CustomerName = customerName;
            MedicineName = medicineName;
            Quantity = quantity;
            Priority = priority;
            Next = null;
        }
    }
}
