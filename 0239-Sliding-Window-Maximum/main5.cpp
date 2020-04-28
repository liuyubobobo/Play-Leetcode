/// Source : https://leetcode.com/problems/sliding-window-maximum/description/
/// Author : liuyubobobo
/// Time   : 2019-03-09

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        if(k == 0 || n == 0)
            return vector<int>();

        if(k == 1)
            return nums;

        vector<int> right(n);
        int cur = nums[0];
        for(int i = 0; i < n; i ++){
            if(i % k == 0) cur = nums[i];
            else cur = max(cur, nums[i]);
            right[i] = cur;
        }

        vector<int> left(n);
        cur = nums[n - 1];
        for(int i = n - 1; i >= 0; i --){
            if(i % k == k - 1) cur = nums[i];
            else cur = max(cur, nums[i]);
            left[i] = cur;
        }

        vector<int> res(n - k + 1);
        for(int i = 0; i <= n - k; i ++)
            res[i] = max(left[i], right[min(i + k - 1, n - 1)]);

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    print_vec(Solution().maxSlidingWindow(nums, 3));
    // 3 3 5 5 6 7

    return 0;
}