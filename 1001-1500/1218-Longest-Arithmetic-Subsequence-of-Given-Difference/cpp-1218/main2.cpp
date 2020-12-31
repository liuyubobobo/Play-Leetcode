/// Source : https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Dynamic Programming
/// More Concise Logic
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {

        map<int, int> dp;
        int res = 1;
        for(int i = 0; i < arr.size(); i ++){
            dp[arr[i]] = max(dp[arr[i]], dp[arr[i] - difference] + 1);
            res = max(res, dp[arr[i]]);
        }
        return res;
    }
};


int main() {

    vector<int> arr1 = {1,2,3,4};
    cout << Solution().longestSubsequence(arr1, 1) << endl;
    // 4

    vector<int> arr2 = {1,3,5,7};
    cout << Solution().longestSubsequence(arr2, 1) << endl;
    // 1

    vector<int> arr3 = {1,5,7,8,5,3,4,2,1};
    cout << Solution().longestSubsequence(arr3, -2) << endl;
    // 4

    return 0;
}