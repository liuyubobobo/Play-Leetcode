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

        int n = arr.size();
        vector<vector<int>> dp(2, vector<int>(5001, 0));
        for(int j = arr[0]; j <= 5000; j ++)
            dp[0][j] = 1;
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < arr[i]; j ++)
                dp[i & 1][j] = dp[(i - 1) & 1][j];
            for(int j = arr[i]; j <= 5000; j ++)
                dp[i & 1][j] = max(dp[(i - 1) & 1][j], 1 + dp[(i - 1) & 1][j - arr[i]]);
        }
        return *max_element(dp[(n - 1) & 1].begin(), dp[(n - 1) & 1].end());
    }
};


int main() {

    return 0;
}