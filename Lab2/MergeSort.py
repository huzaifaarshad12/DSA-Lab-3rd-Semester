# -*- coding: utf-8 -*-
"""
Created on Sun Sep 15 19:54:52 2024

@author: huzai
"""

import random
import time
import csv

# Merge two halves of the array
def Merge(array, p, q, r):
# Create left and right sub-arrays
    left = array[p:q+1]
    right = array[q+1:r+1]

# Indices for left, right, and main array
    i = 0
    j = 0
    k = p

# Merge the sub-arrays back into the main array
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        k += 1

# Copy any remaining elements of left sub-array
    while i < len(left):
        array[k] = left[i]
        i += 1
        k += 1

# Copy any remaining elements of right sub-array
    while j < len(right):
        array[k] = right[j]
        j += 1
        k += 1

# Merge sort implementation
def MergeSort(array, start, end):
    if start < end:
# Find the middle point
        mid = (start + end) // 2

# Sort first and second halves
        MergeSort(array, start, mid)
        MergeSort(array, mid + 1, end)

# Merge the sorted halves
        Merge(array, start, mid, end)

# Function to generate a random
def RandomArray(size):
    return [random.randint(1, 1000000) for _ in range(size)]

# Function to save sorted array to CSV
def save_to_csv(array, filename):
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        for num in array:
            writer.writerow([num])

# Main code to sort and time the sorting process
if __name__ == "__main__":
    # Generate random array of 20,000 integers
    array = RandomArray(20000)

    # Get the start time
    start_time = time.time()

    # Perform merge sort
    MergeSort(array, 0, len(array) - 1)

    # Calculate the time taken
    end_time = time.time()
    time_taken = end_time - start_time
    print(f"Time taken by MergeSort: {time_taken:.4f} seconds")

    # Save the sorted array to a CSV file
    save_to_csv(array, 'SortedMergeSort.csv')
