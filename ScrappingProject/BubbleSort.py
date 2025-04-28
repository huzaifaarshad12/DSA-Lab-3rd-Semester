# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 12:42:16 2024

@author: huzai
"""

def BubbleSort(CustomList):
    for i in range(len(CustomList)-1):
        for j in range(len(CustomList)-i-1):
            if CustomList[j] > CustomList[j+1]:
                CustomList[j], CustomList[j+1] = CustomList[j+1], CustomList[j]
    print(CustomList)
    
Clist= [2,9,8,3,4,7,5,6,1]
BubbleSort(Clist)