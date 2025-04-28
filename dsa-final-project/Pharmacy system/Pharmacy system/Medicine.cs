using System;
using System.Collections.Generic;

namespace Pharmacy_system
{
    public class Medicine
    {
        private Dictionary<string, MedicineInfo> medicines;

        public Medicine()
        {
            medicines = new Dictionary<string, MedicineInfo>();
        }

        public void AddMedicine(string name, double price, int quantity)
        {
            if (medicines.ContainsKey(name))
            {
                medicines[name].Quantity += quantity;
                Console.WriteLine($"Updated stock for {name}. New quantity: {medicines[name].Quantity}");
            }
            else
            {
                medicines[name] = new MedicineInfo(name, price, quantity);
                Console.WriteLine($"Added new medicine: {name}, Price: {price}, Quantity: {quantity}");
            }
        }

        public void RemoveMedicine(string name)
        {
            if (medicines.ContainsKey(name))
            {
                medicines.Remove(name);
                Console.WriteLine($"Removed medicine: {name}");
            }
            else
            {
                Console.WriteLine($"Medicine {name} does not exist.");
            }
        }

        public void SearchMedicine(string name)
        {
            if (medicines.ContainsKey(name))
            {
                var medicine = medicines[name];
                Console.WriteLine($"Medicine Found: {name}, Price: {medicine.Price}, Quantity: {medicine.Quantity}");
            }
            else
            {
                Console.WriteLine($"Medicine {name} is not available.");
            }
        }

        public void DisplayMedicines()
        {
            if (medicines.Count == 0)
            {
                Console.WriteLine("No medicines available.");
                return;
            }

            Console.WriteLine("Available Medicines:");
            foreach (var medicine in medicines.Values)
            {
                Console.WriteLine($"Name: {medicine.Name}, Price: {medicine.Price}, Quantity: {medicine.Quantity}");
            }
        }

        public bool IsMedicineAvailable(string name, int quantity)
        {
            return medicines.ContainsKey(name) && medicines[name].Quantity >= quantity;
        }

        public void DispenseMedicine(string name, int quantity)
        {
            if (IsMedicineAvailable(name, quantity))
            {
                medicines[name].Quantity -= quantity;
                Console.WriteLine($"Dispensed {quantity} units of {name}. Remaining stock: {medicines[name].Quantity}");
            }
            else
            {
                Console.WriteLine($"Cannot dispense {quantity} units of {name}. Insufficient stock.");
            }
        }
    }
}
