# -*- coding: utf-8 -*-
"""
Created on Sun Sep 15 19:55:31 2024

@author: huzai
"""

import random
import time
import csv

# Insertion sort for small sub-arrays
def InsertionSort(array, start, end):
    for i in range(start + 1, end + 1):
        key = array[i]
        j = i - 1
        while j >= start and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key

# Merge function to merge two halves
def Merge(array, p, q, r):
    left = array[p:q+1]
    right = array[q+1:r+1]
    
    i = 0
    j = 0
    k = p
    
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            array[k] = left[i]
            i += 1
        else:
            array[k] = right[j]
            j += 1
        k += 1
    
    while i < len(left):
        array[k] = left[i]
        i += 1
        k += 1
    
    while j < len(right):
        array[k] = right[j]
        j += 1
        k += 1

# Hybrid merge sort: switches to insertion sort for small arrays
def HybridMergeSort(array, start, end, n):
    if end - start + 1 <= n:
        InsertionSort(array, start, end)
    else:
        if start < end:
            mid = (start + end) // 2
            HybridMergeSort(array, start, mid, n)
            HybridMergeSort(array, mid + 1, end, n)
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
    
    # Value of n for hybrid sort
    n = 32
    
    # Get the start time
    start_time = time.time()
    
    # Perform hybrid merge sort
    HybridMergeSort(array, 0, len(array) - 1, n)
    
    # Derive the time taken
    end_time = time.time()
    time_taken = end_time - start_time
    print(f"Time taken by HybridMergeSort: {time_taken:.4f} seconds")
    
    # Save the sorted array to a CSV file
    save_to_csv(array, 'SortedHybridSort.csv')
