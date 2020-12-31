/// Source : https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
/// Author : liuyubobobo
/// Time   : 2018-12-16

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Using keep which columns as the state :-)
/// Time Complexity: O(m * n * n)
/// Space Complexity: O(n)
class Solution {

private:
    int m, n;

public:
    int minDeletionSize(vector<string>& A) {

        m = A.size();
        n = A[0].size();
        vector<int> dp(n, -1);
        for(int i = 0; i < n; i ++)
            dfs(A, i, dp);

        return n - *max_element(dp.begin(), dp.end());
    }

private:
    int dfs(const vector<string>& A, int index, vector<int>& dp){

        if(index == 0)
            return dp[index] = 1;

        if(dp[index] != -1)
            return dp[index];

        int res = 1;
        for(int j = index - 1; j >= 0; j --) {
            bool ok = true;
            for(int i = 0; i < m; i ++)
                if (A[i][index] < A[i][j]) {
                    ok = false;
                    break;
                }
                if (ok)
                    res = max(res, 1 + dfs(A, j, dp));
        }
        return dp[index] = res;
    }
};


int main() {

    vector<string> A1 = {"babca","bbazb"};
    cout << Solution().minDeletionSize(A1) << endl;
    // 3

    vector<string> A2 = {"abbba"};
    cout << Solution().minDeletionSize(A2) << endl;
    // 1

    return 0;
}