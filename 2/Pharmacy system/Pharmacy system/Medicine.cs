using System;
using System.Collections.Generic;

namespace Pharmacy_system
{
    public class Medicine
    {
        private static Medicine instance;
        private BST medicineBST;

        private Medicine()
        {
            medicineBST = new BST();
        }

        public static Medicine Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new Medicine();
                }
                return instance;
            }
        }

        public void AddMedicine(string name, double price, int quantity)
        {
            var medicine = new MedicineInfo(name, price, quantity);
            medicineBST.Insert(medicine);
            Console.WriteLine($"Added new medicine: {name}, Price: {price}, Quantity: {quantity}");
        }

        public void RemoveMedicine(string name)
        {
            medicineBST.Delete(name);
            Console.WriteLine($"Removed medicine: {name}");
        }

        public void SearchMedicine(string name)
        {
            if (medicineBST.Search(name))
            {
                Console.WriteLine($"Medicine {name} is available.");
            }
            else
            {
                Console.WriteLine($"Medicine {name} is not available.");
            }
        }

        public void DisplayMedicines()
        {
            Console.WriteLine("Available Medicines:");
            medicineBST.DisplayInOrder();
        }

        public bool IsMedicineAvailable(string name, int quantity)
        {
            if (medicineBST.Search(name))
            {
                var medicine = medicineBST.SearchRecursive(medicineBST.root, name);
                if (medicine.Medicine.Quantity >= quantity)
                {
                    return true;
                }
                else
                {
                    Console.WriteLine($"Medicine {name} is not available in required quantity.");
                    return false;
                }
            }
            else
            {
                Console.WriteLine($"Medicine {name} is not available.");
                return false;
            }
        }

        public void ConfirmOrders(PriorityQueue orderQueue)
        {
            Console.WriteLine("\nProcessing Orders Based on Priority...");
            while (orderQueue.HasOrders())
            {
                var order = orderQueue.Dequeue(); // Get the highest-priority order
                if (IsMedicineAvailable(order.MedicineName, order.Quantity))
                {
                    Console.WriteLine($"Order confirmed for {order.CustomerName}: {order.Quantity} units of {order.MedicineName}.");
                }
                else
                {
                    Console.WriteLine($"Order cannot be fulfilled for {order.CustomerName}: Insufficient stock of {order.MedicineName}.");
                }
            }
        }
        public void dispenseMedicine(string medicineName, int quantity)
        {
            var medicine = medicineBST.SearchRecursive(medicineBST.root, medicineName);
            if (medicine != null && medicine.Medicine.Quantity >= quantity)
            {
                medicine.Medicine.Quantity -= quantity;
                Console.WriteLine($"{quantity} units of {medicineName} dispensed successfully.");
            }
            else
            {
                Console.WriteLine($"Cannot dispense {medicineName}. Insufficient stock.");
            }
        }
    }
}
