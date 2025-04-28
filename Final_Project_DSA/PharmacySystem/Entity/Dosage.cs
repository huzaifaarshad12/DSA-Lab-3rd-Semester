using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PharmacySystem.Entity
{
    public class Dosage : IComparable, ICloneable
    {
        // Data members
        private string dosageForm;
        private string dose;
        private int dosageQuantity;
        private double dosageCost;
        private double dosagePrice;
        private MedicineDosageRecord record;

        // Default constructor
        public Dosage() { }

        // Constructor with parameters
        public Dosage(string dosageForm, string dose, int dosageQuantity, double dosageCost, double dosagePrice)
        {
            this.dosageForm = dosageForm;
            this.dose = dose;
            this.dosageQuantity = dosageQuantity;
            this.dosageCost = dosageCost;
            this.dosagePrice = dosagePrice;
            this.record = new MedicineDosageRecord(0, 0);
        }

        // Constructor with record
        public Dosage(string dosageForm, string dose, int dosageQuantity, double dosageCost, double dosagePrice, MedicineDosageRecord record)
        {
            this.dosageForm = dosageForm;
            this.dose = dose;
            this.dosageQuantity = dosageQuantity;
            this.dosageCost = dosageCost;
            this.dosagePrice = dosagePrice;
            this.record = record;
        }

        // Getters and Setters
        public string GetDosageForm()
        {
            return dosageForm;
        }

        public void SetDosageForm(string dosageForm)
        {
            this.dosageForm = dosageForm;
        }

        public string GetDose()
        {
            return dose;
        }

        public void SetDose(string dose)
        {
            this.dose = dose;
        }

        public int GetDosageQuantity()
        {
            return dosageQuantity;
        }

        public void SetDosageQuantity(int dosageQuantity)
        {
            this.dosageQuantity = dosageQuantity;
        }

        public double GetDosageCost()
        {
            return dosageCost;
        }

        public void SetDosageCost(double dosageCost)
        {
            this.dosageCost = dosageCost;
        }

        public double GetDosagePrice()
        {
            return dosagePrice;
        }

        public void SetDosagePrice(double dosagePrice)
        {
            this.dosagePrice = dosagePrice;
        }

        public MedicineDosageRecord GetRecord()
        {
            return record;
        }

        public void SetRecord(MedicineDosageRecord record)
        {
            this.record = record;
        }

        // Method to reduce stock
        public void ReduceStock(int qty)
        {
            this.dosageQuantity -= qty;
            int allocateQty = this.record.GetAllocateQuantity() + qty;
            this.record.SetAllocateQuantity(allocateQty);
        }

        // Compare method
        public int CompareTo(object obj)
        {
            if (obj is Dosage otherDosage)
            {
                return this.dosageQuantity.CompareTo(otherDosage.dosageQuantity);
            }
            return 0;
        }

        // Compare dosage quantity
        public int CompareDosageQuantity(object obj)
        {
            if (obj is Dosage otherDosage)
            {
                return this.dosageQuantity.CompareTo(otherDosage.dosageQuantity);
            }
            return 0;
        }

        // Compare allocated quantity
        public int CompareAllocatedQuantity(object obj)
        {
            if (obj is Dosage otherDosage)
            {
                return this.record.GetAllocateQuantity().CompareTo(otherDosage.record.GetAllocateQuantity());
            }
            return 0;
        }

        // Compare restock quantity
        public int CompareRestockQuantity(object obj)
        {
            if (obj is Dosage otherDosage)
            {
                return this.record.GetRestockQuantity().CompareTo(otherDosage.record.GetRestockQuantity());
            }
            return 0;
        }

        // Clone method
        public object Clone()
        {
            // Perform a shallow copy
            return this.MemberwiseClone();
        }

        // ToString method for displaying object details
        public override string ToString()
        {
            return $"DosageForm: {dosageForm}, Dose: {dose}, DosageQuantity: {dosageQuantity}, " +
                   $"DosageCost: {dosageCost}, DosagePrice: {dosagePrice}, Record: {record}";
        }
    }

    // Placeholder for MedicineDosageRecord class
    public class MedicineDosageRecord
    {
        private int allocateQuantity;
        private int restockQuantity;

        public MedicineDosageRecord(int allocateQuantity, int restockQuantity)
        {
            this.allocateQuantity = allocateQuantity;
            this.restockQuantity = restockQuantity;
        }

        public int GetAllocateQuantity()
        {
            return allocateQuantity;
        }

        public void SetAllocateQuantity(int allocateQuantity)
        {
            this.allocateQuantity = allocateQuantity;
        }

        public int GetRestockQuantity()
        {
            return restockQuantity;
        }

        public void SetRestockQuantity(int restockQuantity)
        {
            this.restockQuantity = restockQuantity;
        }

        public override string ToString()
        {
            return $"AllocateQuantity: {allocateQuantity}, RestockQuantity: {restockQuantity}";
        }
    }
}
