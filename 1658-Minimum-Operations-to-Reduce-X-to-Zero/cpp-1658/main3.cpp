/// Source : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
/// Author : liuyubobobo
/// Time   : 2020-11-15

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Two Pointer
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        int t = accumulate(nums.begin(), nums.end(), 0) - x, res = INT_MAX;

        int l = 0, r = -1, cur = 0;
        while(l < n){
            if(r + 1 < n && cur + nums[r + 1] <= t){
                cur += nums[r + 1];
                r ++;
                if(cur == t) res = min(res, n - (r - l + 1));
            }
            else
                cur -= nums[l ++];
        }
        return res == INT_MAX ? -1 : res;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 4, 2, 3};
    cout << Solution().minOperations(nums1, 5) << endl;
    // 2

    vector<int> nums2 = {5, 6, 7, 8, 9};
    cout << Solution().minOperations(nums2, 4) << endl;
    // -1

    vector<int> nums3 = {3,2,20,1,1,3};
    cout << Solution().minOperations(nums3, 10) << endl;
    // 5

    return 0;
}
