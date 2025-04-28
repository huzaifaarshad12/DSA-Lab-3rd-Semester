using System;
using System.Collections.Generic;

namespace PharmacySystem
{
    public class Graph
    {
        private Dictionary<string, List<(string, int)>> adjacencyList;
        private static Graph instance; 
        private Graph()
        {
            adjacencyList = new Dictionary<string, List<(string, int)>>();
        }
        public static Graph Instance()
        {
            if (instance == null)
            {
                instance = new Graph();
            }
            return instance;
        }
        public void AddVertex(string supplier)
        {
            if (!adjacencyList.ContainsKey(supplier))
            {
                adjacencyList[supplier] = new List<(string, int)>();
                Console.WriteLine($"Supplier {supplier} added.");
            }
            else
            {
                Console.WriteLine($"Supplier {supplier} already exists.");
            }
        }
        public void AddEdge(string supplier1, string supplier2, int weight)
        {
            if (!adjacencyList.ContainsKey(supplier1) || !adjacencyList.ContainsKey(supplier2))
            {
                Console.WriteLine("Both suppliers must exist before adding an edge.");
                return;
            }

            adjacencyList[supplier1].Add((supplier2, weight));
            adjacencyList[supplier2].Add((supplier1, weight)); // For an undirected graph
            Console.WriteLine($"Connection added between {supplier1} and {supplier2} with distance {weight}.");
        }
        public void RemoveVertex(string supplier)
        {
            if (adjacencyList.ContainsKey(supplier))
            {
                adjacencyList.Remove(supplier);

                foreach (var key in adjacencyList.Keys)
                {
                    adjacencyList[key].RemoveAll(edge => edge.Item1 == supplier);
                }
                Console.WriteLine($"Supplier {supplier} removed.");
            }
            else
            {
                Console.WriteLine($"Supplier {supplier} does not exist.");
            }
        }
        public void DisplayGraph()
        {
            Console.WriteLine("\nSupplier Network:");
            foreach (var supplier in adjacencyList)
            {
                Console.Write($"{supplier.Key}: ");
                foreach (var edge in supplier.Value)
                {
                    Console.Write($" -> {edge.Item1} ({edge.Item2} km)");
                }
                Console.WriteLine();
            }
        }
        public List<string> GetAllSuppliers()
        {
            return new List<string>(adjacencyList.Keys);
        }
        public bool AreConnected(string supplier1, string supplier2)
        {
            if (!adjacencyList.ContainsKey(supplier1) || !adjacencyList.ContainsKey(supplier2))
                return false;

            foreach (var edge in adjacencyList[supplier1])
            {
                if (edge.Item1 == supplier2)
                    return true;
            }

            return false;
        }
        public void RemoveConnection(string supplier1, string supplier2)
        {
            if (!adjacencyList.ContainsKey(supplier1) || !adjacencyList.ContainsKey(supplier2))
            {
                Console.WriteLine("Both suppliers must exist before removing a connection.");
                return;
            }

            adjacencyList[supplier1].RemoveAll(edge => edge.Item1 == supplier2);
            adjacencyList[supplier2].RemoveAll(edge => edge.Item1 == supplier1);

            Console.WriteLine($"Connection removed between {supplier1} and {supplier2}.");
        }
        public void DisplayShortestPath(string source, string destination)
        {
            if (!adjacencyList.ContainsKey(source) || !adjacencyList.ContainsKey(destination))
            {
                Console.WriteLine("Both source and destination suppliers must exist.");
                return;
            }

            var (distances, predecessors) = DijkstraAlgorithm.FindShortestPaths(adjacencyList, source);
            var path = DijkstraAlgorithm.GetPath(predecessors, source, destination);

            if (path == null || distances[destination] == int.MaxValue)
            {
                Console.WriteLine($"No path exists between {source} and {destination}.");
                return;
            }

            Console.WriteLine($"The shortest path from {source} to {destination} is {distances[destination]} kilometers.");
            Console.WriteLine($"Path: {string.Join(" -> ", path)}");
        }
    }

}
