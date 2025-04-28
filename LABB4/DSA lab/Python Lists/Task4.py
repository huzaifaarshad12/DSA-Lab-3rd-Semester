numbers = [5, -3, 9, -1, 7, -6, 2]

positive_numbers = [num for num in numbers if num >= 0]

max_value = max(positive_numbers)
min_value = min(positive_numbers)

average_value = sum(positive_numbers) / len(positive_numbers)

print("Original list:", numbers)
print("List after removing negative numbers:", positive_numbers)
print("Maximum value:", max_value)
print("Minimum value:", min_value)
print("Average value:", average_value)

