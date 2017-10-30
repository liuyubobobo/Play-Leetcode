/// Source : https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
/// Author : liuyubobobo
/// Time   : 2017-10-19
#include <iostream>
#include <vector>

using namespace std;

/// Memory Search
///
/// Time Complexity: O(len(A)*len(B))
/// Space Complexity: O(len(A)*len(B))
class Solution {
private:
    int dp[1001][1001];

public:
    int findLength(vector<int>& A, vector<int>& B) {

        for(int i = 0 ; i < A.size() ; i ++)
            for(int j = 0 ; j < B.size() ; j ++)
                dp[i][j] = -1;

        int best = 0;
        for(int i = 0 ; i < A.size() ; i ++)
            for(int j = 0 ; j < B.size() ; j ++ ){
                if(dp[i][j] == -1)
                    dp[i][j] = solve(A, B, i, j);
                best = max(best, dp[i][j]);
            }

        return best;
    }

private:
    int solve(const vector<int>& A, const vector<int>& B, int i, int j){

        if(i == A.size() || j == B.size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(A[i] != B[j])
            return dp[i][j] = 0;

        return dp[i][j] = 1 + solve(A, B, i+1, j+1);
    }
};

int main() {

    int numsA[] = {1, 2, 3, 2, 1};
    vector<int> vecA(numsA, numsA + sizeof(numsA)/sizeof(int));

    int numsB[] = {3, 2, 1, 4, 7};
    vector<int> vecB(numsB, numsB + sizeof(numsB)/sizeof(int));

    cout << Solution().findLength(vecA, vecB) << endl;

    return 0;
}