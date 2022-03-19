/// Source : https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>

using namespace std;


/// Memoization
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {

        int n = floor.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + (floor[i] == '1');

        vector<vector<int>> dp(n, vector<int>(numCarpets + 1, -1));
        return dfs(n, floor, presum, carpetLen, 0, numCarpets, dp);
    }

private:
    int dfs(int n, const string& floor, const vector<int>& presum, int len,
            int index, int num, vector<vector<int>>& dp){

        if(index == n) return 0;
        if(num == 0) return presum[n] - presum[index];
        if(dp[index][num] != -1) return dp[index][num];

        int r = min(index + len - 1, n - 1);
        int res = dfs(n, floor, presum, len, r + 1, num - 1, dp);

        res = min(res, (floor[index] == '1') + dfs(n, floor, presum, len, index + 1, num, dp));
        return dp[index][num] = res;
    }
};


int main() {

    cout << Solution().minimumWhiteTiles("10110101", 2, 2) << '\n';
    // 2

    cout << Solution().minimumWhiteTiles("11111", 2, 3) << '\n';
    // 0

    return 0;
}
