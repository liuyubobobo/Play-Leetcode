/// Source : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2018-07-21
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

public:
    int lenLongestFibSubseq(vector<int>& A) {

        int n = A.size();
        unordered_map<int, int> num_index;
        for(int i = 0 ; i < A.size() ; i ++)
            num_index[A[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int res = 0;

        for(int j = 2; j < n ; j ++)
            if(A[0] + A[1] == A[j]){
                dp[1][j] = 3;
                res = max(res, 3);
            }

        for(int i = 2; i < n ; i ++)
            for(int j = i + 1; j < n ; j ++){
                if(A[j] - A[i] < A[i] && num_index.find(A[j] - A[i]) != num_index.end()) {
                    dp[i][j] = dp[num_index[A[j] - A[i]]][i] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << Solution().lenLongestFibSubseq(nums1) << endl;
    // 5

    vector<int> nums2 = {1, 3, 7, 11, 12, 14, 18};
    cout << Solution().lenLongestFibSubseq(nums2) << endl;
    // 3

    vector<int> nums3 = {2, 4, 5, 6, 7, 8, 11, 13, 14, 15, 21, 22, 34};
    cout << Solution().lenLongestFibSubseq(nums3) << endl;
    // 5

    return 0;
}