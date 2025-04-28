def counting_sort(arr):
    if all(isinstance(i, int) for i in arr):
        # Counting sort for integers
        max_val = max(arr)
        count = [0] * (max_val + 1)
        
        for num in arr:
            count[num] += 1

        sorted_arr = []
        for i in range(len(count)):
            sorted_arr.extend([i] * count[i])

        return sorted_arr

    elif all(isinstance(i, str) for i in arr):
        # Counting sort for strings (based on ASCII values)
        max_val = ord(max(arr))
        count = [0] * (max_val + 1)
        
        for char in arr:
            count[ord(char)] += 1

        sorted_arr = []
        for i in range(len(count)):
            sorted_arr.extend([chr(i)] * count[i])

        return sorted_arr

    

# Example usage for integers
nums = [4, 2, 2, 8, 3, 3, 1]
print(counting_sort(nums))


# Example usage for strings
chars = ['b', 'd', 'a', 'c', 'b']
print(counting_sort(chars))

