import math

# Insertion Sort function
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# Bucket Sort function
def bucket_sort(arr):
    if not arr:
        return arr

    # Check if the array contains only integers or strings
    is_int = all(isinstance(i, int) for i in arr)
    is_str = all(isinstance(i, str) for i in arr)

    if is_int:
        max_value = max(arr)
        num_buckets = round(math.sqrt(len(arr)))
        buckets = [[] for _ in range(num_buckets)]
        
        # Fill the buckets
        for val in arr:
            index = min(math.ceil(val * num_buckets / max_value), num_buckets) - 1
            buckets[index].append(val)

    elif is_str:
        max_value = ord(max(arr))
        num_buckets = round(math.sqrt(len(arr)))
        buckets = [[] for _ in range(num_buckets)]
        
        # Fill the buckets
        for val in arr:
            index = min(math.ceil(ord(val) * num_buckets / max_value), num_buckets) - 1
            buckets[index].append(val)

    # Sort each bucket and concatenate the results
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(insertion_sort(bucket))

    return sorted_arr

# Example usage for integers
int_list = [2, 9, 8, 3, 4, 7, 5, 6, 1]
print(bucket_sort(int_list))

# Example usage for strings
str_list = ['s', 'd', 'k', 'k', 'h', 'd', 'f', 'c']
print(bucket_sort(str_list))
