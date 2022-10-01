/// Source : https://leetcode-cn.com/problems/oPs9Bm/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>
#include <numeric>

using namespace  std;


/// Backpack
/// Time Complexity: O(n * k)
/// Space Complexity: O(n * k)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int securityCheck(vector<int>& capacities, int k) {

        int n = capacities.size();
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for(int item: capacities){
            item --;
            for(int c = k; c >= item; c --)
                dp[c] += dp[c - item], dp[c] %= MOD;
        }
        return dp[k];
    }
};


int main() {

    vector<int> cap1 = {2, 2, 3};
    cout << Solution().securityCheck(cap1, 2) << endl;
    // 2

    vector<int> cap2 = {3, 3};
    cout << Solution().securityCheck(cap2, 3) << endl;
    // 0

    vector<int> cap3 = {4, 3, 2, 2};
    cout << Solution().securityCheck(cap3, 6) << endl;
    // 2

    return 0;
}
