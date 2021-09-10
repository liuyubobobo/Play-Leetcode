/// Source : https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
/// Author : liuyubobobo
/// Time   : 2021-02-19

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {

        int n = A.size();
        if(n < 3) return 0;

        vector<map<long long, int>> dp(n);
        for(int i = 1; i < n; i ++){
            for(int j = i - 1; j >= 0; j --){
                long long d = (long long)A[i] - A[j];
                if(dp[j].count(d))
                    dp[i][d] += dp[j][d] + 1;
                else
                    dp[i][d] += 1;
//                cout << i << " " << d << " : " << dp[i][d] << endl;
            }
        }

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(const pair<long long, int>& p: dp[i]) res += p.second;

        return res - n * (n - 1) / 2;
    }
};


int main() {

    vector<int> nums1 = {2, 4, 6, 8, 10};
    cout << Solution().numberOfArithmeticSlices(nums1) << endl;
    // 7

    vector<int> nums2 = {0, 1, 2, 3, 4, 5};
    cout << Solution().numberOfArithmeticSlices(nums2) << endl;
    // 12

    vector<int> nums3 = {2, 2, 3, 4};
    cout << Solution().numberOfArithmeticSlices(nums3) << endl;
    // 2

    vector<int> nums4 = {1, 1, 1, 1};
    cout << Solution().numberOfArithmeticSlices(nums4) << endl;
    // 5

    vector<int> nums5 = {0,2000000000,-294967296};
    cout << Solution().numberOfArithmeticSlices(nums5) << endl;
    // 0

    return 0;
}
