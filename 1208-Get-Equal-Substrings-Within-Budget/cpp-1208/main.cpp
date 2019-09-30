/// Source : https://leetcode.com/problems/get-equal-substrings-within-budget/
/// Author : liuyubobobo
/// Time   : 2019-09-28

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

        vector<int> v;
        for(int i = 0; i < s.size(); i ++)
            v.push_back(abs(s[i] - t[i]));

        int l = 0, r = -1, cur = 0, res = 0; // Sliding Window : [l, r]
        while(l < v.size()){
            if(cur <= maxCost) res = max(res, r - l + 1);

            if(cur <= maxCost && r + 1 < v.size()) cur += v[++ r];
            else cur -= v[l ++];
        }
        return res;
    }
};


int main() {

    cout << Solution().equalSubstring("abcd", "bcdf", 3) << endl;
    // 3

    cout << Solution().equalSubstring("abcd", "cdef", 3) << endl;
    // 1

    cout << Solution().equalSubstring("abcd", "acde", 0) << endl;
    // 1

    return 0;
}