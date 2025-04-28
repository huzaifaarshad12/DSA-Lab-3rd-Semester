import time
import csv
import pandas as pd
from funcs import InsertionSort,BubbleSort,MergeSort,SelectionSort,HybridMergeSort,RandomArray

def ReadValues(filename):
    # Read the text file using pandas
    df = pd.read_csv(filename, header=None)
    # Convert the dataframe to a list
    values = df[0].tolist()
    return values

#Function for measuring time taken for any sorting function
def SortTime(sort_function, array):
    start_time = time.time()
    sort_function(array,0,len(array))
    end_time = time.time()
    return end_time - start_time

def SortingAlgorithms(n_values, filename):
    # Open the CSV file for writing
    with open(filename, mode='w', newline='') as file:
        writer = csv.writer(file)
        # Write the header row
        writer.writerow(["Value of n", "Insertion sort (seconds)", "Merge Sort (seconds)", "Hybrid Merge Sort (seconds)", "Selection Sort (seconds)", "Bubble Sort (seconds)"])
        
        # Run the algorithms for each value of n
        for n in n_values:
            # Generate array with n random numbers
            array = RandomArray(n)
            
            # Make copies of the array for each sorting algorithm
            arr_insertion = array.copy()
            arr_merge = array.copy()
            arr_hybrid = array.copy()
            arr_selection = array.copy()
            arr_bubble = array.copy()
            
            # Measure time for each sorting algorithm
            insertion_time = SortTime(InsertionSort, arr_insertion)
            merge_time = SortTime(MergeSort, arr_merge)
            hybrid_time = SortTime(HybridMergeSort, arr_hybrid)
            selection_time = SortTime(SelectionSort, arr_selection)
            bubble_time = SortTime(BubbleSort, arr_bubble)
            
            # Write the row in the CSV file
            writer.writerow([n, insertion_time, merge_time, hybrid_time, selection_time, bubble_time])


# List of n values
Nvalues = ReadValues("Nvalues.txt")

# Run the sorting algorithms and fill the CSV
SortingAlgorithms(Nvalues, 'RunTime.csv')
