using System;
using System.Collections.Generic;

namespace Pharmacy_system
{
    public class BST
    {
        public Node root;

        public void Insert(MedicineInfo medicine)
        {
            root = InsertRec(root, medicine);
        }

        private Node InsertRec(Node root, MedicineInfo medicine)
        {
            if (root == null)
            {
                root = new Node(medicine);
                return root;
            }

            if (medicine.Name.CompareTo(root.Medicine.Name) < 0)
                root.left = InsertRec(root.left, medicine);
            else if (medicine.Name.CompareTo(root.Medicine.Name) > 0)
                root.right = InsertRec(root.right, medicine);

            return root;
        }

        public bool Search(string name)
        {
            return SearchRec(root, name) != null;
        }

        private Node SearchRec(Node root, string name)
        {
            if (root == null || root.Medicine.Name == name)
                return root;

            if (root.Medicine.Name.CompareTo(name) < 0)
                return SearchRec(root.right, name);

            return SearchRec(root.left, name);
        }

        public Node SearchRecursive(Node root, string name)
        {
            if (root == null || root.Medicine.Name == name)
                return root;

            if (root.Medicine.Name.CompareTo(name) < 0)
                return SearchRecursive(root.right, name);

            return SearchRecursive(root.left, name);
        }

        public void Delete(string name)
        {
            root = DeleteRec(root, name);
        }

        private Node DeleteRec(Node root, string name)
        {
            if (root == null)
                return root;

            if (name.CompareTo(root.Medicine.Name) < 0)
                root.left = DeleteRec(root.left, name);
            else if (name.CompareTo(root.Medicine.Name) > 0)
                root.right = DeleteRec(root.right, name);
            else
            {
                // Node to be deleted found
                if (root.left == null)
                    return root.right;
                else if (root.right == null)
                    return root.left;

                root.Medicine = MinValue(root.right).Medicine;
                root.right = DeleteRec(root.right, root.Medicine.Name);
            }

            return root;
        }

        private Node MinValue(Node root)
        {
            Node current = root;

            while (current.left != null)
                current = current.left;

            return current;
        }

        public void DisplayInOrder()
        {
            InOrderRec(root);
        }

        private void InOrderRec(Node root)
        {
            if (root != null)
            {
                InOrderRec(root.left);
                Console.WriteLine($"Name: {root.Medicine.Name}, Price: {root.Medicine.Price}, Quantity: {root.Medicine.Quantity}");
                InOrderRec(root.right);
            }
        }

        public List<MedicineInfo> GetAllMedicines()
        {
            var medicines = new List<MedicineInfo>();
            InOrderStore(root, medicines);
            return medicines;
        }

        private void InOrderStore(Node root, List<MedicineInfo> medicines)
        {
            if (root != null)
            {
                InOrderStore(root.left, medicines);
                medicines.Add(root.Medicine);
                InOrderStore(root.right, medicines);
            }
        }
    }

    public class Node
    {
        public MedicineInfo Medicine;
        public Node left, right;

        public Node(MedicineInfo medicine)
        {
            Medicine = medicine;
            left = right = null;
        }
    }
}
