# Simplified counting sort for integers based on the digit at 'place' value
def counting_sort_int(arr, place):
    n = len(arr)
    output = [0] * n
    count = [0] * 10  # There are 10 possible digits (0-9)

    for i in arr:
        index = (i // place) % 10
        count[index] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in reversed(arr):
        index = (i // place) % 10
        output[count[index] - 1] = i
        count[index] -= 1

    for i in range(n):
        arr[i] = output[i]

# Simplified counting sort for strings based on ASCII values
def counting_sort_str(arr):
    count = [0] * 256  # There are 256 possible ASCII values
    output = [''] * len(arr)

    for char in arr:
        count[ord(char)] += 1

    for i in range(1, 256):
        count[i] += count[i - 1]

    for char in reversed(arr):
        output[count[ord(char)] - 1] = char
        count[ord(char)] -= 1

    for i in range(len(arr)):
        arr[i] = output[i]

# Radix Sort for integers
def radix_sort(arr):
    if all(isinstance(i, int) for i in arr):
        max_val = max(arr)
        place = 1
        while max_val // place > 0:
            counting_sort_int(arr, place)
            place *= 10
    elif all(isinstance(i, str) for i in arr):
        counting_sort_str(arr)


# Example usage for integers
nums = [170, 45, 75, 90, 802, 24, 2, 66]
radix_sort(nums)
print(nums)

# Example usage for strings
chars = ['s', 'd', 'k', 'k', 'h', 'd', 'f', 'c']
radix_sort(chars)
print(chars)

