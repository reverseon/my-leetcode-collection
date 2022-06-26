#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int res = 0;
        for (int i = 0; i <= nums1.size(); i++) {
            for (int j = 0; j <= nums2.size(); j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1,2,3,2,1};
    vector<int> nums2 = {3,2,1,4,7};
    cout << s.findLength(nums1, nums2) << endl;
    const int a = 2;
    const int b = 3;
    int m[a][b];
}