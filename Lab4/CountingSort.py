# -*- coding: utf-8 -*-
"""
Created on Sun Sep 29 13:54:09 2024

@author: huzai
"""

def counting_sort(arr):
    if len(arr) == 0:
        return arr

    #Find maximum and minimum
    max_val = max(arr)
    min_val = min(arr)
    
    #Create a counting array to store the range of each element
    range_of_elements = max_val - min_val + 1
    count = [0] * range_of_elements

    #Count the occurrences of each element
    for num in arr:
        count[num - min_val] += 1

    #Modify the counting array
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    #Create the output array and place elements at their correct positions
    output = [0] * len(arr)
    for num in reversed(arr):  # Reverse the array to make sorting stable
        output[count[num - min_val] - 1] = num
        count[num - min_val] -= 1

    #Copy the sorted elements back to the original array
    for i in range(len(arr)):
        arr[i] = output[i]

arr = [4, 2, 2, 8, 3, 3, 1]
print("Original array:", arr)

counting_sort(arr)

print("Sorted array:", arr)
