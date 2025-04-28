import pandas as pd
import time
from funcs import ShuffleArray

def ReadFile(file_path):
    # Read the file as a DataFrame where each row is a line
    df = pd.read_fwf(file_path, header=None, names=['Line'])
    # Combine all lines into a single string
    text = ' '.join(df['Line'])
    # Split the text into words
    words = text.split()
    return words


# Function to implement insertion sort
def InsertionSort(array, start, end):
    # Loop through each element in the specified range
    for i in range(start + 1, end):
        key = array[i]
        j = i - 1
        # Move elements of array that are greater than 'key', to one position ahead of their current position
        while j >= start and array[j].lower() > key.lower():  # Compare case-insensitively
            array[j + 1] = array[j]
            j -= 1
        # Place the key at its correct position
        array[j + 1] = key


#function to implement merge sort
def Merge(arr, p, q, r):
    # Slicing the array from the mid
    left_half_array = arr[p:q + 1]
    right_half_array = arr[q + 1:r + 1]

    i = j = 0  # Initialize two pointers
    k = p      # Initial index of merged subarray

    # Merge the temp arrays back into arr
    while i < len(left_half_array) and j < len(right_half_array):
        if left_half_array[i].lower() <= right_half_array[j].lower():  # Compare case-insensitively
            arr[k] = left_half_array[i]
            i += 1
        else:
            arr[k] = right_half_array[j]
            j += 1
        k += 1

    # Copy any remaining elements of left_half_array, if any
    while i < len(left_half_array):
        arr[k] = left_half_array[i]
        i += 1
        k += 1

    # Copy any remaining elements of right_half_array, if any
    while j < len(right_half_array):
        arr[k] = right_half_array[j]
        j += 1
        k += 1

# Function to implement merge sort
def MergeSort(arr, start, end):
    if start < end:
        # Finding the middle point to divide the array
        middle = (start + end) // 2

        # Recursively sort the first and second halves
        MergeSort(arr, start, middle)
        MergeSort(arr, middle + 1, end)

        # Merge the sorted halves
        Merge(arr, start, middle, end)


file_path = 'words.txt' 
words = ReadFile(file_path)
print("Original Array: ", words)

Insertion1 = words.copy()
MergeSort1 = words.copy()

insertion_start = time.time()
InsertionSort(Insertion1, 0, len(words))
insertion_end = time.time()

print("Time Taken by insertion sort: ", insertion_end - insertion_start, " seconds")

merge_start = time.time()
MergeSort(MergeSort1, 0, len(words))
merge_end = time.time()

print("Time Taken by merge sort: ", merge_end - merge_start, " seconds")

ShuffleArray(words, 0, len(words) - 1)
Insertion2 = words.copy()
MergeSort2 = words.copy()

insertion2_start = time.time()
InsertionSort(Insertion2, 0, len(words))
insertion2_end = time.time()

print("Time taken by insertion sort after shuffle: ",insertion2_end - insertion2_start, " seconds")

merge2_start = time.time()
MergeSort(MergeSort2, 0, len(words))
merge2_end = time.time()

print("Time taken by merge sort after shuffle: ",merge2_end - merge2_start, " seconds")

print("Sorted Array: ", MergeSort2)
