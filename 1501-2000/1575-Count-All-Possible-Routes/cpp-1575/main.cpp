/// Source : https://leetcode.com/problems/count-all-possible-routes/description/
/// Author : liuyubobobo
/// Time   : 2023-06-25

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^2 * fuel)
/// Space Complexity: O(n * fuel)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {

        int n = locations.size();
        vector<vector<long long>> dp(n, vector<long long>(fuel + 1, -1));
        return dfs(n, locations, finish, start, fuel, dp);
    }

private:
    long long dfs(int n, const vector<int>& locations, int finish, int cur, int fuel,
                         vector<vector<long long>>& dp){

        if(fuel < 0) return 0;
        if(dp[cur][fuel] != -1) return dp[cur][fuel];

        long long res = 0;
        if(cur == finish) res = 1;
        for(int i = 0; i < n; i ++){
            if(i == cur) continue;
            res += dfs(n, locations, finish, i, fuel - abs(locations[i] - locations[cur]), dp);
        }
        return dp[cur][fuel] = res % MOD;
    }
};


int main() {

    return 0;
}
