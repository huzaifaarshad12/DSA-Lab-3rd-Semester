using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    internal class Program
    {
        static void Main(string[] args)
        {
            initializeMedicines();
            while (true)
            {
                Console.Clear();
                string option = startMenu();
                if (option == "1")
                {
                    Pharmacist pharmacist = new Pharmacist();
                    while (true)
                    {
                        Console.Clear();
                        string op = pharmacist.PharmacistMenu();
                        if (op == "1")
                        {
                            pharmacist.AddMedicine();
                        }
                        else if (op == "2")
                        {
                            pharmacist.RemoveMedicine();
                        }
                        else if (op == "3")
                        {
                            pharmacist.SearchMedicine();
                        }
                        else if (op == "4")
                        {
                            pharmacist.DisplayMedicines();
                        }
                        else if (op == "5")
                        {
                            pharmacist.ConfirmOrders();
                            Console.ReadLine();
                        }
                        else if (op == "6")
                        {
                            break;
                        }
                    }
                }
                else if (option == "2")
                {
                    Customer customer = new Customer();
                    while (true)
                    {
                        Console.Clear();
                        string op = customer.customerMenu();
                        if (op == "1")
                        {
                            customer.DisplayMedicines();
                        }
                        else if (op == "2")
                        {
                            customer.SearchMedicine();
                        }
                        else if (op == "3")
                        {
                            customer.PlaceOrder();
                        }
                        else if (op == "4")
                        {
                            customer.DisplayOrderQueue();
                        }
                        else if (op == "5")
                        {
                            break;
                        }
                    }
                }
                //else if (option == "3")
                //{
                //    Supplier supplier = new Supplier();
                //    supplier.supplierMenu();
                //}
                else if (option == "4")
                {
                    Environment.Exit(0);
                }
                else
                {
                    Console.WriteLine("Invalid option");
                }
            }
        }
        static string startMenu()
        {
            Console.WriteLine("Welcome to the Pharmacy System");
            Console.WriteLine("1. Pharmacist");
            Console.WriteLine("2. Customer");
            Console.WriteLine("3. Supplier");
            Console.WriteLine("4. Exit");
            Console.WriteLine("Please select an option: ");
            string option = Console.ReadLine();
            return option;
        }
        static void initializeMedicines()
        {
            Medicine medicine = new Medicine();
            medicine.AddMedicine("Paracetamol", 5.99, 100);
            medicine.AddMedicine("Ibuprofen", 7.99, 50);
            medicine.AddMedicine("Aspirin", 3.99, 75);
            medicine.AddMedicine("Cetirizine", 9.99, 25);
            medicine.AddMedicine("Loratadine", 8.99, 30);
            medicine.AddMedicine("Denzen ds", 6.99, 40);
            medicine.AddMedicine("Ciprofloxacin", 10.99, 20);
            medicine.AddMedicine("Amoxicillin", 11.99, 15);
            medicine.AddMedicine("Azithromycin", 12.99, 10);
            medicine.AddMedicine("Clarithromycin", 13.99, 5);
            medicine.AddMedicine("Doxycycl", 14.99, 5);
        }
    }
}
