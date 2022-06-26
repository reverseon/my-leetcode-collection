#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_set>
using namespace std;

void printSet(set<char> s) {
    for (auto i : s) {
        cout << i << " ";
    }
    cout << endl;
}

void printMap(map<char, int> m) {
    for (auto i : m) {
        cout << i.first << " " << i.second << endl;
    }
}

void printVector(vector<char> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        if (str.length() < 2) {
            return str.length();
        }
        unsigned int max = 0;
        int start = 0;
        int end = 0;
        vector<char> v;
        while 
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("tmmzuxt") << endl;
}