# -*- coding: utf-8 -*-
"""
Created on Sun Sep 15 19:31:43 2024

@author: huzai
"""

import random
import time
import csv

# Insertion sort implementation
def InsertionSort(array, start, end):
    for i in range(start + 1, end + 1):
        key = array[i]
        j = i - 1
        while j >= start and key < array[j]:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

# Function to generate a random array of integers
def RandomArray(size):
    random_array = [random.randint(1, 10000) for _ in range(size)]
    return random_array

# Function to save sorted array to CSV
def save_to_csv(array, filename):
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        for num in array:
            writer.writerow([num])

# Main code to sort and time the sorting process
if __name__ == "__main__":
# Generate random array
    array = RandomArray(30000)
    
# Get the start time
    start_time = time.time()

# Perform insertion sort
    InsertionSort(array, 0, len(array) - 1)

# Calculate the time taken
    end_time = time.time()
    time_taken = end_time - start_time
    print(f"Time taken by InsertionSort: {time_taken:.4f} seconds")

# Save the sorted array to a CSV file
    save_to_csv(array, 'SortedInsertionSort.csv')
