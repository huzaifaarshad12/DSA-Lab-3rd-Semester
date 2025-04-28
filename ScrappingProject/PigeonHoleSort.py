# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 15:08:47 2024

@author: huzai
"""
# this is non comparison based algorithm
def pigeonholeSort(arr): # this is just like counting sort algorithm

    min_val = min(arr)
    max_val = max(arr)
    
   # we will find the range or size 
    size = max_val - min_val + 1
    
    # we will make holes like in counting sort
    holes = [0] * size
    
    # now we will put elements in array by using arr[i] - min formula
    for i in arr:
        holes[i - min_val] += 1
    
    # we will loop to find sorted arrays
    i = 0
    for count in range(size):
        while holes[count] > 0:
            arr[i] = count + min_val
            i += 1
            holes[count] -= 1
    print (arr)
arr = [8, 3, 2, 7, 4, 6, 8, 1]

pigeonholeSort(arr)
