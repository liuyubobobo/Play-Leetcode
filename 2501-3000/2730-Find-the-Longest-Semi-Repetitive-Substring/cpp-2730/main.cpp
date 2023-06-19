/// Source : https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/description/
/// Author : liuyubobobo
/// Time   : 2023-06-13

#include <iostream>
#include <algorithm>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {

        int res = 1;
        for(int i = 0; i + 1 < s.size(); i ++)
            res = max(res, solve(s, i, i + 1));
        return res;
    }

private:
    int solve(const string& s, int a, int b){
        int res = 2;
        for(int i = a - 1; i >= 0 && s[i] != s[i + 1]; i --) res ++;
        for(int i = b + 1; i < s.size() && s[i] != s[i - 1]; i ++) res ++;
        return res;
    }
};


int main() {

    return 0;
}
