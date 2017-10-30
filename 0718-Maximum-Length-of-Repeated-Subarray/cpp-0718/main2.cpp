/// Source : https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
/// Author : liuyubobobo
/// Time   : 2017-10-19
#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
///
/// Time Complexity: O(len(A)*len(B))
/// Space Complexity: O(len(A)*len(B))
class Solution {

private:
    int dp[1001][1001];
public:
    int findLength(vector<int>& A, vector<int>& B) {

        for(int j = 0 ; j <= B.size() ; j ++)
            dp[A.size()][j] = 0;

        int best = 0;
        for(int i = A.size() - 1 ; i >= 0 ; i --)
            for(int j = B.size() - 1 ; j >= 0 ; j --)
                if(A[i] == B[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    best = max(best, dp[i][j]);
                }

        return best;
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