import random
import time
import csv

# BubbleSort function
def BubbleSort(array, start, end):
    for i in range(start, end):
        for j in range(start, end - i):
            if array[j] > array[j + 1]:
                # Swap elements if they are in the wrong order
                array[j], array[j + 1] = array[j + 1], array[j]

# Function to create a random array of 30,000 integers
def RandomArray(size):
    return [random.randint(0, 100000) for _ in range(size)]

# Save the sorted array to a CSV file
def SaveToCSV(array, filename):
    with open(filename, 'w', newline='') as file:
        writer = csv.writer(file)
        for num in array:
            writer.writerow([num])

if __name__ == "__main__":
    # Create a random array of 30,000 integers
    size = 30000
    array = RandomArray(size)

    # Sort using BubbleSort and calculate the time taken
    start_time = time.time()
    BubbleSort(array, 0, size - 1)
    end_time = time.time()

    # Print the time taken
    print(f"BubbleSort took {end_time - start_time} seconds")

    # Save the sorted array to CSV
    SaveToCSV(array, "SortedBubbleSort.csv")
