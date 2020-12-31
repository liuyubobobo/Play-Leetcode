/// Source : https://leetcode.com/problems/partition-array-for-maximum-sum/
/// Author : liuyubobobo
/// Time   : 2019-05-11

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(|A|^2)
/// Space Complexity :O(|A|)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {

        vector<int> dp(A.size(), -1);
        return dfs(A, 0, K, dp);
    }

private:
    int dfs(const vector<int>& A, int start, int K, vector<int>& dp){

        if(start == A.size()) return 0;
        if(dp[start] != -1) return dp[start];

        int maxv = A[start];
        int res = 0;
        for(int end = start; end <= min(start + K - 1, (int)A.size() - 1); end ++){
            maxv = max(maxv, A[end]);
            res = max(res, maxv * (end - start + 1) + dfs(A, end + 1, K, dp));
        }
        return dp[start] = res;
    }
};


int main() {

    return 0;
}