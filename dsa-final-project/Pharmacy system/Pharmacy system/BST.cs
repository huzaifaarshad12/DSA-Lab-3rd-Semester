using System;

namespace Pharmacy_system
{
    public class BST
    {
        private BSTNode root;

        public void Insert(MedicineInfo medicine)
        {
            root = InsertRecursive(root, medicine);
        }

        private BSTNode InsertRecursive(BSTNode node, MedicineInfo medicine)
        {
            if (node == null)
                return new BSTNode(medicine);

            if (string.Compare(medicine.Name, node.Medicine.Name, StringComparison.Ordinal) < 0)
                node.Left = InsertRecursive(node.Left, medicine);
            else if (string.Compare(medicine.Name, node.Medicine.Name, StringComparison.Ordinal) > 0)
                node.Right = InsertRecursive(node.Right, medicine);

            return node;
        }

        public bool Search(string name)
        {
            return SearchRecursive(root, name) != null;
        }

        private BSTNode SearchRecursive(BSTNode node, string name)
        {
            if (node == null || node.Medicine.Name == name)
                return node;

            if (string.Compare(name, node.Medicine.Name, StringComparison.Ordinal) < 0)
                return SearchRecursive(node.Left, name);
            else
                return SearchRecursive(node.Right, name);
        }

        public void Delete(string name)
        {
            root = DeleteRecursive(root, name);
        }

        private BSTNode DeleteRecursive(BSTNode node, string name)
        {
            if (node == null)
                return node;

            if (string.Compare(name, node.Medicine.Name, StringComparison.Ordinal) < 0)
                node.Left = DeleteRecursive(node.Left, name);
            else if (string.Compare(name, node.Medicine.Name, StringComparison.Ordinal) > 0)
                node.Right = DeleteRecursive(node.Right, name);
            else
            {
                if (node.Left == null)
                    return node.Right;
                else if (node.Right == null)
                    return node.Left;

                node.Medicine = FindMin(node.Right).Medicine;
                node.Right = DeleteRecursive(node.Right, node.Medicine.Name);
            }

            return node;
        }

        private BSTNode FindMin(BSTNode node)
        {
            while (node.Left != null)
                node = node.Left;
            return node;
        }

        public void DisplayInOrder()
        {
            InOrderTraversal(root);
        }

        private void InOrderTraversal(BSTNode node)
        {
            if (node != null)
            {
                InOrderTraversal(node.Left);
                Console.WriteLine(node.Medicine);
                InOrderTraversal(node.Right);
            }
        }
    }
}
