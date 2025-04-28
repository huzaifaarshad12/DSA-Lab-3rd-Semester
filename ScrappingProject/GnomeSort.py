# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 15:27:21 2024

@author: huzai
"""
# This sort is just like Insertion Sort the most common example is sorting  cards on hand
def GnomeSort(arr):
    n = len(arr)
    index = 0  

    while index < n:
        # So we are at the first element
        if index == 0 or arr[index] >= arr[index - 1]:
            index += 1  # Move to the next element
        else:
            
            arr[index], arr[index - 1] = arr[index - 1], arr[index]  # Swap the element
            index -= 1  # Peechay jana aek position
    
    return arr


array = [34, 2, 23, 67, 1, 99, 12]
GnomeSort(array)
print(array)
    
