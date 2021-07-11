/// Source : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
/// Author : liuyubobobo
/// Time   : 2021-07-10

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Ad-Hoc
/// Using presum and binary search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n = s.size();
        vector<vector<int>> presum(26, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i ++)
            for(char c = 'a'; c <= 'z'; c ++)
                presum[c - 'a'][i + 1] = presum[c - 'a'][i] + (s[i] == c);

        int res = 0;
        for(int c = 0; c < 26; c ++){

            vector<int>::iterator iter = lower_bound(presum[c].begin(), presum[c].end(), 1);

            if(iter == presum[c].end()) continue;
            int i = (iter - presum[c].begin()) - 1;

            iter = lower_bound(presum[c].begin(), presum[c].end(), presum[c].back());
            int j = (iter - presum[c].begin()) - 1;

            if(i == j || i + 1 == j) continue;

            for(int cc = 0; cc < 26; cc ++)
                res += !!(presum[cc][j] - presum[cc][i + 1]);
        }
        return res;
    }
};


int main() {

    cout << Solution().countPalindromicSubsequence("bbcbaba") << endl;
    // 4

    return 0;
}
