/// Source : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// Sliding Window + Mono Queue
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        deque<int> inc = {0}, dec = {0};
        int res = 1;
        for(int l = 0, i = 1; i < nums.size(); i ++){
            while(!inc.empty() && nums[i] < nums[inc.back()]) inc.pop_back();
            inc.push_back(i);

            while(!dec.empty() && nums[i] > nums[dec.back()]) dec.pop_back();
            dec.push_back(i);

            if(abs(nums[inc.front()] - nums[dec.front()]) <= limit)
                res = max(res, i - l + 1);
            else{
                while(!inc.empty() && !dec.empty() && abs(nums[inc.front()] - nums[dec.front()]) > limit){
                    if(!inc.empty() && inc.front() == l) inc.pop_front();
                    if(!dec.empty() && dec.front() == l) dec.pop_front();
                    l ++;
                }
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {8, 2, 4, 7};
    cout << Solution().longestSubarray(nums1, 4) << endl;
    // 2

    vector<int> nums2 = {10,1,2,4,7,2};
    cout << Solution().longestSubarray(nums2, 5) << endl;
    // 4

    vector<int> nums3 = {4,2,2,2,4,4,2,2};
    cout << Solution().longestSubarray(nums3, 0) << endl;
    // 3

    vector<int> nums4 = {4,10,2,6,1};
    cout << Solution().longestSubarray(nums4, 10) << endl;
    // 5

    return 0;
}
