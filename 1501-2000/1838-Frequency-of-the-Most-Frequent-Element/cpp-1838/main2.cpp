/// Source : https://leetcode.com/problems/frequency-of-the-most-frequent-element/
/// Author : liuyubobobo
/// Time   : 2021-04-24

#include <iostream>
#include <vector>

using namespace std;


/// Sliding Windows
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int l = 0, r = -1, res = 0;
        long long sum = 0ll;
        while(l < nums.size()){
            if(r + 1 < nums.size() && (long long)nums[r + 1] * (r - l + 2) - (sum + nums[r + 1]) <= k){
                r ++;
                res = max(res, r - l + 1);
                sum += nums[r];
            }
            else{
                sum -= nums[l];
                l ++;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 4};
    cout << Solution().maxFrequency(nums1, 5) << endl;
    // 3

    vector<int> nums2 = {1, 4, 8, 13};
    cout << Solution().maxFrequency(nums2, 5) << endl;
    // 2

    vector<int> nums3 = {3, 9, 6};
    cout << Solution().maxFrequency(nums3, 2) << endl;
    // 1

    return 0;
}
