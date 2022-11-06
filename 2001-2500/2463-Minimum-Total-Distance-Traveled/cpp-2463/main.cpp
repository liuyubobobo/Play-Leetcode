/// Source : https://leetcode.com/problems/minimum-total-distance-traveled/
/// Author : liuyubobobo
/// Time   : 2022-11-05

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


/// Memoization
/// Time Complexity: O(|robot| * |factory| * |max_limit|)
/// Space Complexity: O(|robot| * |factory|)
class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int rn = robot.size(), fn = factory.size();
        vector<vector<long long>> dp(rn, vector<long long>(fn, -1));
        return dfs(rn, robot, fn, factory, 0, 0, dp);
    }

private:
    long long dfs(int rn, const vector<int>& robot, int fn, const vector<vector<int>>& factory,
                  int rindex, int findex, vector<vector<long long>>& dp){

        if(rindex == rn) return 0;
        if(findex == fn) return LONG_LONG_MAX / 2;
        if(dp[rindex][findex] != -1) return dp[rindex][findex];

        long long res = dfs(rn, robot, fn, factory, rindex, findex + 1, dp);

        int fpos = factory[findex][0], limit = factory[findex][1];
        long long cur = 0;
        for(int i = 0; i < limit && rindex + i < rn; i ++){
            cur += abs(fpos - robot[rindex + i]);
            res = min(res, cur + dfs(rn, robot, fn, factory, rindex + i + 1, findex + 1, dp));
        }
        return dp[rindex][findex] = res;
    }
};


int main() {

    return 0;
}
