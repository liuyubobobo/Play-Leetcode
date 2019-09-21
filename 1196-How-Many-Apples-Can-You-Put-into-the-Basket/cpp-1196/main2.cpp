/// Source : https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Progrramming with Space Optimization
/// Time Complexity: O(5000n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {

        vector<int> dp(5001, 0);
        for(int j = arr[0]; j <= 5000; j ++)
            dp[j] = 1;
        for(int i = 1; i < arr.size(); i ++){
            vector<int> dp2 = dp;
            for(int j = arr[i]; j <= 5000; j ++)
                dp2[j] = max(dp[j], 1 + dp[j - arr[i]]);
            dp = dp2;
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    return 0;
}