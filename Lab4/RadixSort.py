# -*- coding: utf-8 -*-
"""
Created on Sun Sep 29 9:54:08 2024

@author: huzai
"""

def counting_sort_for_radix(arr, exp):
    n = len(arr)
    
    # Output array to store sorted values
    output = [0] * n
    
    # Initialize count array
    count = [0] * 10
    
    #Store count of occurrences in count[]
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    
    #Change count[i] so that it contains the actual position
    for i in range(1, 10):
        count[i] += count[i - 1]
    
    # Build the output array using the count array
    for i in range(n - 1, -1, -1):
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
    
    #Copy the output array to arr[], so that arr now contains sorted numbers
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    max_num = max(arr)
    
    exp = 1
    while max_num // exp > 0:
        counting_sort_for_radix(arr, exp)
        exp *= 10

arr = [170, 45, 75, 90, 802, 24, 2, 66]
print("Original array:", arr)

radix_sort(arr)

print("Sorted array:", arr)
