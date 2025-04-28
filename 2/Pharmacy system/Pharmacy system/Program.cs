using PharmacySystem;
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
            initializeGraph();
            initilizePrescriptions();
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
                            Console.ReadLine();
                        }
                        else if (op == "2")
                        {
                            pharmacist.RemoveMedicine();
                            Console.ReadLine();
                        }
                        else if (op == "3")
                        {
                            pharmacist.SearchMedicine();
                            Console.ReadLine();
                        }
                        else if (op == "4")
                        {
                            pharmacist.DisplayMedicines();
                        }
                        else if (op == "5")
                        {
                            pharmacist.AddOrder();
                            Console.ReadLine();
                        }
                        else if (op == "6")
                        {
                            pharmacist.ConfirmOrders();
                            Console.ReadLine();
                        }
                        else if (op == "7")
                        {
                            pharmacist.AddPrescription();
                            Console.ReadLine();
                        }
                        else if (op == "8")
                        {
                            pharmacist.ViewPrescription();
                            Console.ReadLine();
                        }
                        else if (op == "9")
                        {
                            pharmacist.DisplayAllPrescriptions();
                            Console.ReadLine();
                        }
                        else if (op == "10")
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
                        string op = customer.CustomerMenu();
                        if (op == "1")
                        {
                            customer.DisplayMedicines();
                            Console.ReadLine();
                        }
                        else if (op == "2")
                        {
                            customer.SearchMedicine();
                            Console.ReadLine();
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
                else if (option == "3")
                {
                    Supplier supplier = Supplier.Instance();
                    while (true)
                    {
                        Console.Clear();
                        string op = supplier.SupplierMenu();
                        if (op == "1")
                        {
                            supplier.AddSupplier();
                            Console.ReadLine();
                        }
                        else if (op == "2")
                        {
                            supplier.AddConnection();
                            Console.ReadLine();
                        }
                        else if (op == "3")
                        {
                            supplier.RemoveSupplier();
                            Console.ReadLine();
                        }
                        else if (op == "4")
                        {
                            supplier.RemoveConnection();
                        }
                        else if (op == "5")
                        {
                            supplier.DisplaySuppliers();
                        }
                        else if (op == "6")
                        {
                            supplier.DisplayShortestPath();
                        }
                        else if (op=="7")
                        {
                            break;
                        }
                    }
                }
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
            Medicine medicine = Medicine.Instance;
            medicine.AddMedicine("Paracetamol", 5.99, 100);
            medicine.AddMedicine("Ibuprofen", 7.99, 50);
            medicine.AddMedicine("Aspirin", 3.99, 75);
            medicine.AddMedicine("Cetirizine", 9.99, 25);
            medicine.AddMedicine("Loratadine", 8.99, 30);
            medicine.AddMedicine("Denzen ds", 6.99, 40);
        }
        static void initializeGraph()
        {
            Graph graph = Graph.Instance();

            // Add vertices (suppliers)
            graph.AddVertex("shalamar");
            graph.AddVertex("baghbanpura");
            graph.AddVertex("sultan pura");
            graph.AddVertex("garhi shahu");
            graph.AddVertex("station");
            graph.AddVertex("lari adda");
            graph.AddVertex("nadra office");
            graph.AddVertex("uet lahore");
            graph.AddVertex("mehmoood boti");
            graph.AddVertex("canal");

            // Add edges (connections with distances)
            graph.AddEdge("shalamar", "baghbanpura", 2);     // Distance: 5 km
            graph.AddEdge("baghbanpura", "sultan Pura", 1);  // Distance: 3 km
            graph.AddEdge("sultan Pura", "garhi shahu", 1);  // Distance: 7 km
            graph.AddEdge("garhi shahu", "station", 3); // Distance: 4 km
            graph.AddEdge("shalamar", "sultan pura", 6);     // Distance: 6 km
            graph.AddEdge("baghbanpura", "garhi shahu", 3);  // Distance: 8 km
            graph.AddEdge("uet lahore", "garhi shahu", 2); // Distance: 10 km
            graph.AddEdge("garhi shahu", "station", 5);       // Distance: 5 km
            graph.AddEdge("uet lahore", "nadra office", 4);    // Distance: 8 km
            graph.AddEdge("nadra office", "station", 3);       // Distance: 4 km
            graph.AddEdge("uet lahore", "lari adda", 4);        // Distance: 12 km
            graph.AddEdge("garhi shahu", "lari adda", 3);                // Distance: 6 km
        }
        static void initilizePrescriptions()
        {
            PrescriptionHistory prescriptionHistory = PrescriptionHistory.Instance;
            prescriptionHistory.AddPrescription("Ali","take bed rest for two days");
            prescriptionHistory.AddPrescription("Ali", "take medicine for two days");
            prescriptionHistory.AddPrescription("Ahmed", "check after 1 week");
        }
    }
}
