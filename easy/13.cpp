#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int romansingleton(char s) {
        switch (s) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int sum = 0;
        char prev = NULL;
        for (int i = 0; i < s.length(); i++) {
            sum += romansingleton(s[i]);
            if (prev != NULL && romansingleton(s[i]) > romansingleton(prev)) {
                sum -= 2 * romansingleton(prev);
            }
            prev = s[i];
        }
        return sum;
    }
};