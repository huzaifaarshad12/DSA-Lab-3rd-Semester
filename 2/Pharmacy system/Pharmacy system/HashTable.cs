using System;
using System.Collections.Generic;

namespace PharmacySystem
{
    public class HashTable
    {
        private class Node
        {
            public string Key { get; set; }
            public List<string> Prescriptions { get; set; }
            public Node Next { get; set; }

            public Node(string key, string prescription)
            {
                Key = key;
                Prescriptions = new List<string> { prescription };
                Next = null;
            }
        }

        private Node[] table;
        private int capacity;

        public HashTable(int capacity = 100)
        {
            this.capacity = capacity;
            table = new Node[capacity];
        }

        private int GetHash(string key)
        {
            int hash = 0;
            foreach (char c in key)
            {
                hash += c;
            }
            return hash % capacity;
        }

        public void AddPrescription(string patientID, string prescription)
        {
            int index = GetHash(patientID);
            Node currentNode = table[index];

            while (currentNode != null)
            {
                if (currentNode.Key == patientID)
                {
                    currentNode.Prescriptions.Add(prescription);
                    Console.WriteLine("Prescription added .");
                    return;
                }
                currentNode = currentNode.Next;
            }

            Node newNode = new Node(patientID, prescription);
            newNode.Next = table[index];
            table[index] = newNode;
            Console.WriteLine($"New patient {patientID} added with prescription: {prescription}");
        }

        public List<string> GetPrescriptions(string patientID)
        {
            int index = GetHash(patientID);
            Node currentNode = table[index];

            while (currentNode != null)
            {
                if (currentNode.Key == patientID)
                {
                    return currentNode.Prescriptions;
                }
                currentNode = currentNode.Next;
            }

            Console.WriteLine($"No prescriptions found for patient {patientID}");
            return null;
        }

        public void DisplayAllPrescriptions()
        {
            for (int i = 0; i < capacity; i++)
            {
                Node currentNode = table[i];
                while (currentNode != null)
                {
                    Console.WriteLine($"Patient {currentNode.Key}:");
                    foreach (var prescription in currentNode.Prescriptions)
                    {
                        Console.WriteLine($"  - {prescription}");
                    }
                    currentNode = currentNode.Next;
                }
            }
        }
    }
}
