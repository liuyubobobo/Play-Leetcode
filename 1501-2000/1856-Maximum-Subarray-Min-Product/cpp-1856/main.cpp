/// Source : https://leetcode.com/problems/maximum-subarray-min-product/
/// Author : liuyubobobo
/// Time   : 2021-05-08

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int maxSumMinProduct(vector<int>& nums) {

        vector<int> right(nums.size(), nums.size());
        stack<int> stack;
        for(int i = 0; i < nums.size(); i ++){
            while(!stack.empty() && nums[i] < nums[stack.top()])
                right[stack.top()] = i, stack.pop();
            stack.push(i);
        }

//        cout << "right : ";
//        for(int e: right) cout << e << " "; cout << endl;

        vector<int> left(nums.size(), -1);
        while(!stack.empty()) stack.pop();
        for(int i = nums.size() - 1; i >= 0; i --){
            while(!stack.empty() && nums[i] < nums[stack.top()])
                left[stack.top()] = i, stack.pop();
            stack.push(i);
        }

//        cout << "left : ";
//        for(int e: left) cout << e << " "; cout << endl;

        vector<long long> presum(nums.size() + 1, 0ll);
        for(int i = 0; i < nums.size(); i ++)
            presum[i + 1] = presum[i] + nums[i];

        long long res = -1ll;
        for(int i = 0; i < nums.size(); i ++){
            int l = left[i] + 1, r = right[i] - 1;
            res = max(res, (presum[r + 1] - presum[l]) * nums[i]);
        }

        return res % MOD;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 2};
    cout << Solution().maxSumMinProduct(nums1) << endl;
    // 14

    vector<int> nums2 = {2, 3, 3, 1, 2};
    cout << Solution().maxSumMinProduct(nums2) << endl;
    // 18

    vector<int> nums3 = {3, 1, 5, 6, 4, 2};
    cout << Solution().maxSumMinProduct(nums3) << endl;
    // 60

    return 0;
}
