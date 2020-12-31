/// Source : https://leetcode.com/problems/restore-the-array/
/// Author : liuyubobobo
/// Time   : 2020-04-19

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int numberOfArrays(string s, int k) {

        vector<int> dp(s.size(), -1);
        return dfs(s, 0, k, dp);
    }

private:
    int dfs(const string& s, int index, int k, vector<int>& dp){

        if(index == s.size()) return 1;
        if(dp[index] != -1) return dp[index];
        if(s[index] == '0') return dp[index] = 0;

        int res = 0;
        for(int i = index; i < s.size(); i ++){
            if(i + 1 - index == 10 && s[index] >= '2') break;
            int tnum = atoi(s.substr(index, i + 1 - index).c_str());
            if(tnum > k) break;
            res = (res + dfs(s, i + 1, k, dp)) % MOD;
        }
        return dp[index] = res;
    }
};


int main() {

    cout << Solution().numberOfArrays("1000", 10000) << endl;
    // 1

    cout << Solution().numberOfArrays("1000", 10) << endl;
    // 0

    cout << Solution().numberOfArrays("1317", 2000) << endl;
    // 8

    cout << Solution().numberOfArrays("2020", 30) << endl;
    // 1

    cout << Solution().numberOfArrays("1234567890", 90) << endl;
    // 34

    return 0;
}
