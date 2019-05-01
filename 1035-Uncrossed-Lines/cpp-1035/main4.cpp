/// Source : https://leetcode.com/problems/uncrossed-lines/
/// Author : liuyubobobo
/// Time   : 2019-04-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Dynamic Programming
/// It's actualy The Longest Common Subsequence Problem
/// 1-D Dynamic Programming
///
/// Time Complexity: O(|A| * |B|)
/// Space Complexity: O(|B|)
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {

        vector<int> dp(B.size() + 1, 0);
        for(int i = 1; i <= A.size(); i ++){
            for(int j = B.size(); j >= 1; j --)
                if(A[i - 1] == B[j - 1])
                    dp[j] = 1 + dp[j - 1];
            for(int j = 1; j <= B.size(); j ++)
                dp[j] = max(dp[j], dp[j - 1]);
        }

        return dp[B.size()];
    }
};


int main() {

    vector<int> A1 = {3};
    vector<int> B1 = {3, 3, 2};
    cout << Solution().maxUncrossedLines(A1, B1) << endl;
    // 1

    vector<int> A2 = {2, 5, 1, 2, 5};
    vector<int> B2 = {10, 5, 2, 1, 5, 2};
    cout << Solution().maxUncrossedLines(A2, B2) << endl;
    // 3

    vector<int> A3 = {1, 4, 2};
    vector<int> B3 = {1, 2, 4};
    cout << Solution().maxUncrossedLines(A3, B3) << endl;
    // 2

    return 0;
}