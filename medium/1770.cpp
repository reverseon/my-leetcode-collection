#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& n, vector<int>& m, int i, int l, int r) {
        if (i == m.size()) return 0;
        if (dp[l][i] != -1) return dp[l][i];
        int lv = m[i]*n[l] + dfs(n, m, i+1, l+1, r);
        int rv = m[i]*n[r] + dfs(n, m, i+1, l, r-1);
        dp[l][i] = max(lv, rv);
        return dp[l][i];

    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        dp = vector<vector<int>>(n, vector<int>(m, INT_MIN));
        return dfs(nums, multipliers, 0, 0, n-1);   
    }
};

int main() {
    Solution s;
    vector<int> nums = {-5,-3,-3,-2,7,1};
    vector<int> multipliers = {-10,-5,3,4,6};
    cout << s.maximumScore(nums, multipliers) << endl;
    return 0;
}