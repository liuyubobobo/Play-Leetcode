/// Source : https://leetcode.com/problems/minimum-time-to-finish-the-race/
/// Author : liuyubobobo
/// Time   : 2022-02-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Memoization
/// Time Complexity: O(n * log(MAX_TIME) + numLaps ^ 2)
/// Space Complexity: O(n + numLaps^2)
class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, long long changeTime, long long numLaps) {

        int n = tires.size();
        sort(tires.begin(), tires.end());

        long long L = (numLaps - 1ll) * changeTime + numLaps * tires[0][0];
        vector<long long> minT(numLaps + 1, LONG_LONG_MAX);
        for(int i = 0; i < n; i ++){
            long long sum = 0, cur = tires[i][0];
            for(int j = 1; j <= numLaps && sum <= L; j ++){
                sum += cur;
                cur *= tires[i][1];
                minT[j] = min(minT[j], sum);
            }
        }

        vector<long long> dp(numLaps + 1, -1);
        return dfs(numLaps, minT, changeTime, dp);
    }

private:
    long long dfs(int left, const vector<long long>& minT, long long changeTime,
                  vector<long long>& dp){

        if(left == 0) return 0;
        if(dp[left] != -1) return dp[left];

        long long res = LONG_LONG_MAX;
        for(int i = 1; i <= left && minT[i] != LONG_LONG_MAX; i ++){
            long long tres = minT[i] + (i == left ? 0 : changeTime) + dfs(left - i, minT, changeTime, dp);
            res = min(res, tres);
        }
        return dp[left] = res;
    }
};


int main() {

    vector<vector<int>> tires1 = {{2, 3}, {3, 4}};
    int changeTime1 = 5, numLaps1 = 4;
    cout << Solution().minimumFinishTime(tires1, changeTime1, numLaps1) << endl;
    // 21

    vector<vector<int>> tires2 = {{1, 10}, {2, 2}, {3, 4}};
    int changeTime2 = 6, numLaps2 = 5;
    cout << Solution().minimumFinishTime(tires2, changeTime2, numLaps2) << endl;
    // 25

    return 0;
}
