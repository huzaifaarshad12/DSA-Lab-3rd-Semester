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
            Console.Clear();
            startInterface();
            Console.ReadLine();
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
            Console.Clear();

            // Define the menu content
            string[] menuLines = new string[]
            {
        "╔══════════════════════════════════════════════════╗",
        "║                                                  ║",
        "║          Welcome to the Pharmacy System          ║",
        "║                                                  ║",
        "╠══════════════════════════════════════════════════╣",
        "║    1. Pharmacist                                 ║",
        "║    2. Customer                                   ║",
        "║    3. Supplier                                   ║",
        "║                                                  ║",
        "║    4. Exit                                       ║",
        "╚══════════════════════════════════════════════════╝",
        "",  // Line spacing before the prompt
        "Please select an option: ",
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

            // Print each line of the menu centered horizontally
            foreach (string line in menuLines)
            {
                int horizontalPadding = (consoleWidth - line.Length) / 2;
                Console.WriteLine(new string(' ', horizontalPadding) + line);
            }

            // Display the input prompt centered
            int promptPadding = (consoleWidth - ">> ".Length) / 2;
            Console.SetCursorPosition(promptPadding, Console.CursorTop);
            Console.Write(">> ");
            return Console.ReadLine();
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
            graph.AddVertex("uet dispensery");
            graph.AddVertex("shalamar");
            graph.AddVertex("baghbanpura");
            graph.AddVertex("sultan pura");
            graph.AddVertex("garhi shahu");
            graph.AddVertex("station");
            graph.AddVertex("lari adda");
            graph.AddVertex("nadra office");
            graph.AddVertex("mehmoood boti");
            graph.AddVertex("canal");


            graph.AddEdge("uet dispensery", "shalamar", 4);
            graph.AddEdge("shalamar", "baghbanpura", 2);   
            graph.AddEdge("baghbanpura", "sultan Pura", 1);  
            graph.AddEdge("sultan Pura", "garhi shahu", 1); 
            graph.AddEdge("garhi shahu", "station", 3); 
            graph.AddEdge("shalamar", "sultan pura", 6);    
            graph.AddEdge("baghbanpura", "garhi shahu", 3);  
            graph.AddEdge("uet dispensery", "garhi shahu", 2); 
            graph.AddEdge("garhi shahu", "station", 5);  
            graph.AddEdge("uet dispensery", "nadra office", 4);  
            graph.AddEdge("nadra office", "station", 3);      
            graph.AddEdge("uet dispensery", "lari adda", 6);   
            graph.AddEdge("garhi shahu", "lari adda", 3);     
        }
        static void initilizePrescriptions()
        {
            PrescriptionHistory prescriptionHistory = PrescriptionHistory.Instance;
            prescriptionHistory.AddPrescription("Ali","take bed rest for two days");
            prescriptionHistory.AddPrescription("Ali", "take medicine for two days");
            prescriptionHistory.AddPrescription("Ahmed", "check after 1 week");
        }
        static void startInterface()
        {
            string[] art = new string[]
            {
        "______ _                                                               _                 ",
        "| ___ \\ |                                                             | |                ",
        "| |_/ / |__   __ _ _ __ _ __ ___   __ _  ___ _   _       ___ _   _ ___| |_ ___ _ __ ___  ",
        "|  __/| '_ \\ / _` | '__| '_ ` _ \\ / _` |/ __| | | |     / __| | | / __| __/ _ \\ '_ ` _ \\ ",
        "| |   | | | | (_| | |  | | | | | | (_| | (__| |_| |     \\__ \\ |_| \\__ \\ ||  __/ | | | | |",
        "\\_|   |_| |_|\\__,_|_|  |_| |_| |_|\\__,_|\\___|\\__, |     |___/\\__, |___/\\__\\___|_| |_| |_|",
        "                                              __/ |           __/ |                      ",
        "                                             |___/           |___/                       "
            };

            int screenWidth = Console.WindowWidth;    // Get console width
            int screenHeight = Console.WindowHeight;  // Get console height
            int topPadding = (screenHeight - art.Length) / 2; // Calculate top padding

            // Add vertical padding (empty lines)
            Console.Clear();
            for (int i = 0; i < topPadding; i++)
            {
                Console.WriteLine();
            }

            // Print the ASCII art centered horizontally
            foreach (string line in art)
            {
                int padding = (screenWidth - line.Length) / 2; // Calculate horizontal padding
                Console.WriteLine(new string(' ', padding) + line); // Print centered line
            }
        }
     }
}
