using PharmacySystem;
using System;
using System.Collections.Generic;

namespace Pharmacy_system
{
    public class Pharmacist
    {
        private Medicine medicine;
        private PriorityQueue orderQueue; // Internal priority queue for orders
        private PrescriptionHistory prescriptionHistory;
        public Pharmacist()
        {
            medicine = Medicine.Instance; // Use singleton instance of Medicine
            orderQueue = PriorityQueue.Instance;
            prescriptionHistory = PrescriptionHistory.Instance;
        }

        public string PharmacistMenu()
        {
            string choice;
            Console.WriteLine("\nPharmacist Menu:");
            Console.WriteLine("1. Add a Medicine");
            Console.WriteLine("2. Remove a Medicine");
            Console.WriteLine("3. Search for a Medicine");
            Console.WriteLine("4. Display Medicines");
            Console.WriteLine("5. Add order");
            Console.WriteLine("6. Confirm Orders");
            Console.WriteLine("7. Add Prescription of patient");
            Console.WriteLine("8. View Prescription of patient");
            Console.WriteLine("9. Display All Prescriptions");
            Console.WriteLine("10 Back to Main Menu");
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
            orderQueue.DisplayQueue();

            Console.WriteLine("Would you like to confirm any orders? (y/n)");
            string confirmChoice = Console.ReadLine();
            if (confirmChoice.ToLower() == "y")
            {
                while (orderQueue.HasOrders())
                {
                    var order = orderQueue.Dequeue(); // Get the highest-priority order
                    if (medicine.IsMedicineAvailable(order.MedicineName, order.Quantity))
                    {
                        // Assuming dispenseMedicine is a method to handle dispensing the medicine
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
            Console.WriteLine("Patient Name: ");
            string customerName = Console.ReadLine();
            Console.WriteLine("Medicine Name: ");
            string medicineName = Console.ReadLine();
            Console.WriteLine("Quantity: ");
            int quantity = int.Parse(Console.ReadLine());
            orderQueue.Enqueue(customerName, medicineName, quantity, 1);
            Console.WriteLine("Order added to queue.");
        }
    }
}
