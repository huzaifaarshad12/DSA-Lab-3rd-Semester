# -*- coding: utf-8 -*-
"""
Created on Sat Oct  5 14:05:42 2024

@author: huzai
"""

def CountingSort(l):
    
    size = len(l)
    output = [0] * size
    count = [0] * 10
    
    for i in range(0, size):
        count[l[i]] += 1
        
    for j in range(1,10):
        count[j] += count[j-1]
        
    a = size -1
    while a >=0:
        output[count[l[a]] -1] = l[a]
        count[l[a]] -= 1
        a-=1
        
    for k in range(0, size):
        l[k] = output[k]
        
    
    
CList=[3,4,5,6,7,7,3,2,1]
CountingSort(CList)
print(CList)