/// Source : https://leetcode.com/problems/minimum-operations-to-make-numbers-non-positive/description/
/// Author : liuyubobobo
/// Time   : 2023-05-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(max(nums)))
/// Space Complexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {

        long long l = 0, r = *max_element(nums.begin(), nums.end());
        while(l < r){
            long long mid = (l + r) / 2;
            if(ok(nums, x, y, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(vector<int>& nums, long long x, long long y, long long k) {

        long long cnt = 0;
        for (long long e: nums) {
            e -= k * y;
            if (e <= 0) continue;
            cnt += e / (x - y) + !!(e % (x - y));
        }
        return cnt <= k;
    }
};


int main() {

    vector<int> nums1 = {3, 4, 1, 7, 6};
    cout << Solution().minOperations(nums1, 4, 2) << '\n';
    // 3

    vector<int> nums2 = {1, 2, 1};
    cout << Solution().minOperations(nums2, 2, 1) << '\n';
    // 1

    vector<int> nums3 = {74, 92, 25, 65, 77, 1, 73};
    cout << Solution().minOperations(nums3, 10, 4) << '\n';
    // 16

    return 0;
}
