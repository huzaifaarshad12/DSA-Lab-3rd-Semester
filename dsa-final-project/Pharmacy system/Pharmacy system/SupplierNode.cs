using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class SupplierNode
    {
        public string Name;
        public List<SupplierNode> Connections;

        public SupplierNode(string name)
        {
            Name = name;
            Connections = new List<SupplierNode>();
        }

        public void AddConnection(SupplierNode supplier)
        {
            Connections.Add(supplier);
        }
    }
}
