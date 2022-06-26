#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector<int> res;
        int acc = 0;
        for (int i = 0; i < nums.size(); i++) {
            acc += nums[i];
            res.push_back(acc);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> res = s.runningSum(nums);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}