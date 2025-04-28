using System;
using System.Linq;

namespace PharmacySystem
{
    public class Supplier
    {
        private Graph supplierGraph; // Reference to the graph instance
        private static Supplier instance;

        private Supplier()
        {
            supplierGraph = Graph.Instance(); // Access the singleton instance of Graph
        }

        public static Supplier Instance()
        {
            if (instance == null)
            {
                instance = new Supplier();
            }
            return instance;
        }
        public string SupplierMenu()
        {
            Console.Clear();

            // Define menu content
            string[] menuLines = new string[]
            {
        "╔══════════════════════════════════════════════════╗",
        "║                  Supplier Menu                   ║",
        "╠══════════════════════════════════════════════════╣",
        "║  1. Add Supplier                                 ║",
        "║  2. Add Connection                               ║",
        "║  3. Remove Supplier                              ║",
        "║  4. Remove Connection                            ║",
        "║  5. Display Suppliers                            ║",
        "║  6. Display Shortest Path                        ║",
        "║  7. Back to Main Menu                            ║",
        "╚══════════════════════════════════════════════════╝",
        "", // Line spacing before the prompt
        "Choose an option: "
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

            // Calculate horizontal padding for center alignment
            int horizontalPadding = (consoleWidth - menuLines.Max(line => line.Length)) / 2;

            // Print each line of the menu centered horizontally
            foreach (string line in menuLines)
            {
                Console.WriteLine(line.PadLeft(horizontalPadding + line.Length));
            }

            // Set cursor position for input
            int promptPadding = (consoleWidth - "Choose an option: ".Length) / 2;
            Console.SetCursorPosition(promptPadding, Console.CursorTop);
            Console.Write(">> ");
            return Console.ReadLine();
        }

        public void AddSupplier()
        {
            Console.WriteLine("Enter supplier name");
            string supplierName = Console.ReadLine();
            supplierGraph.AddVertex(supplierName);
        }

        public void AddConnection()
        {
            Console.WriteLine("Enter distance between suppliers");
            int distance = int.Parse(Console.ReadLine());
            Console.WriteLine("Enter supplier name to connect from");
            string fromSupplier = Console.ReadLine();
            Console.WriteLine("Enter supplier name to connect to");
            string toSupplier = Console.ReadLine();
            supplierGraph.AddEdge(fromSupplier, toSupplier, distance);
        }

        public void RemoveSupplier()
        {
            Console.WriteLine("Enter supplier name to remove");
            string supplierName = Console.ReadLine();
            supplierGraph.RemoveVertex(supplierName);
            Console.ReadLine();
        }

        public void RemoveConnection()
        {
            string fromSupplier = Console.ReadLine();
            string toSupplier = Console.ReadLine();
            supplierGraph.RemoveConnection(fromSupplier, toSupplier);
            Console.ReadLine();
        }

        public void DisplaySuppliers()
        {
            supplierGraph.DisplayGraph();
            Console.ReadKey();
        }
        public void DisplayShortestPath()
        {
            Console.WriteLine("Enter the source supplier:");
            string source = Console.ReadLine();
            Console.WriteLine("Enter the destination supplier:");
            string destination = Console.ReadLine();
            supplierGraph.DisplayShortestPath(source, destination);
            Console.ReadKey();
        }
        
    }
}
