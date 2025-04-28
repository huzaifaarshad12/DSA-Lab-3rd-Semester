# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 12:11:12 2024

@author: huzai
"""

def  InsertionSort(CustomList):
    for i in range(1, len(CustomList)): ## the loop starts from the second element
        key = CustomList[i]
        j = i - 1
        while j>=0 and key < CustomList[j]:
            CustomList[j+ 1] = CustomList[j] 
            j -= 1
        CustomList[j +1] = key
    print(CustomList)
    
CList=[2,9,8,3,4,7,5,6,1]
InsertionSort(CList)  



    
