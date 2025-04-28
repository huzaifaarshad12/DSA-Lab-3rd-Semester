using System;
using System.Collections.Generic;
using System.Linq;

namespace Pharmacy_system
{
    public class Customer
    {
        private PriorityQueue orderQueue;

        public Customer()
        {
            orderQueue = PriorityQueue.Instance;// Initialize order queue
        }

        public string CustomerMenu()
        {
            string choice;

            // Get console dimensions
            int consoleWidth = Console.WindowWidth;
            int consoleHeight = Console.WindowHeight;

            // Prepare the menu content
            string[] menuLines = new string[]
            {
        "╔══════════════════════════════════════════════════╗",
        "║                                                  ║",
        "║                Customer Menu                     ║",
        "║                                                  ║",
        "╠══════════════════════════════════════════════════╣",
        "║  1. View Available Medicines                     ║",
        "║  2. Search for Medicine                          ║",
        "║  3. Place an Order                               ║",
        "║  4. View Orders in Priority                      ║",
        "║  5. Back to Main Menu                            ║",
        "║                                                  ║",
        "╚══════════════════════════════════════════════════╝",
        "",  // Line spacing before the prompt
        "Enter your choice: ",
        ""   // Line spacing after the prompt
            };

            // Calculate vertical padding for centering
            int verticalPadding = (consoleHeight - menuLines.Length) / 2;

            // Print vertical padding (blank lines)
            for (int i = 0; i < verticalPadding; i++)
            {
                Console.WriteLine();
            }

            // Calculate the horizontal padding for center alignment
            int horizontalPadding = (consoleWidth - menuLines.Max(line => line.Length)) / 2;

            // Print each line of the menu centered horizontally
            foreach (string line in menuLines)
            {
                Console.WriteLine(line.PadLeft(horizontalPadding + line.Length));
            }

            // Set cursor position for input
            int choicePromptPadding = (consoleWidth - "Enter your choice: ".Length) / 2;
            Console.SetCursorPosition(choicePromptPadding, Console.CursorTop);
            Console.Write(">> ");

            choice = Console.ReadLine();
            return choice;
        }


        public void DisplayMedicines()
        {
            Medicine medicine = Medicine.Instance; 
            medicine.DisplayMedicines();
            Console.ReadLine();
        }

        public void SearchMedicine()
        {
            Medicine medicine = Medicine.Instance;
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
