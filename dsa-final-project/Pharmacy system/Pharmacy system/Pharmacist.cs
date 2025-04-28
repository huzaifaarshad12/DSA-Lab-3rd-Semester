using System;

namespace Pharmacy_system
{
    public class Pharmacist
    {
        private Medicine medicine;
        private PriorityQueue orderQueue; // Internal priority queue for orders

        public Pharmacist()
        {
            medicine = new Medicine();
            orderQueue = new PriorityQueue(); // Initialize the priority queue internally
        }

        public string PharmacistMenu()
        {
            string choice;
            Console.WriteLine("\nPharmacist Menu:");
            Console.WriteLine("1. Add a Medicine");
            Console.WriteLine("2. Remove a Medicine");
            Console.WriteLine("3. Search for a Medicine");
            Console.WriteLine("4. Display Medicines");
            Console.WriteLine("5. Confirm Orders");
            Console.WriteLine("6. Back to Main Menu");
            Console.Write("Enter your choice: ");
            choice = Console.ReadLine();
            return choice;
        }

        public void AddMedicine()
        {
            Console.Write("Enter the name of the medicine to add: ");
            string name = Console.ReadLine();
            Console.Write("Enter the price of the medicine: ");
            double price = double.Parse(Console.ReadLine());
            Console.Write("Enter the quantity of the medicine: ");
            int quantity = int.Parse(Console.ReadLine());
            medicine.AddMedicine(name, price, quantity);
        }

        public void RemoveMedicine()
        {
            Console.Write("Enter the name of the medicine to remove: ");
            string name = Console.ReadLine();
            medicine.RemoveMedicine(name);
        }

        public void SearchMedicine()
        {
            Console.Write("Enter the name of the medicine to search: ");
            string name = Console.ReadLine();
            medicine.SearchMedicine(name);
        }

        public void DisplayMedicines()
        {
            medicine.DisplayMedicines();
            Console.ReadLine();
        }

        public void ConfirmOrders()
        {
            Console.WriteLine("\nProcessing Orders Based on Priority...");
            while (orderQueue.HasOrders())
            {
                var order = orderQueue.Dequeue(); // Get the highest-priority order
                if (medicine.IsMedicineAvailable(order.MedicineName, order.Quantity))
                {
                    medicine.DispenseMedicine(order.MedicineName, order.Quantity);
                    Console.WriteLine($"Order confirmed for {order.CustomerName}: {order.Quantity} units of {order.MedicineName}.");
                }
                else
                {
                    Console.WriteLine($"Order cannot be fulfilled for {order.CustomerName}: Insufficient stock of {order.MedicineName}.");
                }
            }
            Console.WriteLine("All orders processed.");
        }

        public void AddOrder(string customerName, string medicineName, int quantity, int priority)
        {
            orderQueue.Enqueue(customerName, medicineName, quantity, priority);
            Console.WriteLine($"Order added to the queue: {customerName}, {medicineName}, Quantity: {quantity}, Priority: {priority}");
        }
    }
}
