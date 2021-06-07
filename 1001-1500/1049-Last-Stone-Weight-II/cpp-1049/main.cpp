/// Source : https://leetcode.com/problems/last-stone-weight-ii/
/// Author : liuyubobobo
/// Time   : 2021-06-07

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n * sum)
/// Space Complexity: O(sum)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {

        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);

        vector<bool> dp(sum / 2 + 1, false);
        dp[0] = true;
        if(stones[0] <= sum / 2) dp[stones[0]] = true;
        for(int i = 1; i < n; i ++){
            for(int j = sum / 2; j >= stones[i]; j --)
                dp[j] = dp[j - stones[i]] || dp[j];
        }

        int res = 0;
        for(int i = sum / 2; i >= 0; i --)
            if(dp[i]){
                res = i; break;
            }
//        cout << "res = " << res << endl;

        return sum - 2 * res;
    }
};


int main() {

    vector<int> stones1 = {31,26,33,21,40};
    cout << Solution().lastStoneWeightII(stones1) << endl;
    // 5

    return 0;
}