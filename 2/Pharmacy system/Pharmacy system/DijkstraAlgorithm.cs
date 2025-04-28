using System;
using System.Collections.Generic;

namespace PharmacySystem
{
    public class DijkstraAlgorithm
    {
        public static (Dictionary<string, int> distances, Dictionary<string, string> predecessors) FindShortestPaths(
            Dictionary<string, List<(string, int)>> graph, string source)
        {
            var distances = new Dictionary<string, int>();
            var predecessors = new Dictionary<string, string>();
            var priorityQueue = new SortedSet<(int distance, string supplier)>();

            // Initialize distances and priority queue
            foreach (var vertex in graph.Keys)
            {
                distances[vertex] = int.MaxValue;
                predecessors[vertex] = null;
            }
            distances[source] = 0;
            priorityQueue.Add((0, source));

            while (priorityQueue.Count > 0)
            {
                var (currentDistance, currentSupplier) = priorityQueue.Min;
                priorityQueue.Remove(priorityQueue.Min);

                foreach (var (neighbor, weight) in graph[currentSupplier])
                {
                    int newDistance = currentDistance + weight;
                    if (newDistance < distances[neighbor])
                    {
                        priorityQueue.Remove((distances[neighbor], neighbor));
                        distances[neighbor] = newDistance;
                        predecessors[neighbor] = currentSupplier;
                        priorityQueue.Add((newDistance, neighbor));
                    }
                }
            }

            return (distances, predecessors);
        }

        public static List<string> GetPath(Dictionary<string, string> predecessors, string source, string destination)
        {
            var path = new List<string>();
            for (var current = destination; current != null; current = predecessors[current])
            {
                path.Insert(0, current);
            }
            return path[0] == source ? path : null; // Return path only if it starts from the source
        }
    }
}
