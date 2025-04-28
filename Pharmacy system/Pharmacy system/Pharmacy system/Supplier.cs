using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class Supplier
    {
        public string Name;
        public List<Supplier> Connections;

        public Supplier(string name)
        {
            Name = name;
            Connections = new List<Supplier>();

        }

        public void AddConnection(Supplier supplier)
        {
            Connections.Add(supplier);
        }
        public void RemoveConnection(Supplier supplier)
        {
            Connections.Remove(supplier);
        }
        public void displayConnections()
        {
            foreach (Supplier supplier in Connections)
            {
                Console.WriteLine(supplier.Name);
            }
        }
        public Supplier findConnection(string name)
        {
            foreach (Supplier supplier in Connections)
            {
                if (supplier.Name == name)
                {
                    return supplier;
                }
            }
            return null;
        }

       
        
    }
}
