using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class Graph
    {
        public HashTable hashTable;
        public Graph() 
        {
            hashTable = new HashTable();
        }
        public  void addSupplier(SupplierNode node)
        {
            hashTable.Insert(node);
        }
        public void AddConnection(SupplierNode node1, SupplierNode node2)
        {
            node1.AddConnection(node2);
            node2.AddConnection(node1);
        }
        public void RemoveConnection(SupplierNode node1, SupplierNode node2)
        {
            node1.Connections.Remove(node2);
            node2.Connections.Remove(node1);
        }
        public void RemoveSupplier(SupplierNode node)
        {
            hashTable.Delete(node.Name);
            foreach (SupplierNode n in hashTable.table[hashTable.GetHash(node.Name)])
            {
                n.Connections.Remove(node);
            }
        }
        public void displayConnections()
        {
            foreach (List<SupplierNode> list in hashTable.table)
            {
                foreach (SupplierNode node in list)
                {
                    Console.WriteLine(node.Name);
                    foreach (SupplierNode supplier in node.Connections)
                    {
                        Console.WriteLine(supplier.Name);
                    }
                }
            }
        }
        public SupplierNode findSupplier(string name)
        {
            return hashTable.Search(name);
        }
        public void displaySuppliers()
        {
            foreach (List<SupplierNode> list in hashTable.table)
            {
                foreach (SupplierNode node in list)
                {
                    Console.WriteLine(node.Name);
                }
            }
        }
        public void displayConnections(string name)
        {
            SupplierNode node = findSupplier(name);
            foreach (SupplierNode supplier in node.Connections)
            {
                Console.WriteLine(supplier.Name);
            }
        }
        public void displayConnections(SupplierNode node)
        {
            foreach (SupplierNode supplier in node.Connections)
            {
                Console.WriteLine(supplier.Name);
            }
        }uuuu
        /*public List<SupplierNode> Nodes;

        public Graph()
        {
            Nodes = new List<SupplierNode>();
        }

        public void AddNode(SupplierNode node)
        {
            Nodes.Add(node);
        }

        public void AddConnection(SupplierNode node1, SupplierNode node2)
        {
            node1.AddConnection(node2);
            node2.AddConnection(node1);
        }

        public void RemoveConnection(SupplierNode node1, SupplierNode node2)
        {
            node1.Connections.Remove(node2);
            node2.Connections.Remove(node1);
        }

        public void RemoveNode(SupplierNode node)
        {
            Nodes.Remove(node);
            foreach (SupplierNode n in Nodes)
            {
                n.Connections.Remove(node);
            }
        }
        public void displayConnections()
        {
            foreach (SupplierNode node in Nodes)
            {
                Console.WriteLine(node.Name);
                foreach (SupplierNode supplier in node.Connections)
                {
                    Console.WriteLine(supplier.Name);
                }
            }
        }
        public SupplierNode findNode(string name)
        {
            foreach (SupplierNode node in Nodes)
            {
                if (node.Name == name)
                {
                    return node;
                }
            }
            return null;
        }*/



    }
}
