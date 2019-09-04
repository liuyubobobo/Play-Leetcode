/// Source : https://leetcode.com/problems/decode-ways/
/// Author : liuyubobobo
/// Time   : 2019-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int n;
    vector<int> dp;

public:
    int numDecodings(string s) {

        n = s.size();
        dp.resize(n, -1);
        return dfs(s, 0);
    }

private:
    int dfs(const string& s, int start){

        if(start >= s.size()) return 1;
        if(s[start] == '0') return 0;
        if(dp[start] != -1) return dp[start];

        int res = dfs(s, start + 1);
        if(start + 1 < n && s.substr(start, 2) <= "26")
            res += dfs(s, start + 2);
        return dp[start] = res;
    }
};


int main() {

    cout << Solution().numDecodings("12") << endl;
    cout << Solution().numDecodings("226") << endl;

    return 0;
}