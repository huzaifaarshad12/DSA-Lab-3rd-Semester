using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    internal class HashTable
    {
        private const int tablesize=100;
        private List<SupplierNode>[] table;


        public HashTable() 
        {
            // HashTable constructor
            table = new List<SupplierNode>[tablesize];
            for (int i = 0; i < tablesize; i++)
            {
                table[i] = new List<SupplierNode>();
            }
            
        }
        private int GetHash(string key)
        {
            // GetHash function
            int hash = 0;
            for (int i = 0; i < key.Length; i++)
            {
                hash += key[i];
            }
            return hash % tablesize;
        }
        public void Insert(SupplierNode node)
        {
            int index = GetHash(node.Name);
            table[index].Add(node);

        }
        public SupplierNode Search(string key)
        {
            int index = GetHash(key);
            foreach (SupplierNode node in table[index])
            {
                if (node.Name == key)
                {
                    return node;
                }
            }
            return null;
        }
        public void Delete(string key)
        {
            int index = GetHash(key);
            foreach (SupplierNode node in table[index])
            {
                if (node.Name == key)
                {
                    table[index].Remove(node);
                    return;
                }
            }
        }
        public void Display()
        {
            for (int i = 0; i < tablesize; i++)
            {
                foreach (SupplierNode node in table[i])
                {
                    Console.WriteLine(node.Name);
                }
            }
        }
        

        
    }
}
