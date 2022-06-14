/// Source : https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
/// Author : liuyubobobo
/// Time   : 2022-06-14

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(log(max_dis) * nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums[0];
        while(l < r){
            int d = (l + r) / 2;
            if(dis_cnt_less_than_or_equal_to(n, nums, d) >= k) r = d;
            else l = d + 1;
        }
        return l;
    }

private:
    int dis_cnt_less_than_or_equal_to(int n, const vector<int>& nums, int d){

        int cnt = 0;
        for(int i = 0; i < n; i ++){
            auto iter = upper_bound(nums.begin(), nums.end(), nums[i] + d);
            cnt += iter - nums.begin() - i - 1;
        }
        return cnt;
    }
};


int main() {

    vector<int> nums1 = {1, 3, 1};
    cout << Solution().smallestDistancePair(nums1, 1) << endl;
    // 0

    vector<int> nums2 = {1, 1, 1};
    cout << Solution().smallestDistancePair(nums2, 2) << endl;
    // 0

    vector<int> nums3 = {1, 6, 1};
    cout << Solution().smallestDistancePair(nums3, 3) << endl;
    // 5

    return 0;
}