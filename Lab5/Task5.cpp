#include <iostream>
#include <vector>

using namespace std;

void displayMatrix(const vector<vector<int>>& matrix) {
    cout << "Current Matrix:\n";
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void addRow(vector<vector<int>>& matrix, const vector<int>& row) {
    matrix.push_back(row);
    cout << "Row added successfully.\n";
}

void addColumn(vector<vector<int>>& matrix, const vector<int>& column) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i < column.size()) {
            matrix[i].push_back(column[i]);
        } else {
            matrix[i].push_back(0); // Fill with 0 if column size is smaller
        }
    }
    cout << "Column added successfully.\n";
}

vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

int main() {
    vector<vector<int>> matrix;

    // Adding initial rows
    addRow(matrix, {1, 2, 3});
    addRow(matrix, {4, 5, 6});
    addRow(matrix, {7, 8, 9});
    displayMatrix(matrix);

    // Adding a column
    addColumn(matrix, {10, 11, 12});
    displayMatrix(matrix);

    // Transposing the matrix
    vector<vector<int>> transposedMatrix = transpose(matrix);
    displayMatrix(transposedMatrix);

    return 0;
}
