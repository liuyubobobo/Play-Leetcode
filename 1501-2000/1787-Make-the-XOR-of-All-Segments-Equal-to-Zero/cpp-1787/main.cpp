/// Source : https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/
/// Author : liuyubobobo
/// Time   : 2021-03-11

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DP
/// Time Complexity: O(LIMIT * k)
/// Space Complexity: O(LIMIT * k)
class Solution {

public:
    int minChanges(vector<int>& nums, int k) {

        vector<int> pow2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
        int LIMIT = *lower_bound(pow2.begin(), pow2.end(), *max_element(nums.begin(), nums.end())) * 2;

        vector<map<int, int>> f(k);
        vector<int> total(k, 0);
        for(int i = 0; i < nums.size(); i ++){
            total[i % k] ++;
            f[i % k][nums[i]] ++;
        }

        vector<vector<int>> dp(k, vector<int>(LIMIT));
        int premin = INT_MAX;
        for(int x = 0; x < LIMIT; x ++){
            dp[k - 1][x] = total[k - 1] - f[k - 1][x];
            premin = min(premin, dp[k - 1][x]);
        }

        for(int index = k - 2; index >= 0; index --){

            int curmin = total[index] + premin;
            for(int x = 0; x < LIMIT; x ++){
                dp[index][x] = total[index] + premin;

                for(const pair<int, int>& p: f[index]){
                    dp[index][x] = min(dp[index][x], total[index] - p.second + dp[index + 1][x ^ p.first]);
                    curmin = min(curmin, dp[index][x]);
                }
            }
            premin = curmin;
        }
        return dp[0][0];
    }
};


int main() {

    vector<int> nums1 = {1, 2, 0, 3, 0};
    cout << Solution().minChanges(nums1, 1) << endl;
    // 3

    vector<int> nums2 = {3,4,5,2,1,7,3,4,7};
    cout << Solution().minChanges(nums2, 3) << endl;
    // 3

    vector<int> nums3 = {26,19,19,28,13,14,6,25,28,19,0,15,25,11};
    cout << Solution().minChanges(nums3, 3) << endl;
    // 11

    vector<int> nums4 = {4,17,25,30,27,20,14,8,24,21,7,3,13,11,10,3,21,21,30,0,0};
    cout << Solution().minChanges(nums4, 13) << endl;
    // 8

    vector<int> nums5 = {231,167,89,85,224,180,45,58,23,108,157,95,108,64,206,109,147,28,194,17,4,46,74,96,237,109,114,122,161,76,181,251,9,82,44,15,242,7,23,109,210,109,181,12,14,226,61,49,8,74,19,152,4,137,243,27,187,200,168,145,188,203,98,193,253,133,164,198,132,119,148,146,94,43,181,123,212,83,157};
    cout << Solution().minChanges(nums5, 2) << endl;
    // 75

    vector<int> nums6 = {67,101,73,239,200,79,137,0,65,145,0,51,244,234,1,229,198,133,241,178,158,111,39,164,203,145,127,113,103,248,87,199,202,4,36,19,141,141,58,188,31,253,223,151,88,36,174,242,1,113,217,114,233,40,221,212,218,142,135,206,133,216,90,13,169,108,218,89,104,82,162,247,34,222,13,80,183,139,230,182,114,88,95,102,175,148,150,110,189,10,104,23,86,34,95,158,227,159,147,0,249,96,157,224,33,150,61,130,25,229,173,217,35,86,220,63,26,216,148,82,103,206,23,28,17,146,117,158,153,64,230,150,255,208,168,137,7,219,56,7,199,95,61,78,20,122,227,189,109,86,181,24,4,160,244,122,79,57,63,173,49,44,14,145,129,38,163,240,38,252,190,239,180,18,211,23,57,177,206,140,160,171,63,120,191,3,126,139,213,88,39,67,122,67,210,157,119,92,85,152,195,151,167,199,128,132,221,23,11,225,231,159,133,21,152,52,49,46,76,112,146,10,77};
    cout << Solution().minChanges(nums6, 75) << endl;
    // 147

    return 0;
}
