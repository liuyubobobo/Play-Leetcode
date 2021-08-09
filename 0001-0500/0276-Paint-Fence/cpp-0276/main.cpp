/// Source : https://leetcode.com/problems/paint-fence/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numWays(int n, int k) {

        vector<vector<int>> dp(2, vector<int>(n, -1));
        return k * dfs(n, k, 1, false, dp);
    }

private:
    int dfs(const int n, const int k, int index, bool same,
            vector<vector<int>>& dp){

        if(index == n) return 1;
        if(dp[same][index] != -1) return dp[same][index];

        int res = 0;
        if(same) res += (k - 1) * dfs(n, k, index + 1, false, dp);
        else{
            res += (k - 1) * dfs(n, k, index + 1, false, dp);
            res += dfs(n, k, index + 1, true, dp);
        }
        return dp[same][index] = res;
    }
};


int main() {

    cout << Solution().numWays(3, 2) << endl;
    // 6

    cout << Solution().numWays(1, 1) << endl;
    // 1

    cout << Solution().numWays(7, 2) << endl;
    // 42

    return 0;
}
