/// Source : https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>
#include <vector>

using namespace std;


/// 2D presum + sorting
/// Time Complexity: O(R * C + R * C * log(R * C))
/// Space Complexity: O(R * C)
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {

        int R = matrix.size(), C = matrix[0].size();

        vector<vector<int>> dp(R, vector<int>(C, 0));
        dp[0][0] = matrix[0][0];

        vector<int> v = {dp[0][0]};
        for(int j = 1; j < C; j ++){
            dp[0][j] = dp[0][j - 1] ^ matrix[0][j];
            v.push_back(dp[0][j]);
        }
        for(int i = 1; i < R; i ++){
            dp[i][0] = dp[i - 1][0] ^ matrix[i][0];
            v.push_back(dp[i][0]);
        }

        for(int i = 1; i < R; i ++)
            for(int j = 1; j < C; j ++){
                dp[i][j] = matrix[i][j] ^ dp[i - 1][j] ^ dp[i][j - 1] ^ dp[i - 1][j - 1];
                v.push_back(dp[i][j]);
            }

        sort(v.begin(), v.end(), greater<int>());
        return v[k - 1];
    }
};


int main() {

    vector<vector<int>> m1 = {
            {5, 2}, {1, 6}
    };
    cout << Solution().kthLargestValue(m1, 1) << endl;
    // 7

    vector<vector<int>> m2 = {
            {5, 2}, {1, 6}
    };
    cout << Solution().kthLargestValue(m2, 2) << endl;
    // 5

    vector<vector<int>> m3 = {
            {5, 2}, {1, 6}
    };
    cout << Solution().kthLargestValue(m3, 3) << endl;
    // 4

    vector<vector<int>> m4 = {
            {5, 2}, {1, 6}
    };
    cout << Solution().kthLargestValue(m4, 4) << endl;
    // 0

    return 0;
}
