grid = [[1, 2, 3],
        [4, 5, 6],
        [7, 8, 9]]
def add_row(new_row):
    grid.append(new_row)

def add_column(new_col):
    for i in range(len(grid)):
        grid[i].append(new_col[i])

def display_grid():
    for row in grid:
        print(row)

def sum_of_elements():
    total = 0
    for row in grid:
        total += sum(row)
    return total

print("Original grid:")
display_grid()

add_row([10, 11, 12])
print("\nGrid after adding a row:")
display_grid()

add_column([13, 14, 15, 16])
print("\nGrid after adding a column:")
display_grid()

total_sum = sum_of_elements()
print("\nSum of all elements in the grid:", total_sum)
