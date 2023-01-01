/// Source : https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/
/// Author : liuyubobobo
/// Time   : 2022-12-31

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Memoization
/// Time Complexity: O(nlogk)
/// Space Complexity: O(n)
class Solution {

private:
    const int INF = INT_MAX / 2;
public:
    int minimumPartition(string s, int k) {

        int n = s.size();
        vector<int> dp(n, -1);
        dfs(n, s, 0, k, dp);
        return dp[0] == INF ? -1 : dp[0];
    }

private:
    int dfs(int n, const string& s, int index, long long k, vector<int>& dp){

        if(index == n) return 0;
        if(dp[index] != -1) return dp[index];

        long long cur = 0;
        int res = INF;
        for(int i = index; i < n && cur * 10 + (s[i] - '0') <= k; i ++){
            cur = cur * 10 + (s[i] - '0');
            res = min(res, 1 + dfs(n, s, i + 1, k, dp));
        }
        return dp[index] = res;
    }
};


int main() {


    return 0;
}
