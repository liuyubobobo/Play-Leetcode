/// Source : https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(target)
/// Space Complexity: O(target * |s|)
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {

        vector<string> dp(target + 1, "");
        for(int i = 0; i < 9; i ++)
            if(cost[i] <= target) dp[cost[i]] = string(1, '0' + (1 + i));

        for(int k = 1; k <= target; k ++)
            for(int i = 8; i >= 0; i --)
                if(k > cost[i] && dp[k - cost[i]] != "" && 1 + dp[k - cost[i]].size() > dp[k].size())
                    dp[k] = string(1, '0' + (1 + i)) + dp[k - cost[i]];
        return dp[target].size() ? dp[target] : "0";
    }
};


int main() {

    vector<int> cost1 = {4,3,2,5,6,7,2,5,5};
    cout << Solution().largestNumber(cost1, 9) << endl;
    // 7772

    vector<int> cost2 = {7,6,5,5,5,6,8,7,8};
    cout << Solution().largestNumber(cost2, 12) << endl;
    // 85

    vector<int> cost3 = {210,77,91,105,378,333,316,323,353};
    cout << Solution().largestNumber(cost3, 1217) << endl;
    // 9944443

    return 0;
}
