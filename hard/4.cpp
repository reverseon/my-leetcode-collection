#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& n1, vector<int>& n2) {
       int totsize = n1.size() + n2.size();
       int ptr1 = 0, ptr2 = 0;
       if (totsize % 2 == 0) {
            int i = 0;
            int res = 0;
            int ptr1 = 0;
            int ptr2 = 0;
            int to = totsize / 2 - 1;
            while (i <= to + 1) {
                while (ptr1 < n1.size() && ptr2 < n2.size() && n1[ptr1] < n2[ptr2]) {
                    if (i == to) {
                        res += n1[ptr1];
                    }
                    else if (i == to + 1) {
                        res += n1[ptr1];
                        return res / 2.0;
                    }
                    ptr1++;
                    i++;
                }
                while (ptr1 < n1.size() && ptr2 < n2.size() && n1[ptr1] > n2[ptr2]) {
                    if (i == to) {
                        res += n2[ptr2];
                    }
                    else if (i == to + 1) {
                        res += n2[ptr2];
                        return res / 2.0;
                    }
                    ptr2++;
                    i++;
                }
                while (ptr1 >= n1.size() && ptr2 < n2.size()) {
                    if (i == to) {
                        res += n2[ptr2];
                    }
                    else if (i == to + 1) {
                        res += n2[ptr2];
                        return res / 2.0;
                    }
                    ptr2++;
                    i++;
                }
                while (ptr1 < n1.size() && ptr2 >= n2.size()) {
                    if (i == to) {
                        res += n1[ptr1];
                    }
                    else if (i == to + 1) {
                        res += n1[ptr1];
                        return res / 2.0;
                    }
                    ptr1++;
                    i++;
                }
                while (ptr1 < n1.size() && ptr2 < n2.size() && n1[ptr1] == n2[ptr2]) {
                    if (i == to) {
                        res += n1[ptr1];
                    }
                    else if (i == to + 1) {
                        res += n1[ptr1];
                        return res / 2.0;
                    }
                    ptr1++;
                    i++;
                    if (i == to) {
                        res += n2[ptr2];
                    }
                    else if (i == to + 1) {
                        res += n2[ptr2];
                        return res / 2.0;
                    }
                    ptr2++;
                    i++;
                }
            }
            return 0.0;
       } else {
            int i = 0;
            int ptr1 = 0;
            int ptr2 = 0;
            int to = totsize / 2;
            while (i <= to) {
                while (ptr1 < n1.size() && ptr2 < n2.size() && n1[ptr1] < n2[ptr2]) {
                    if (i == to) {
                        return n1[ptr1];
                    }
                    ptr1++;
                    i++;
                }
                while (ptr1 < n1.size() && ptr2 < n2.size() && n1[ptr1] > n2[ptr2]) {
                    if (i == to) {
                        return n2[ptr2];
                    }
                    ptr2++;
                    i++;
                }
                while (ptr1 >= n1.size() && ptr2 < n2.size()) {
                    if (i == to) {
                        return n2[ptr2];
                    }
                    ptr2++;
                    i++;
                }
                while (ptr1 < n1.size() && ptr2 >= n2.size()) {
                    if (i == to) {
                        return n1[ptr1];
                    }
                    ptr1++;
                    i++;
                }
                while (ptr1 < n1.size() && ptr2 < n2.size() && n1[ptr1] == n2[ptr2]) {
                    if (i == to) {
                        return n1[ptr1];
                    }
                    ptr1++;
                    i++;
                    if (i == to) {
                        return n2[ptr2];
                    }
                    ptr2++;
                    i++;
                }
            }
       }
       return 0.0;
    }
};
int main() {
    Solution s;
    vector<int> n1 = {1, 3};
    vector<int> n2 = {2};
    cout << s.findMedianSortedArrays(n1, n2) << endl;
}