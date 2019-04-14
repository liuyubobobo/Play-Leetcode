/// Source : https://leetcode.com/problems/longest-arithmetic-sequence/
/// Author : liuyubobobo
/// Time   : 2019-04-13

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

public:
    int longestArithSeqLength(vector<int>& A) {

        unordered_map<int, unordered_map<int, int>> dp;

        int res = 2;
        for(int i = 0; i < A.size(); i ++)
            for(int j = i + 1; j < A.size(); j ++){
                dp[A[j] - A[i]][j] = max(dp[A[j] - A[i]][j], dp[A[j] - A[i]][i] + 1);
                res = max(res, dp[A[j] - A[i]][j]);
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