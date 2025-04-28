# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 13:44:40 2024

@author: huzai
"""

import math

def  InsertionSort(CustomList):
    for i in range(1, len(CustomList)):
        key = CustomList[i]
        j = i - 1
        while j>=0 and key < CustomList[j]:
            CustomList[j+ 1] = CustomList[j]
            j -= 1
        CustomList[j +1] = key
    return CustomList

def BucketSort(CustomList):
    
    numberOfBuckets = round(math.sqrt(len(CustomList)))  # first step is to find how many buckets there are
    # we use the formula square root of length of List to find the number of buckets
    MaxValue = max(CustomList)
    arr = []
    
    for i in range (numberOfBuckets):
        arr.append([])
        
    for j in CustomList:
        
        index_b = math.ceil(j*numberOfBuckets/MaxValue) # ceil means that eg the ceil of 2.3 is 3 and of 0.2 is 1
        
        # we use the formula to find where the elements go in which bucket
        # the formula is the ceil of (value * number of buckets/ max value)
        # By using this we can find that which element goes in which bucket
        
        arr[index_b -1].append(j)
        
    for i in range (numberOfBuckets): # In this insertion sort we will sort the buckets
        arr[i] = InsertionSort(arr[i])
        
        
    k=0 
    
    # In this loop we will merge the buckets and then our array will be sorted
    
    for i in range(numberOfBuckets):
        for j in range(len(arr[i])):
            CustomList[k]= arr[i][j]
            k+=1
            
    return CustomList
        
CList=[2,9,8,3,4,7,5,6,1]
print(BucketSort(CList))
                
CList=['s', 'd', 'k', 'k', 'h', 'd', 'f', 'c']       
print (BucketSort(CList))
    
    
    