/// Source : https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
/// Author : liuyubobobo
/// Time   : 2021-07-10

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int res = 0;
        for(char c = 'a'; c <= 'z'; c ++){
            int i = 0;
            for(; i < s.size(); i ++)
                if(s[i] == c) break;

            if(i == s.size()) continue;

            int j = s.size() - 1;
            for(; j >= 0; j --)
                if(s[j] == c) break;

            if(i == j || i + 1 == j) continue;

            vector<int> v(26, 0);
            for(int k = i + 1; k < j; k ++)
                v[s[k] - 'a'] = 1;

            res += accumulate(v.begin(), v.end(), 0);
        }
        return res;
    }
};


int main() {

    return 0;
}
