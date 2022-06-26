#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <set>
#include <algorithm>
#define ULL unsigned long long
#define UINT unsigned int
#define LL long long
using namespace std;

// UNFINISHED, MAYBE FINISHED LATER

template <typename T>
void vprint(vector<T>& v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}
template <typename T>
void setprint(set<T>& s) {
    for (auto i : s) {
        cout << i << " ";
    }
    cout << endl;
}

void vprint(vector<vector<int>>& v) {
    for (auto i : v) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

class Solution {
private:
    int p;
    ULL hash_mask = 1610612741;
    // ULL p = 786433;
public:
    UINT countunique(vector<vector<int>>& v) {
        unordered_set<ULL> unique;
        for (auto i : v) {
            for (auto j : i) {
                unique.insert(j);
            }
        }
        return unique.size();
    }
    ULL modexp(ULL a, ULL b, ULL mod) {
        ULL res = 1;
        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    UINT intersection_how_many(vector<set<ULL>>& sets) {
        set<ULL> res;
        for (auto i : sets) {
            if (res.empty()) {
                res = i;
            } else {
                set<ULL> tmp;
                set_intersection(res.begin(), res.end(), i.begin(), i.end(), inserter(tmp, tmp.begin()));
                if (tmp.empty()) {
                    return 0;
                } else {
                    res = tmp;
                }
            }
        }
        return res.size();
    }
    inline ULL posminmod(ULL x, ULL y, ULL mod) { // (6-31)%20 =15
        if (x > y) {
            return (x - y) % mod; 
        } else {
            ULL buff = 0;
            while (buff < y) {
                buff += mod;
            }
            return (x + buff - y) % mod;
        }
    }
    set<ULL> get_hash_set(int len, vector<int> v) {
        set<ULL> hash_set;
        ULL hash = 0;
        // vprint(v);
        for (int i = 0; i < v.size(); i++) {
            hash = ((hash*p) % hash_mask + (v[i] + 1)) % hash_mask;
            if (i >= len) { 
                hash = posminmod(hash, ((v[i-len]+1) * modexp(p, len, hash_mask)) % hash_mask, hash_mask);
            } 
            if (i >= len - 1) {
                hash_set.insert(hash);
            }
            // DBUGING SECTION
            
        }
        return hash_set;
    }
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // cout.tie(NULL);
        p = countunique(paths);
        UINT left = 1;
        UINT right = 0xffffffff;
        for (auto i : paths) {
            right = min(right, (UINT)i.size());
        }
        UINT res = 0;
        while (left <= right) {
            UINT mid = (left + right) / 2;
            vector<set<ULL>> sets;
            for (auto i : paths) {
                sets.push_back(get_hash_set(mid, i));
            }
            if (intersection_how_many(sets) > 0) {
                res = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return res;
    }
};

set<ULL> inline to_set(vector<int>& v) {
    set<ULL> s(v.begin(), v.end());
    return s;
}

int main() {
    Solution s;
    vector<vector<int>> v = {{1,7,0,6,9,0,7,4,3,9,1,5,0,8,0,6,3,6,0,8,3,7,8,3,5,3,7,4,0,6,8,1,4},
    {1,7,0,6,9,0,7,4,3,9,1,5,0,8,0,6,3,6,0,8,3,7,8,3,5,3,7,4,0,6,8,1,5},
    {8,1,7,0,6,9,0,7,4,3,9,1,5,0,8,0,6,3,6,0,8,3,7,8,3,5,3,7,4,0,6,8,1}};
    // vector<set<ULL>> test_inter;
    // for (auto i : v) {
    //     test_inter.push_back(to_set(i));
    // }
    // cout << s.intersection_how_many(test_inter) << endl;
    // for (auto i : res) {
    //     cout << i << " ";
    // }
    cout << s.longestCommonSubpath(5, v) << endl;
    // cout << "TRIAL" << endl;
    // unordered_set<ULL> s1 = s.get_hash_set(4, {1,1,1,1,2});
    // for (ULL i: s1) {
    //     cout << i << endl;
    // }
}