/// Source : https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
/// Author : liuyubobobo
/// Time   : 2021-05-19

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {

        long long sum = 0ll, n = nums.size(), minv = nums[0];

        for(long long e: nums){
            sum += e;
            minv = min(minv, e);
        }
        return sum - minv * n;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3};
    cout << Solution().minMoves(nums1) << endl;
    // 3

    vector<int> nums2 = {1, 2};
    cout << Solution().minMoves(nums2) << endl;
    // 1

    vector<int> nums3 = {1, (int)1e9};
    cout << Solution().minMoves(nums3) << endl;
    // 999999999

    return 0;
}
