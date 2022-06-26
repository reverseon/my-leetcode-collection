#include <iostream>
#include <vector>
using namespace std;

// DEBUG

template <typename T>
void print_vector(vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

class NumMatrix {
    vector<vector<int>> matrixsum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        matrixsum.resize(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                matrixsum[i][j] = matrixsum[i-1][j] + matrixsum[i][j-1] - matrixsum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // int r1 = row1 + 1;
        // int r2 = row2 + 1;
        // int c1 = col1 + 1;
        // int c2 = col2 + 1;
        // return matrixsum[r2][c2] - matrixsum[r1-1][c2] - matrixsum[r2][c1-1] + matrixsum[r1-1][c1-1];
        return matrixsum[row2+1][col2+1] - matrixsum[row1][col2+1] - matrixsum[row2+1][col1] + matrixsum[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix nm(matrix);
    cout << nm.sumRegion(2, 1, 4, 3) << endl;
    return 0;
}