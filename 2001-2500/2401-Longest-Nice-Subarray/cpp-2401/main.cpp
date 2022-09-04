/// Source : https://leetcode.com/problems/longest-nice-subarray/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> bits(30, vector<int>(n, 0));
        for(int i = 0; i < n; i ++){
            for(int p = 0; p < 30; p ++)
                bits[p][i] = ((nums[i] >> p) & 1);
        }

        vector<vector<int>> presum(30, vector<int>(n + 1, 0));
        for(int p = 0; p < 30; p ++)
            for(int i = 0; i < n; i ++)
                presum[p][i + 1] = presum[p][i] + bits[p][i];

        int res = 0;
        for(int start = 0; start < n; start ++){
            int end_l = start, end_r = n - 1;
            while(end_l < end_r){
                int end_mid = (end_l + end_r + 1) / 2;
                if(ok(presum, start, end_mid)) end_l = end_mid;
                else end_r = end_mid - 1;
            }
            res = max(res, end_l - start + 1);
        }
        return res;
    }

private:
    bool ok(const vector<vector<int>>& presum, int start, int end){

        for(int p = 0; p < 30; p ++){
            int t = presum[p][end + 1] - presum[p][start];
            if(t > 1) return false;
        }
        return true;
    }
};


int main() {

    vector<int> nums1 = {1, 3, 8, 48, 10};
    cout << Solution().longestNiceSubarray(nums1) << '\n';
    // 3

    vector<int> nums2 = {3, 1, 5, 11, 13};
    cout << Solution().longestNiceSubarray(nums2) << '\n';
    // 1

    return 0;
}
