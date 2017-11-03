/// Source : https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
/// Author : liuyubobobo
/// Time   : 2017-11-03

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    int findNumberOfLIS(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        vector<int> dp(nums.size(), 0);
        vector<int> cnt(nums.size(), 0);

        int longest = 1;

        dp[0] = 1;
        cnt[0] = 1;
        for(int i = 1 ; i < nums.size() ; i ++){

            dp[i] = 1;
            for(int j = 0 ; j < i ; j ++)
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);

            longest = max(longest, dp[i]);

            cnt[i] = 0;
            for(int j = 0 ; j < i ; j ++)
                if(nums[j] < nums[i] && dp[j] + 1 == dp[i])
                    cnt[i] += cnt[j];

            if(cnt[i] == 0)
                cnt[i] = 1;
        }

//        cout << "dp : "; printVec(dp);
//        cout << "cnt: "; printVec(cnt);

        int res = 0;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(dp[i] == longest)
                res += cnt[i];

        return res;
    }

private:
    void printVec(const vector<int>& vec){
        for(int e: vec)
            cout << e << " ";
        cout << endl;
    }
};

int main() {

    int nums1[5] = {1, 3, 5, 4, 7};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().findNumberOfLIS(vec1) << endl;
    // 2

    // ---

    int nums2[5] = {2, 2, 2, 2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    cout << Solution().findNumberOfLIS(vec2) << endl;
    // 5

    // ---

    int nums3[8] = {1, 2, 4, 3, 5, 4, 7, 2};
    vector<int> vec3(nums3, nums3 + sizeof(nums3)/sizeof(int));
    cout << Solution().findNumberOfLIS(vec3) << endl;
    // 3

    return 0;
}