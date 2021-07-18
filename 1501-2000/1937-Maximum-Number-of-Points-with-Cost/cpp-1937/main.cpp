/// Source : https://leetcode.com/problems/maximum-number-of-points-with-cost/
/// Author : liuyubobobo
/// Time   : 2021-07-17

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// DP
/// Time Complexity: O(R * C)
/// Space Complexity: O(C)
class Solution {

public:
    long long maxPoints(vector<vector<int>>& points) {

        int R = points.size(), C = points[0].size();

        vector<long long> dp(C, 0);
        for(int j = 0; j < C; j ++) dp[j] = points[0][j];

        vector<long long> left(C), right(C);
        for(int r = 1; r < R; r ++){

            for(int j = 0; j < C; j ++)
                left[j] = dp[j] + j, right[j] = dp[j] - j;
            for(int j = 1; j < C; j ++)
                left[j] = max(left[j], left[j - 1]);
            for(int j = C - 2; j >= 0; j --)
                right[j] = max(right[j], right[j + 1]);

            for(int j = 0; j < C; j ++)
                dp[j] = (long long)points[r][j] + max(left[j] - j, right[j] + j);
        }

        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<vector<int>> points1 = {
            {1, 2, 3},
            {1, 5, 1},
            {3, 1, 1}
    };
    cout << Solution().maxPoints(points1) << endl;
    // 9

    vector<vector<int>> points2 = {
            {1, 5},
            {2, 3},
            {4, 2}
    };
    cout << Solution().maxPoints(points2) << endl;
    // 11

    vector<vector<int>> points3 = {
            {1},
            {2},
            {4}
    };
    cout << Solution().maxPoints(points3) << endl;
    // 7

    return 0;
}
