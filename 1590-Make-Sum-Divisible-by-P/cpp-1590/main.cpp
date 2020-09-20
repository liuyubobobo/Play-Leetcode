/// Source : https://leetcode.com/problems/make-sum-divisible-by-p/
/// Author : liuyubobobo
/// Time   : 2020-09-19

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;


/// Hash Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long sum = 0;
        for(int e: nums) sum += (long long)e;
        long long mod = sum % (long long)p;

        if(mod == 0ll) return 0;

        int res = nums.size();
        unordered_map<long long, int> table;
        table[0ll] = -1;

        sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum += (long long)nums[i];
            long long curmod = sum % (long long)p;
            table[curmod] = i;

            long long targetmod = curmod >= mod ? (curmod - mod) : (curmod - mod + p);
            if(table.count(targetmod))
                res = min(res, i - table[targetmod]);
        }
        return res == nums.size() ? -1 : res;
    }
};


int main() {

    vector<int> nums1 = {3, 1, 4, 2};
    cout << Solution().minSubarray(nums1, 6) << endl;
    // 1

    vector<int> nums2 = {6, 3, 5, 2};
    cout << Solution().minSubarray(nums2, 9) << endl;
    // 2

    vector<int> nums3 = {1, 2, 3};
    cout << Solution().minSubarray(nums3, 3) << endl;
    // 0

    vector<int> nums4 = {1, 2, 3};
    cout << Solution().minSubarray(nums4, 7) << endl;
    // -1

    vector<int> nums5 = {1000000000,1000000000,1000000000};
    cout << Solution().minSubarray(nums5, 3) << endl;
    // 0

    return 0;
}
