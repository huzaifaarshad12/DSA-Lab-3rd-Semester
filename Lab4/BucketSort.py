# -*- coding: utf-8 -*-
"""
Created on Sun Sep 29 13:54:08 2024

@author: huzai
"""

def bucket_sort(arr):
    # Step 1: Create empty buckets
    bucket_count = len(arr)
    buckets = [[] for _ in range(bucket_count)]

    # Step 2: Distribute the elements into different buckets
    max_value = max(arr)
    for num in arr:
        # Find the bucket for each element
        index = int(num / max_value * (bucket_count - 1))
        buckets[index].append(num)

    # Step 3: Sort each bucket individually
    for i in range(bucket_count):
        buckets[i].sort()

    # Step 4: Concatenate all sorted buckets
    sorted_array = []
    for bucket in buckets:
        sorted_array.extend(bucket)

    return sorted_array

arr = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68]
print("Original array:", arr)

sorted_arr = bucket_sort(arr)

print("Sorted array:", sorted_arr)
