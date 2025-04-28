using Entity;
using System;
using System.Collections.Generic;
using System.Collections.Immutable;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PharmacySystem.Entity
{
    public class Doctor
    {
        private string ID;
        private string name;
        private ISortedList<Appointment> appointmentList;

        // Constructors
        public Doctor() : this("", "")
        {
        }

        public Doctor(string id, string name)
        {
            this.ID = id;
            this.name = name;
            this.appointmentList = new SortedDoublyLinkedList<Appointment>();
        }

        // Getters
        public string GetID()
        {
            return ID;
        }

        public string GetName()
        {
            return name;
        }

        public ISortedList<Appointment> GetAppointmentList()
        {
            return appointmentList;
        }

        // Setters
        public void SetID(string id)
        {
            this.ID = id;
        }

        public void SetName(string name)
        {
            this.name = name;
        }

        public void SetAppointmentList(ISortedList<Appointment> appointmentList)
        {
            this.appointmentList = appointmentList;
        }

        // Equals method
        public override bool Equals(object obj)
        {
            if (ReferenceEquals(this, obj))
                return true;

            if (obj == null || GetType() != obj.GetType())
                return false;

            Doctor other = (Doctor)obj;
            return string.Equals(this.ID, other.ID, StringComparison.Ordinal);
        }

        public override int GetHashCode()
        {
            return ID?.GetHashCode() ?? 0;
        }

        // ToString method
        public override string ToString()
        {
            return $"Doctor{{ID='{ID}', name='{name}', appointmentList={appointmentList}}}";
        }
    }

    /// <summary>
    /// Interface for a sorted list, similar to SortedListInterface in Java.
    /// </summary>
    public interface ISortedList<T> : IEnumerable<T> where T : IComparable<T>
    {
        void Add(T item);
        void Remove(T item);
        bool Contains(T item);
        int Count { get; }
    }

    /// <summary>
    /// Implementation of a sorted doubly linked list.
    /// </summary>
    /// <typeparam name="T"></typeparam>
    public class SortedDoublyLinkedList<T> : ISortedList<T> where T : IComparable<T>
    {
        private class Node
        {
            public T Data;
            public Node Next;
            public Node Previous;

            public Node(T data)
            {
                Data = data;
            }
        }

        private Node head;
        private int count;

        public void Add(T item)
        {
            Node newNode = new Node(item);

            if (head == null)
            {
                head = newNode;
            }
            else
            {
                Node current = head;
                Node previous = null;

                // Find correct position to insert
                while (current != null && current.Data.CompareTo(item) < 0)
                {
                    previous = current;
                    current = current.Next;
                }

                if (previous == null) // Insert at the head
                {
                    newNode.Next = head;
                    head.Previous = newNode;
                    head = newNode;
                }
                else
                {
                    previous.Next = newNode;
                    newNode.Previous = previous;

                    if (current != null)
                    {
                        current.Previous = newNode;
                        newNode.Next = current;
                    }
                }
            }

            count++;
        }

        public void Remove(T item)
        {
            Node current = head;

            while (current != null)
            {
                if (current.Data.Equals(item))
                {
                    if (current.Previous != null)
                    {
                        current.Previous.Next = current.Next;
                    }
                    else
                    {
                        head = current.Next;
                    }

                    if (current.Next != null)
                    {
                        current.Next.Previous = current.Previous;
                    }

                    count--;
                    return;
                }

                current = current.Next;
            }
        }

        public bool Contains(T item)
        {
            Node current = head;

            while (current != null)
            {
                if (current.Data.Equals(item))
                {
                    return true;
                }

                current = current.Next;
            }

            return false;
        }

        public int Count => count;

        public IEnumerator<T> GetEnumerator()
        {
            Node current = head;

            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        public override string ToString()
        {
            List<string> items = new List<string>();
            foreach (var item in this)
            {
                items.Add(item.ToString());
            }
            return string.Join(", ", items);
        }

    }
}
