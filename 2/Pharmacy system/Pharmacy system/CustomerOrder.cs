using System;

namespace Pharmacy_system
{
    public class CustomerOrder
    {
        public string CustomerName { get; set; }
        public string MedicineName { get; set; }
        public int Quantity { get; set; }
        public int Priority { get; set; }

        public CustomerOrder(string customerName, string medicineName, int quantity, int priority)
        {
            CustomerName = customerName;
            MedicineName = medicineName;
            Quantity = quantity;
            Priority = priority;
        }
    }
}
