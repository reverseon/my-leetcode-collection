#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string a, string b) {
            return a.size() > b.size();
        });
        for (int i = 0; i < strs.size(); i++) {
            bool is_unique = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) return strs[i].size();
        }
        return -1;
    }
};