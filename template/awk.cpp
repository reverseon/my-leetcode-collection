#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const char *script = R"(
BEGIN {
    n = split(nums, arr)
    for (i = 1; i <= n; i++) {
        need = target - arr[i]
        if (need in seen) {
            print seen[need], i - 1
            exit
        }
        seen[arr[i]] = i - 1
    }
}
)";

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        string nums_str;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) nums_str += " ";
            nums_str += to_string(nums[i]);
        }

        string cmd = "awk -v nums='" + nums_str + "' -v target=" + to_string(target) + " '" + script + "'";

        FILE *fp = popen(cmd.c_str(), "r");

        vector<int> result;
        int val;
        while (fscanf(fp, "%d", &val) == 1) {
            result.push_back(val);
        }
        pclose(fp);

        return result;
    }
};

int main() {
    Solution s;

    // Test 1: nums = [2,7,11,15], target = 9 -> [0,1]
    vector<int> nums1 = {2, 7, 11, 15};
    auto r1 = s.twoSum(nums1, 9);
    cout << "Test 1: [" << r1[0] << ", " << r1[1] << "]" << endl;

    // Test 2: nums = [3,2,4], target = 6 -> [1,2]
    vector<int> nums2 = {3, 2, 4};
    auto r2 = s.twoSum(nums2, 6);
    cout << "Test 2: [" << r2[0] << ", " << r2[1] << "]" << endl;

    // Test 3: nums = [3,3], target = 6 -> [0,1]
    vector<int> nums3 = {3, 3};
    auto r3 = s.twoSum(nums3, 6);
    cout << "Test 3: [" << r3[0] << ", " << r3[1] << "]" << endl;

    return 0;
}
