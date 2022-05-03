/// Source : https://leetcode.com/problems/minimum-average-difference/
/// Author : liuyubobobo
/// Time   : 2022-05-03

#include <iostream>
#include <vector>
#include <numeric>
#include <climits>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Compelxity: O(1)
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        int n = nums.size();

        long long sum = accumulate(nums.begin(), nums.end(), 0ll);

        long long min_diff = LONG_LONG_MAX, pre = 0ll, post = sum;
        int res = n - 1;
        for(int i = 0; i < n; i ++){
            pre += nums[i];
            post -= nums[i];

            long long t = abs(pre / (i + 1) - (n - i - 1 == 0 ? 0 : post / (n - i - 1)));
//            cout << i << ' ' << t << '\n';
            if(t < min_diff) res = i, min_diff = t;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, 5, 3, 9, 5, 3};
    cout << Solution().minimumAverageDifference(nums1) << '\n';
    // 3

    vector<int> nums2 = {4, 2, 0};
    cout << Solution().minimumAverageDifference(nums2) << '\n';
    // 2

    return 0;
}
