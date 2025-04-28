using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PharmacySystem.Entity
{
        public class Appointment : IComparable<Appointment>
        {
            // Data members
            private static int count = 1; // Static counter for generating unique IDs
            private static readonly string DateFormat = "dd-MM-yyyy HH:mm"; // Date format

            public string ID { get; private set; } // Auto-implemented property with private setter
            public Patient Patient { get; set; }  // Reference to a Patient object
            public DateTime Date { get; set; }    // DateTime object for appointment date
            public string AppointmentDescription { get; set; } // Description of the appointment

            // Default Constructor
            public Appointment()
            {
                ID = GenerateAppointmentID();
                Patient = null;
                Date = DateTime.Now; // Default date is the current date and time
                AppointmentDescription = string.Empty;
                count++;
            }

            // Parameterized Constructor
            public Appointment(Patient patient, DateTime date, string appointmentDescription)
            {
                ID = GenerateAppointmentID();
                Patient = patient;
                Date = date;
                AppointmentDescription = appointmentDescription;
                count++;
            }

            // Static property to get the current count
            public static int Count => count;

            // Method to format the DateTime object as a string
            public string GetFormattedDate()
            {
                return Date.ToString(DateFormat, CultureInfo.InvariantCulture);
            }

            // Generate a unique Appointment ID
            private string GenerateAppointmentID()
            {
                return "A" + count;
            }

            // Implement IComparable for sorting or comparing appointments by date
            public int CompareTo(Appointment other)
            {
                return Date.CompareTo(other.Date);
            }

            // Override Equals for object comparison
            public override bool Equals(object obj)
            {
                if (ReferenceEquals(this, obj))
                    return true;

                if (obj == null || GetType() != obj.GetType())
                    return false;

                Appointment other = (Appointment)obj;
                return ID == other.ID;
            }

            // Override GetHashCode to complement Equals
            public override int GetHashCode()
            {
                return ID.GetHashCode();
            }

            // Override ToString for a formatted string representation of the object
            public override string ToString()
            {
                return $"{ID}\t{Patient?.PatientName ?? "Unknown"}\t{GetFormattedDate()}\t{AppointmentDescription}";
            }
        }

        /// <summary>
        /// Placeholder Patient class to simulate the Patient entity.
        /// </summary>
        public class Patient
        {
            public string PatientName { get; set; } // Example property
        }
    }

