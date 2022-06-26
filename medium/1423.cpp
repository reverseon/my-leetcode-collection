#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int r = 0;
        for (int i = 0; i < min(k, n); i++) {
            r += cardPoints[i];
        }
        if (n <= k) {
            return r;
        } else {
            int t = r;
            int front = k-1;
            for (int i = n-1; i >= 0; i--) {
                if (front < 0) {
                    break;
                }
                t -= cardPoints[front];
                t += cardPoints[i];
                front--;
                if (t > r) r = t;
            }
            return r;
        }
    }
};

int main() {
    Solution s;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    cout << s.maxScore(cardPoints, 3) << endl;
    return 0;
}