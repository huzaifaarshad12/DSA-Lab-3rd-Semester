using Pharmacy_system;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PharmacySystem
{
    public class PrescriptionHistory
    {
        private HashTable hashTable;
        private static PrescriptionHistory instance;
        private PrescriptionHistory()
        {
            hashTable = new HashTable();
        }
        public static PrescriptionHistory Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new PrescriptionHistory();
                }
                return instance;
            }
        }
        public void AddPrescription(string patientID, string prescription)
        {
            hashTable.AddPrescription(patientID, prescription);
        }

        public List<string> GetPrescriptions(string patientID)
        {
            return hashTable.GetPrescriptions(patientID);
        }

        public void DisplayAllPrescriptions()
        {
            hashTable.DisplayAllPrescriptions();
        }
    }
}
