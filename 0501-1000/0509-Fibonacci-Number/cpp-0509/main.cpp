/// Source : https://leetcode.com/problems/fibonacci-number/
/// Author : liuyubobobo
/// Time   : 2019-01-09

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int fib(int N) {

        vector<int> dp(N + 1, -1);
        dp[0] = 0;
        dp[1] = 1;
        return dfs(N, dp);
    }

private:
    int dfs(int N, vector<int>& dp){

        if(N <= 1) return N;
        if(dp[N] >= 0) return dp[N];
        return dp[N] = dfs(N - 1, dp) + dfs(N - 2, dp);
    }
};


int main() {

    return 0;
}