/// Source : https://leetcode.com/problems/reducing-dishes/
/// Author : liuyubobobo
/// Time   : 2020-04-11

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(nlogn + n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(), satisfaction.end());

        int n = satisfaction.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, INT_MIN));
        for(int i = 0; i < n; i ++) dp[i][n] = satisfaction[i] * n;

        for(int t = n - 1; t > 0; t --){
            dp[n - 1][t] = satisfaction[n - 1] * t;
            for(int i = n - 2; i >= 0; i --)
                dp[i][t] = max(satisfaction[i] * t + dp[i + 1][t + 1], dp[i + 1][t]);
        }
        return max(0, dp[0][1]);
    }
};


int main() {

    vector<int> nums1 = {-1,-8,0,5,-9};
    cout << Solution().maxSatisfaction(nums1) << endl;

    return 0;
}
