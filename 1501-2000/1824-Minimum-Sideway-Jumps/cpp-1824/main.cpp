/// Source : https://leetcode.com/problems/minimum-sideway-jumps/
/// Author : liuyubobobo
/// Time   : 2021-04-10

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int n;

public:
    int minSideJumps(vector<int>& obstacles) {

        n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return dfs(2, 0, obstacles, dp);
    }

private:
    int dfs(int index, int pos, const vector<int>& obstacles, vector<vector<int>>& dp){

        if(pos == n - 1) return 0;
        if(dp[index][pos] != -1) return dp[index][pos];

        int res = INT_MAX;
        if(obstacles[pos + 1] != index)
            res = min(res, dfs(index, pos + 1, obstacles, dp));

        for(int next_index = 1; next_index <= 3; next_index ++)
            if(next_index != index){
                if(obstacles[pos] != next_index && obstacles[pos + 1] != next_index)
                    res = min(res, 1 + dfs(next_index, pos + 1, obstacles, dp));
            }
        return dp[index][pos] = res;
    }
};


int main() {

    vector<int> obstacle1 = {0,1,2,3,0};
    cout << Solution().minSideJumps(obstacle1) << endl;
    // 2

    vector<int> obstacle2 = {0,1,1,3,3,0};
    cout << Solution().minSideJumps(obstacle2) << endl;
    // 0

    vector<int> obstacle3 = {0,2,1,0,3,0};
    cout << Solution().minSideJumps(obstacle3) << endl;
    // 2

    return 0;
}
