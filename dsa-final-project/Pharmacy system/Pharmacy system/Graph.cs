using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class Graph
    { 
            private Dictionary<string, List<string>> adjacencyList;

            public Graph()
            {
                adjacencyList = new Dictionary<string, List<string>>();
            }

            // Add a medicine (vertex) to the graph
            public void AddMedicine(string medicineName)
            {
                if (!adjacencyList.ContainsKey(medicineName))
                {
                    adjacencyList[medicineName] = new List<string>();                    
                    
                }
            }

            // Add a relationship (edge) between two medicines
            public void AddRelation(string medicine1, string medicine2)
            {
                AddMedicine(medicine1);
                AddMedicine(medicine2);

                adjacencyList[medicine1].Add(medicine2);
                adjacencyList[medicine2].Add(medicine1); // Comment this line for directed graphs
            }

            // Check if a medicine exists in the graph
            public bool ContainsMedicine(string medicineName)
            {
                return adjacencyList.ContainsKey(medicineName);
            }

            // Check if a relationship exists between two medicines
            public bool HasRelation(string medicine1, string medicine2)
            {
                if (adjacencyList.ContainsKey(medicine1) && adjacencyList.ContainsKey(medicine2))
                {
                    return adjacencyList[medicine1].Contains(medicine2);
                }
                return false;
            }

            // Display all medicines and their relationships
            public void Display()
            {
                foreach (var medicine in adjacencyList)
                {
                    Console.WriteLine($"{medicine.Key}: {string.Join(", ", medicine.Value)}");
                }
            }

            // Perform BFS traversal starting from a given medicine
            public void BFS(string start)
            {
                if (!adjacencyList.ContainsKey(start))
                {
                    Console.WriteLine($"{start} does not exist in the graph.");
                    return;
                }

                var visited = new HashSet<string>();
                var queue = new Queue<string>();

                queue.Enqueue(start);
                visited.Add(start);

                Console.WriteLine("BFS Traversal:");
                while (queue.Count > 0)
                {
                    string medicine = queue.Dequeue();
                    Console.WriteLine(medicine);

                    foreach (var neighbor in adjacencyList[medicine])
                    {
                        if (!visited.Contains(neighbor))
                        {
                            queue.Enqueue(neighbor);
                            visited.Add(neighbor);
                        }
                    }
                }
            }

            // Perform DFS traversal starting from a given medicine
            public void DFS(string start)
            {
                if (!adjacencyList.ContainsKey(start))
                {
                    Console.WriteLine($"{start} does not exist in the graph.");
                    return;
                }

                var visited = new HashSet<string>();
                Console.WriteLine("DFS Traversal:");
                DFSRecursive(start, visited);
            }

            private void DFSRecursive(string medicine, HashSet<string> visited)
            {
                visited.Add(medicine);
                Console.WriteLine(medicine);

                foreach (var neighbor in adjacencyList[medicine])
                {
                    if (!visited.Contains(neighbor))
                    {
                        DFSRecursive(neighbor, visited);
                    }
                }
            }
        }
    }
