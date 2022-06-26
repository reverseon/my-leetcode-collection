#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int smallest = 0x7fffffff;
        string sml;
        for (string s: strs) {
            if (s.length() < smallest) {
                smallest = s.length();
                sml = s;
            }
        }
        for (int i = 0; i < smallest; i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return sml;
    }
};