using System;

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

            Console.WriteLine("\nSupplier Menu:");
            Console.WriteLine("1. Add Supplier");
            Console.WriteLine("2. Add Connection");
            Console.WriteLine("3. Remove Supplier");
            Console.WriteLine("4. Remove Connection");
            Console.WriteLine("5. Display Suppliers");
            Console.WriteLine("6. Display Shortest Path");
            Console.WriteLine("7. Back to main menu");

            Console.Write("Choose an option: ");
            string input = Console.ReadLine();

            return input;
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
