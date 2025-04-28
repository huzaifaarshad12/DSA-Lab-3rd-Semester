# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 15:02:07 2024

@author: huzai
"""


def countingSort(arr, place):
    n = len(arr)
    output = [0] * n  
    count = [0] * 10 
    
   
    for i in range(n):
        index = (arr[i] // place) % 10
        count[index] += 1
    
    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        index = (arr[i] // place) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
    
    for i in range(n):
        arr[i] = output[i]

# Function to do Radix Sort
def radixSort(arr):
    # maximum number 
    max_val = max(arr)
    
    # perform counting sort for each digit by starting with lsb to msb 1 place then 10 place than 100 place
    place = 1
    while max_val // place > 0:
        countingSort(arr, place)
        place *= 10
        
    print(arr)
    
arr = [170, 45, 75, 90, 802, 24, 2, 66]
radixSort(arr)

arr = ['s', 'd','k','k','h','d','f','c']
radixSort(arr)
