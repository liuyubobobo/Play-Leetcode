/// Source : https://leetcode.com/problems/rotate-function/
/// Author : liuyubobobo
/// Time   : 2022-04-21

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int n = nums.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        int cur = 0;
        for(int i = 0; i < n; i ++) cur += i * nums[i];

        int res = cur;
        for(int i = 1; i < n; i ++){
            cur -= presum[n] - presum[i];
            cur -= presum[i - 1];
            cur += (n - 1) * nums[i - 1];
            res = max(res, cur);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {4, 3, 2, 6};
    cout << Solution().maxRotateFunction(nums1) << '\n';
    // 26

    return 0;
}
