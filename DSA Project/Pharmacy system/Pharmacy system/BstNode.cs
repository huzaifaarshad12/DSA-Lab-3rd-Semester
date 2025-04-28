namespace Pharmacy_system
{
    public class BSTNode
    {
        public MedicineInfo Medicine { get; set; }
        public BSTNode Left { get; set; }
        public BSTNode Right { get; set; }

        public BSTNode(MedicineInfo medicine)
        {
            Medicine = medicine;
        }
    }
}
