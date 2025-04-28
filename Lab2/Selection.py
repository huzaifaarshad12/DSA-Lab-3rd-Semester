# -*- coding: utf-8 -*-
"""
Created on Sun Sep 15 20:08:28 2024

@author: huzai
"""

import random
import time
import csv

# SelectionSort function
def SelectionSort(array, start, end):
    for i in range(start, end):
        # Assume the first element is the minimum
        min_index = i
        for j in range(i + 1, end + 1):
            if array[j] < array[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        array[i], array[min_index] = array[min_index], array[i]

# Function to create a random array of 30,000 integers
def RandomArray(size):
    return [random.randint(0, 100000) for _ in range(size)]

# Save the sorted array to a CSV file
def SaveToCSV(array, filename):
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        for num in array:
            writer.writerow([num])

if __name__ == "__main__":
    # Create a random array of 30,000 integers
    size = 30000
    array = RandomArray(size)

    # Sort using SelectionSort and calculate the time taken
    start_time = time.time()
    SelectionSort(array, 0, size - 1)
    end_time = time.time()

    # Print the time taken
    print(f"SelectionSort took {end_time - start_time} seconds")

    # Save the sorted array to CSV
    SaveToCSV(array, "SortedSelectionSort.csv")
