using PharmacySystem;
using System;
using System.Collections.Generic;
using System.Linq;

namespace Pharmacy_system
{
    public class Pharmacist
    {
        private Medicine medicine;
        private PriorityQueue orderQueue;
        private PrescriptionHistory prescriptionHistory;
        public Pharmacist()
        {
            medicine = Medicine.Instance; 
            orderQueue = PriorityQueue.Instance;
            prescriptionHistory = PrescriptionHistory.Instance;
        }

        public string PharmacistMenu()
        {
            Console.Clear();

            // Define the menu content
            string[] menuLines = new string[]
            {
        "╔══════════════════════════════════════════════════╗",
        "║                                                  ║",
        "║                Pharmacist Menu                   ║",
        "║                                                  ║",
        "╠══════════════════════════════════════════════════╣",
        "║  1. Add a Medicine                               ║",
        "║  2. Remove a Medicine                            ║",
        "║  3. Search for a Medicine                        ║",
        "║  4. Display Medicines                            ║",
        "║  5. Add order                                    ║",
        "║  6. Confirm Orders                               ║",
        "║  7. Add Prescription of patient                  ║",
        "║  8. View Prescription of patient                 ║",
        "║  9. Display All Prescriptions                    ║",
        "║  10. Back to Main Menu                           ║",
        "║                                                  ║",
        "╚══════════════════════════════════════════════════╝",
        "",  // Line spacing before the prompt
        "Enter your choice: ",
        ""   // Line spacing after the prompt
            };

            // Get console dimensions
            int consoleWidth = Console.WindowWidth;
            int consoleHeight = Console.WindowHeight;

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

            // Display the input prompt centered
            int choicePromptPadding = (consoleWidth - "Enter your choice: ".Length) / 2;

            // Set cursor position for input
            Console.SetCursorPosition(choicePromptPadding, Console.CursorTop);
            Console.Write(">> ");
            return Console.ReadLine();
        }
        public void AddMedicine()
        {
            Console.Clear();  // Clear the console to refresh the view

            // Get console dimensions
            int consoleWidth = Console.WindowWidth;
            int consoleHeight = Console.WindowHeight;

            // Calculate vertical and horizontal padding for centering
            int verticalPadding = (consoleHeight - 11) / 2; // 11 lines for headers and message (including spacing)
            int horizontalPadding = (consoleWidth - 50) / 2; // 50 is an estimated length of the message line

            // Apply vertical padding
            for (int i = 0; i < verticalPadding; i++)
            {
                Console.WriteLine();
            }

            // Calculate the horizontal padding needed to center each message
            int horizontalOffset;

            // Display the message with horizontal padding
            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.WriteLine("╔══════════════════════════════════════════════════╗");
            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.WriteLine("║              Add Medicine to Inventory           ║");
            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.WriteLine("╠══════════════════════════════════════════════════╣");
            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.WriteLine(); // 2 lines spacing after header

            // Input prompts
            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.Write("Enter the name of the medicine to add: ");
            string name = Console.ReadLine();

            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.Write("Enter the price of the medicine: ");
            double price = double.Parse(Console.ReadLine());

            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.Write("Enter the quantity of the medicine: ");
            int quantity = int.Parse(Console.ReadLine());

            // Interact with the medicine list or inventory to add the medicine
            medicine.AddMedicine(name, price, quantity);

            // Confirmation message
            Console.WriteLine();
            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.WriteLine("Medicine added successfully!");

            // Prompt to return to the main menu
            Console.SetCursorPosition(horizontalPadding, Console.CursorTop);
            Console.WriteLine("Press any key to return to the Pharmacist Menu...");
            Console.ReadKey();
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
            orderQueue.DisplayQueue();

            Console.WriteLine("Would you like to confirm any orders? (y/n)");
            string confirmChoice = Console.ReadLine();
            if (confirmChoice.ToLower() == "y")
            {
                while (orderQueue.HasOrders())
                {
                    var order = orderQueue.Dequeue();
                    if (medicine.IsMedicineAvailable(order.MedicineName, order.Quantity))
                    {
                        medicine.dispenseMedicine(order.MedicineName, order.Quantity);
                        Console.WriteLine($"Order confirmed for {order.CustomerName}: {order.Quantity} units of {order.MedicineName}.");
                    }
                    else
                    {
                        Console.WriteLine($"Order cannot be fulfilled for {order.CustomerName}: Insufficient stock of {order.MedicineName}.");
                    }
                }
            }
            Console.WriteLine("All orders processed.");
        }
        public void AddPrescription()
        {
            Console.Write("Enter the patient ID: ");
            string patientID = Console.ReadLine();
            Console.Write("Prescription: ");
            string prescription = Console.ReadLine();
            prescriptionHistory.AddPrescription(patientID, prescription);
        }

        public void ViewPrescription()
        {
            Console.Write("Enter patient ID : ");
            string patientID = Console.ReadLine();
            List<string> prescriptions = prescriptionHistory.GetPrescriptions(patientID);
            if (prescriptions != null)
            {
                Console.WriteLine($"Prescriptions for patient {patientID}:");
                foreach (var prescription in prescriptions)
                {
                    Console.WriteLine($"- {prescription}");
                }
            }
            else
            {
                Console.WriteLine($"No prescriptions found for patient {patientID}");
            }
        }

        public void DisplayAllPrescriptions()
        {
            prescriptionHistory.DisplayAllPrescriptions();
        }
        public void AddOrder()
        {
            Console.Write("Patient Name: ");
            string customerName = Console.ReadLine();
            Console.Write("Medicine Name: ");
            string medicineName = Console.ReadLine();
            Console.Write("Quantity: ");
            int quantity = int.Parse(Console.ReadLine());
            orderQueue.Enqueue(customerName, medicineName, quantity, 1);
            Console.WriteLine("Order added to queue.");
        }
    }
}
