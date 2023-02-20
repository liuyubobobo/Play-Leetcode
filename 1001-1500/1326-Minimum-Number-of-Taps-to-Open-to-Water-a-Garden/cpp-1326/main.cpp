/// Source : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/
/// Author : liuyubobobo
/// Time   : 2023-02-20

#include <iostream>
#include <climits>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n * max_range)
/// Space Complexity: O(n)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<int> dp(n, INT_MAX / 2);
        for(int i = 0; i <= n; i ++){
            int l = max(0, i - ranges[i]), r = min(n, i + ranges[i]);
            for(int j = l; j < r; j ++)
                dp[j] = min(dp[j], (l - 1 >= 0 ? dp[l - 1] : 0) + 1);
        }
        return dp.back() == INT_MAX / 2 ? -1 : dp.back();
    }
};

int main() {

    vector<int> ranges1 = {0, 0, 0, 0};
    cout << Solution().minTaps(3, ranges1) << '\n';

    return 0;
}
