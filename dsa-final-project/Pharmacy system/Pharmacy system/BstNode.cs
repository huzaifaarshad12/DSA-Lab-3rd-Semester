using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pharmacy_system
{
    public class BSTNode
    {
        public MedicineInfo Medicine;
        public BSTNode Left;
        public BSTNode Right;

        public BSTNode(MedicineInfo medicine)
        {
            Medicine = medicine;
            Left = Right = null;
        }
    }
}
