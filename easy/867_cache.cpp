#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    uint32_t flp2 (uint32_t x)
    {  
        x = x | (x >> 1);
        x = x | (x >> 2);
        x = x | (x >> 4);
        x = x | (x >> 8);
        x = x | (x >> 16);
        return x - (x >> 1);
    }
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<vector<int>> dst(matrix[0].size(), vector<int>(matrix.size()));
        unsigned int m = matrix.size();
        unsigned int n = matrix[0].size();
        unsigned int blocksize = flp2(matrix.size()) / 4;
        blocksize = blocksize > 16 ? blocksize : 16;
        for (int ii = 0; ii < m; ii+=blocksize) {
            for (int jj = 0; jj < n; jj+=blocksize) {
                for (int i = ii; i < ii+blocksize; i++) {
                    for (int j = jj; j < jj+blocksize; j++) {
                        if (i < m && j < n) {
                            dst[j][i] = matrix[i][j];
                        }
                    }
                }
            }
        }
        return dst;
    }   
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> res = s.transpose(matrix);
    for (auto i : res) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}