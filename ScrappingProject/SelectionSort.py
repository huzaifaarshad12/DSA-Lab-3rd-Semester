# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 11:57:34 2024

@author: huzai
"""

def SelectionSort(CustomList):
    for i in range(len(CustomList)):
        min_index = i
        for j in range(i+1, len(CustomList)):
            if CustomList[min_index] > CustomList[j]:
                min_index = j
            CustomList[i] , CustomList[min_index] = CustomList[min_index] , CustomList[i] # Swapping
    print(CustomList)
    
CList = [8,6,5,4,3,6,4,2,1]
SelectionSort(CList)
