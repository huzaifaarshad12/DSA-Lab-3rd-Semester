# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
print ("Hello to Data Structure and Algorithms Course")







def SearchA(Arr, x):
    return [i for i, val in enumerate(Arr) if val == x]

X = [22, 2, 1, 7, 11, 13, 5, 2, 9]
x = int(input("Enter the number: "))
indices = SearchA(X, x)
print(f"Index: {','.join(map(str, indices))}")






"""
import random
array = []
min = 0
max = 20
n = 5
for i in range (0, n):
    num = random. randint (min, max)
    array. append (num)
#Process the same using numpy

"""






def find_indices(Arr, x):
    indices = []
    for i in range(len(Arr)):
        if Arr[i] == x:
            indices.append(i)
    return indices

# Example usage
Arr = [1, 2, 2, 2, 2, 3, 4, 2, 5]
x = int(input("Enter the number: "))

indices = find_indices(Arr, x)
if indices:
    print(f"Index: {', '.join(map(str, indices))}")
else:
    print("Element not found.")
    
    
    
    
    
    
    
    
    
def find_min_index(Arr, start, end):
    if start < 0 or end >= len(Arr) or start > end:
        raise ValueError("Invalid indices")
    min_index = start
    for i in range(start + 1, end + 1):
        if Arr[i] < Arr[min_index]:
            min_index = i

    return min_index
Arr = [3, 4, 7, 8, 0, 1, 23, -2, -5]
start = 4
end = 7

min_index = find_min_index(Arr, start, end)
print(f"Index of minimum element: {min_index}")
   







def find_min_index(Arr, start, end):
    
    if start < 0 or end >= len(Arr) or start > end:
        raise ValueError("Invalid indices")

    min_index = start
    for i in range(start + 1, end + 1):
        if Arr[i] < Arr[min_index]:
            min_index = i

    return min_index

def Sort4(Arr):
    n = len(Arr)
    for i in range(n):
        min_index = find_min_index(Arr, i, n - 1)
        Arr[i], Arr[min_index] = Arr[min_index], Arr[i]
    return Arr

Arr = [35, 4, 1, 101, -4, -5, 1, 100, 0, -3]
sorted_Arr = Sort4(Arr)
print(f"Sorted array: {sorted_Arr}")







def StringReverse(s, start, end):
    
    substring = s[start:end+1]
    reversed_substring = substring[::-1]
    return reversed_substring

s = "University of Engineering and Technology Lahore"
start = 20
end = 38

result = StringReverse(s, start, end)
print(result)





