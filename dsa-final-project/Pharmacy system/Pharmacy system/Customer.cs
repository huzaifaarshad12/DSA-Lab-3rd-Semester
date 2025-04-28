using System;

namespace Pharmacy_system
{
    public class Customer
    {
        private PriorityQueue orderQueue;

        public Customer()
        {
            orderQueue = new PriorityQueue();
        }

        public string customerMenu()
        {
            string choice;
            
                Console.WriteLine("\nCustomer Menu:");
                Console.WriteLine("1. View Available Medicines");
                Console.WriteLine("2. Search for Medicine");
                Console.WriteLine("3. Place an Order");
                Console.WriteLine("4. View Orders in Priority");
                Console.WriteLine("5. Back to Main Menu");
                Console.Write("Enter your choice: ");
                choice = Console.ReadLine();
            return choice;
                
        }

        public void DisplayMedicines()
        {
            Medicine medicine = new Medicine();
            medicine.DisplayMedicines();
            Console.ReadLine();
        }

        public void SearchMedicine()
        {
            Medicine medicine = new Medicine();
            Console.Write("Enter the name of the medicine to search: ");
            string name = Console.ReadLine();
            medicine.SearchMedicine(name);
            Console.ReadLine();
        }

        public void PlaceOrder()
        {
            Console.Write("Enter your name: ");
            string customerName = Console.ReadLine();
            Console.Write("Enter the name of the medicine: ");
            string medicineName = Console.ReadLine();
            Console.Write("Enter the quantity: ");
            int quantity = int.Parse(Console.ReadLine());
            Console.Write("Enter the priority (1-5, where 1 is highest): ");
            int priority = int.Parse(Console.ReadLine());

            orderQueue.Enqueue(customerName, medicineName, quantity, priority);
            Console.WriteLine("Order placed successfully!");
            Console.ReadLine();
        }

        public void DisplayOrderQueue()
        {
            Console.WriteLine("\nOrders in Priority:");
            orderQueue.DisplayQueue();
            Console.ReadLine();
        }
    }
}
