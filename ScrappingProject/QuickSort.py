# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 12:41:03 2024

@author: huzai
"""

def partition(customList, low, high):
    i=low - 1 
    pivot= customList[high]
    for j in range(low, high):
        if customList[j]<= pivot:
            i += 1
            customList[i] , customList[j] = customList[j], customList[i]   # SWapping-
    customList[i+1], customList[high] = customList[high] , customList[i+1] # Swapping-
    return (i+1) 

def quickSort(customList, low, high):
    if low < high:
        pi = partition(customList, low, high)
        quickSort(customList, low, pi-1)
        quickSort(customList, pi+1, high)
        
cList =[3,1,7,6,5,8,5,4,4,9]
quickSort(cList, 0, 9)

print(cList)