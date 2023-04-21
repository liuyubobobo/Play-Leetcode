/// Source : https://leetcode.com/problems/longest-arithmetic-sequence/
/// Author : liuyubobobo
/// Time   : 2019-04-13
/// Updated: 2023-04-13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

private:
    const int offset = 500;

public:
    int longestArithSeqLength(vector<int>& A) {

        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(1001, 1));

        int res = 1;
        for(int i = 1; i < n; i ++)
            for(int j = i - 1; j >= 0; j --){
                int d = A[i] - A[j] + offset;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                res = max(res, dp[i][d]);
            }

        return res;
    }
};


int main() {

    vector<int> A1 = {3, 6, 9, 12};
    cout << Solution().longestArithSeqLength(A1) << endl; // 4

    vector<int> A2 = {9, 4, 7, 2, 10};
    cout << Solution().longestArithSeqLength(A2) << endl; // 3

    vector<int> A3 = {20,1,15,3,10,5,8};
    cout << Solution().longestArithSeqLength(A3) << endl; // 4

    return 0;
}