/// Source : https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Calculate the result string's length first
/// and construct this result string afterwards
/// Time Complexity: O(target)
/// Space Complexity: O(target)
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {

        vector<int> dp(target + 1, 0);
        for(int i = 0; i < 9; i ++)
            if(cost[i] <= target) dp[cost[i]] = 1;

        for(int k = 1; k <= target; k ++)
            for(int i = 8; i >= 0; i --)
                if(k > cost[i] && dp[k - cost[i]] && 1 + dp[k - cost[i]] > dp[k])
                    dp[k] = 1 + dp[k - cost[i]];

        if(!dp[target]) return "0";

//        for(int e: dp) cout << e << " "; cout << endl;
        string res = "";
        int cur = target;
        while(cur){
            for(int i = 8; i >= 0; i --)
                if(cur >= cost[i] && dp[cur] == 1 + dp[cur - cost[i]]){
                    if(dp[cur] == 1 && cur != cost[i]) continue;
                    res += string(1, ('0' + (i + 1)));
                    cur -= cost[i];
                    break;
                }
        }
        return res;
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
