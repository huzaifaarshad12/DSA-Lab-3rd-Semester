#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> matrix;
public:
    void addRow(const vector<int>& row) 
    {
        matrix.push_back(row);
    }
    void addColumn(const vector<int>& col) {
        for (size_t i = 0; i < matrix.size(); i++) {
            if (i < col.size()) 
            {
                matrix[i].push_back(col[i]);
            } else 
            {
                matrix[i].push_back(0);
            }
        }
    }

    void display() const 
    {
        for (const auto& row : matrix) 
        {
            for (int val : row) 
            {
                cout << val << " ";
            }
            cout << endl;
        }
    }

    void transpose() 
    {
        vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));
        for (size_t i = 0; i < matrix.size(); i++) {
            for (size_t j = 0; j < matrix[i].size(); j++) {
                transposed[j][i] = matrix[i][j];
            }
        }
        matrix = transposed;
    }
};

int main() {
    Matrix mat;
    
    mat.addRow({4, 5, 6});
    mat.addRow({7, 8, 9});
    cout << "Original Matrix:" << endl;
    mat.display();
    mat.transpose();
    cout << "Transposed Matrix:" << endl;
    mat.display();
    return 0;
}