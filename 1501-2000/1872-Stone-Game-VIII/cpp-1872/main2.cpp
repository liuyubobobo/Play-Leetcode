/// Source : https://leetcode.com/problems/stone-game-viii/
/// Author : liuyubobobo
/// Time   : 2021-05-23

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {

        int n = stones.size();
        vector<int> sum(n, stones[0]);
        for(int i = 1; i < n; i ++)
            sum[i] = sum[i - 1] + stones[i];

        vector<int> dp(n, INT_MIN);
        dp[n - 2] = sum[n - 1];
        for(int i = n - 3; i >= 0; i --)
            dp[i] = max(sum[i + 1] - dp[i + 1], dp[i + 1]);
        return dp[0];
    }
};


int main() {

    vector<int> stones1 = {-1, 2, -3, 4, -5};
    cout << Solution().stoneGameVIII(stones1) << endl;
    // 5

    vector<int> stones2 = {7, -6, 5, 10, 5, -2, -6};
    cout << Solution().stoneGameVIII(stones2) << endl;
    // 13

    vector<int> stones3 = {-10, -12};
    cout << Solution().stoneGameVIII(stones3) << endl;
    // -22

    return 0;
}
