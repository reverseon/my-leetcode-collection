#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < numbers.size(); i++) {
            if (hash.find(numbers[i]) != hash.end()) {
                return vector<int>{hash[numbers[i]], i + 1};
            }
            hash[target - numbers[i]] = i + 1;
        }
        return vector<int>{};
    }
};