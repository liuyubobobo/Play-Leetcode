/// Source : https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
/// Author : liuyubobobo
/// Time   : 2020-04-04

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> res;
        int cur = 0;
        for(int e: nums){
            cur += e;
            res.push_back(e);
            if(cur > sum - cur) break;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {4, 3, 10, 9, 8};
    print_vec(Solution().minSubsequence(nums1));
    // 10 9

    vector<int> nums2 = {4, 4, 7, 6, 7};
    print_vec(Solution().minSubsequence(nums2));
    // 7 7 6

    vector<int> nums3 = {6};
    print_vec(Solution().minSubsequence(nums3));
    // 6

    return 0;
}
