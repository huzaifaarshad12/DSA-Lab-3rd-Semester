using PharmacySystem;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class Stack
    {

    }
}
//public void DisplayShortestPaths(string startSupplier)
//{
//    if (!adjacencyList.ContainsKey(startSupplier))
//    {
//        Console.WriteLine($"Supplier {startSupplier} does not exist.");
//        return;
//    }

//    var shortestPaths = DijkstraAlgorithm.FindShortestPaths(adjacencyList, startSupplier);

//    Console.WriteLine($"\nShortest paths from {startSupplier}:");
//    foreach (var shortestPath in shortestPaths)
//    {
//        string supplier = shortestPath.Key;
//        int distance = shortestPath.Value;
//        string distanceText = distance == int.MaxValue ? "Infinity" : distance.ToString();
//        Console.WriteLine($"{supplier}: {distanceText}");
//    }

//}