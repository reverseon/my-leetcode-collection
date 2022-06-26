#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> sum;
    vector<vector<int>> mat;
public:
    int countsum(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
    int counttarget(int target) {
        int count = 0;
        for (int r1 = 0; r1 < mat.size(); r1++) {
            for (int c1 = 0; c1 < mat[0].size(); c1++) {
                for (int r2 = r1; r2 < mat.size(); r2++) {
                    for (int c2 = c1; c2 < mat[0].size(); c2++) {
                        if (countsum(r1, c1, r2, c2) == target) {
                            cout << count << ": " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        sum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        mat = matrix;
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + mat[i-1][j-1];
            }
        }
        for (auto row : sum) {
            for (auto col : row) {
                cout << col << " ";
            }
            cout << endl;
        }
        return counttarget(target);
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == 0) {
        //             sum[i][j] = matrix[i][j];
        //         } else {
        //             sum[i][j] = sum[i - 1][j] + matrix[i][j];
        //         }
        //     }
        // }
        // int res = 0;
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         for (int k = i; k < m; k++) {
        //             int sum_k = sum[k][j];
        //             if (i > 0) sum_k -= sum[i - 1][j];
        //             if (sum_k == target) res++;
        //         }
        //     }
        // }
        // return res;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };
    Solution sol;
    cout << sol.numSubmatrixSumTarget(matrix, 3) << endl;
    return 0;
}