import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QPushButton, QVBoxLayout, QTableWidget, QTableWidgetItem, QComboBox, QProgressBar
from PyQt5.QtCore import Qt
import pandas as pd
import time

# Sorting Algorithms
def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def count_sort(arr):
    max_val = max(arr)
    count = [0] * (max_val + 1)
    for num in arr:
        count[num] += 1
    sorted_arr = []
    for i in range(len(count)):
        sorted_arr.extend([i] * count[i])
    return sorted_arr

def radix_sort(arr):
    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        counting_sort(arr, exp)
        exp *= 10
    return arr

def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n
    count = [0] * 10
    for i in range(n):
        index = (arr[i] // exp) % 10
        count[index] += 1
    for i in range(1, 10):
        count[i] += count[i - 1]
    i = n - 1
    while i >= 0:
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1
    for i in range(n):
        arr[i] = output[i]

def bucket_sort(arr):
    max_val = max(arr)
    size = max_val / len(arr)
    buckets = [[] for _ in range(len(arr))]
    for num in arr:
        index = int(num / size)
        if index != len(arr):
            buckets[index].append(num)
        else:
            buckets[len(arr) - 1].append(num)
    for i in range(len(arr)):
        insertion_sort(buckets[i])
    sorted_arr = []
    for bucket in buckets:
        sorted_arr.extend(bucket)
    return sorted_arr

def pigeonholeSort(arr): # this is just like counting sort algorithm

    min_val = min(arr)
    max_val = max(arr)
    
   # we will find the range or size 
    size = max_val - min_val + 1
    
    # we will make holes like in counting sort
    holes = [0] * size
    
    # now we will put elements in array by using arr[i] - min formula
    for i in arr:
        holes[i - min_val] += 1
    
    # we will loop to find sorted arrays
    i = 0
    for count in range(size):
        while holes[count] > 0:
            arr[i] = count + min_val
            i += 1
            holes[count] -= 1
    return arr


def GnomeSort(arr):
    n = len(arr)
    index = 0  

    while index < n:
        # So we are at the first element
        if index == 0 or arr[index] >= arr[index - 1]:
            index += 1  # Move to the next element
        else:
            
            arr[index], arr[index - 1] = arr[index - 1], arr[index]  # Swap the element
            index -= 1  # Peechay jana aek position
    
    return arr


class EbookApp(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowTitle('Ebook Data Viewer')
        self.setGeometry(100, 100, 800, 600)

        self.layout = QVBoxLayout()

        self.label = QLabel('Select Sorting Algorithm:')
        self.layout.addWidget(self.label)

        self.sort_combo = QComboBox()
        self.sort_combo.addItems(['Insertion Sort', 'Selection Sort', 'Bubble Sort', 'Quick Sort', 'Merge Sort', 'Count Sort', 'Radix Sort', 'Bucket Sort', 'Pigeonhole Sort', 'Gnome Sort'])
        self.layout.addWidget(self.sort_combo)

        self.attribute_label = QLabel('Select Attribute to Sort:')
        self.layout.addWidget(self.attribute_label)

        self.attribute_combo = QComboBox()
        self.layout.addWidget(self.attribute_combo)

        self.sort_button = QPushButton('Sort')
        self.sort_button.clicked.connect(self.sort_data)
        self.layout.addWidget(self.sort_button)

        self.progress_bar = QProgressBar()
        self.layout.addWidget(self.progress_bar)

        self.table = QTableWidget()
        self.layout.addWidget(self.table)

        self.load_data()

        self.setLayout(self.layout)

    def load_data(self):
        df = pd.read_csv(r'D:\Documents\Semester3\DSA Lab\Project 1\Project 1\ebooks.csv')
        self.data = df.to_dict(orient='list')
        self.display_data(df)
        self.attribute_combo.addItems(df.columns)

    def display_data(self, df):
        self.table.setRowCount(len(df))
        self.table.setColumnCount(len(df.columns))
        self.table.setHorizontalHeaderLabels(df.columns)

        for i, row in df.iterrows():
            for j, col in enumerate(df.columns):
                item = QTableWidgetItem(str(row[col]))
                self.table.setItem(i, j, item)

    def sort_data(self):
        algorithm = self.sort_combo.currentText()
        column_to_sort = self.attribute_combo.currentText()

        if column_to_sort in ['Price (EUR)', 'Publish Year']:
            values = [float(value.replace(',', '')) for value in self.data[column_to_sort]]
        else:
            values = self.data[column_to_sort]

        self.progress_bar.setRange(0, len(values))
        self.progress_bar.setValue(0)

        if algorithm == 'Insertion Sort':
            sorted_values = self.insertion_sort_with_progress(values)
        elif algorithm == 'Selection Sort':
            sorted_values = self.selection_sort_with_progress(values)
        elif algorithm == 'Bubble Sort':
            sorted_values = self.bubble_sort_with_progress(values)
        elif algorithm == 'Quick Sort':
            sorted_values = quick_sort(values)
        elif algorithm == 'Merge Sort':
            sorted_values = merge_sort(values)
        elif algorithm == 'Count Sort':
            sorted_values = count_sort(values)
        elif algorithm == 'Radix Sort':
            sorted_values = radix_sort(values)
        elif algorithm == 'Bucket Sort':
            sorted_values = bucket_sort(values)
        elif algorithm == 'Pigeonhole Sort':
            sorted_values = pigeonholeSort(values)
        elif algorithm == 'Gnome Sort':
            sorted_values = GnomeSort(values)

        sorted_indices = sorted(range(len(values)), key=lambda k: values[k])
        sorted_data = {key: [self.data[key][i] for i in sorted_indices] for key in self.data}

        df_sorted = pd.DataFrame(sorted_data)
        self.display_data(df_sorted)

    def insertion_sort_with_progress(self, arr):
        for i in range(1, len(arr)):
            key = arr[i]
            j = i - 1
            while j >= 0 and key < arr[j]:
                arr[j + 1] = arr[j]
                j -= 1
            arr[j + 1] = key
            self.progress_bar.setValue(i)
            QApplication.processEvents()  # Update the progress bar
        return arr

    def selection_sort_with_progress(self, arr):
        for i in range(len(arr)):
            min_idx = i
            for j in range(i + 1, len(arr)):
                if arr[j] < arr[min_idx]:
                    min_idx = j
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
            self.progress_bar.setValue(i)
            QApplication.processEvents()  # Update the progress bar
        return arr

    def bubble_sort_with_progress(self, arr):
        n = len(arr)
        for i in range(n):
            for j in range(0, n - i - 1):
                if arr[j] > arr[j + 1]:
                    arr[j], arr[j + 1] = arr[j + 1], arr[j]
            self.progress_bar.setValue(i)
            QApplication.processEvents()  # Update the progress bar
        return arr

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = EbookApp()
    ex.show()
    sys.exit(app.exec_())
