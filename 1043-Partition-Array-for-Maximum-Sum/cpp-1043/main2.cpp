/// Source : https://leetcode.com/problems/partition-array-for-maximum-sum/
/// Author : liuyubobobo
/// Time   : 2019-05-19

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(|A|^2)
/// Space Complexity :O(|A|)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {

        vector<int> dp(A.size());
        for(int i = 0; i < A.size(); i ++){

            int curMax = 0;
            for(int k = 1; k <= K && i - k + 1 >= 0; k ++){
                curMax = max(curMax, A[i - k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + curMax * k);
            }
        }
        return dp[A.size() - 1];
    }
};


int main() {

    return 0;
}