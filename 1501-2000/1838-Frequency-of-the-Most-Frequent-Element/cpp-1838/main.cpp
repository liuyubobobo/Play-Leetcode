/// Source : https://leetcode.com/problems/frequency-of-the-most-frequent-element/
/// Author : liuyubobobo
/// Time   : 2021-04-24

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(nlogn)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        vector<long long> presum(nums.size() + 1, 0ll);
        for(int i = 0; i < nums.size(); i ++)
            presum[i + 1] = presum[i] + nums[i];

        int res = 0;
        for(int i = 0; i < nums.size(); i ++)
            res = max(res, solve(nums, i, k, presum));
        return res;
    }

private:
    int solve(const vector<int>& nums, int start, int k, const vector<long long>& presum){

        int l = start, r = nums.size() - 1;
        while(l < r){

            int mid = (l + r + 1) / 2;
            if((long long)nums[mid] * (mid - start + 1) - (presum[mid + 1] - presum[start]) <= (long long)k)
                l = mid;
            else
                r = mid - 1;
        }
        return r - start + 1;
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
