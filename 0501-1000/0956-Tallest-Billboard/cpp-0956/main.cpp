/// Source : https://leetcode.com/problems/tallest-billboard/
/// Author : liuyubobobo
/// Time   : 2020-05-12

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n * max_sum)
/// Space Complexity: O(n * max_sum)
class Solution {

private:
    const int OFFSET = 5000;

public:
    int tallestBillboard(vector<int>& rods) {

        vector<vector<int>> dp(20, vector<int>(10001, -1));
        int res = dfs(rods, 0, 0, dp);
        return res == INT_MIN ? 0 : res;
    }

private:
    // diff is left - right
    int dfs(const vector<int>& rods, int index, int diff, vector<vector<int>>& dp){

        if(index == rods.size()) return diff == 0 ? 0 : INT_MIN;

        int state = diff + OFFSET;
        if(dp[index][state] != -1) return dp[index][state];

        int res =  dfs(rods, index + 1, diff, dp);

        int tres = dfs(rods, index + 1, diff - rods[index], dp);
        res = max(res, tres);

        tres = dfs(rods, index + 1, diff + rods[index], dp);
        res = max(res, tres + rods[index]);

        return dp[index][state] = res;
    }
};


int main() {

    vector<int> rods1 = {243,269,278,237,208,279,229,231,262,256,248,261,232,275,254,224,264};
    cout << Solution().tallestBillboard(rods1) << endl;
    // 2125

    vector<int> rods2 = {1, 2};
    cout << Solution().tallestBillboard(rods2) << endl;
    // 0

    return 0;
}
