using System;

namespace Pharmacy_system
{
    public class MedicineInfo
    {
        public string Name { get; set; }
        public double Price { get; set; }
        public int Quantity { get; set; }

        public MedicineInfo(string name, double price, int quantity)
        {
            Name = name;
            Price = price;
            Quantity = quantity;
        }

        public override string ToString()
        {
            return $"{Name}, Price: ${Price}, Quantity: {Quantity}";
        }
    }
}
