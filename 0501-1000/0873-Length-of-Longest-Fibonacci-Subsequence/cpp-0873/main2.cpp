/// Source : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2018-07-21

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

private:
    int n;
    unordered_map<int, int> num_index;

public:
    int lenLongestFibSubseq(vector<int>& A) {

        n = A.size();
        num_index.clear();
        for(int i = 0 ; i < A.size() ; i ++)
            num_index[A[i]] = i;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int res = 0;
        for(int i = 1; i < n; i ++)
            for(int j = i + 1; j < n ; j ++)
                res = max(res, getRes(A, i, j, dp));
        return res == 2 ? 0 : res;
    }

private:
    int getRes(const vector<int>& A, int a, int b, vector<vector<int>>& dp){

        if(dp[a][b] != -1)
            return dp[a][b];

        if(A[b] - A[a] < A[a] && num_index.find(A[b] - A[a]) != num_index.end())
            return dp[a][b] = 1 + getRes(A, num_index[A[b] - A[a]], a, dp);
        return 2;
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