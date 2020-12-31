/// Source : https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Progrramming
/// Time Complexity: O(5000n)
/// Space Complexity: O(5000n)
class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {

        vector<vector<int>> dp(arr.size(), vector<int>(5001, 0));
        for(int j = arr[0]; j <= 5000; j ++)
            dp[0][j] = 1;
        for(int i = 1; i < arr.size(); i ++){
            for(int j = 0; j < arr[i]; j ++)
                dp[i][j] = dp[i - 1][j];
            for(int j = arr[i]; j <= 5000; j ++)
                dp[i][j] = max(dp[i - 1][j], 1 + dp[i - 1][j - arr[i]]);
        }
        return *max_element(dp.back().begin(), dp.back().end());
    }
};


int main() {

    return 0;
}