# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 12:50:23 2024

@author: huzai
"""

def Merge(CustomList, l, m , r): #dvide and Conquer Algorithm l is left, r is right , m is middle
    
    n1 = m - l +1 # First Sub Array
    n2 = r - m    # Second Sub Array
    
    L= [0] * (n1)
    R= [0] * (n2)
    
    for i in range(0 , n1):                   #First Sub Array
        L[i] = CustomList[l+i]            
        
    for j in range(0 , n2):                   # Second Sub Array
        R[j] = CustomList[m+ 1+j]
    
    i=0
    j=0
    k=l
    
    while i< n1 and j< n2:
        if L[i]<= R[j]:
            CustomList[k] = L[i]
            i+= 1 
        else:
            CustomList[k] = R[j]
            j+= 1
        k+= 1 
    
    while i< n1:
        CustomList[k] = L[i]
        i+= 1
        k+= 1 
        
    while j< n2:
        CustomList[k] = R[j]
        j+= 1
        k+= 1
        
def MergeSort(CustomList , l, r):# now we have divide and then we will conquer it merge it accordingly
    if(l < r):
        m = (l+ (r-1)) //2  # // is floating divide
        
        MergeSort(CustomList, l, m)
        MergeSort(CustomList,m+1, r)
        Merge(CustomList, l, m, r)
        
    return CustomList


CList=[2,9,8,3,4,7,5,6,1]
print(MergeSort(CList, 0, 8))
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        