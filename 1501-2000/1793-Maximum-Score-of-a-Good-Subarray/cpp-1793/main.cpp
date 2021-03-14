/// Source : https://leetcode.com/problems/maximum-score-of-a-good-subarray/
/// Author : liuyubobobo
/// Time   : 2021-03-14

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int> right(n);
        stack<int> stack;
        for(int i = 0; i < n; i ++){
            while(!stack.empty() && nums[i] < nums[stack.top()])
                right[stack.top()] = i - 1, stack.pop();
            stack.push(i);
        }
        while(!stack.empty()) right[stack.top()] = n - 1, stack.pop();

        vector<int> left(n);
        for(int i = n - 1; i >= 0; i --){
            while(!stack.empty() && nums[i] < nums[stack.top()])
                left[stack.top()] = i + 1, stack.pop();
            stack.push(i);
        }
        while(!stack.empty()) left[stack.top()] = 0, stack.pop();

        int res = 0;
        for(int i = 0; i < n; i ++)
            if(left[i] <= k && k <= right[i])
                res = max(res, nums[i] * (right[i] - left[i] + 1));
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 4, 3, 7, 4, 5};
    cout << Solution().maximumScore(nums1, 3) << endl;
    // 15

    vector<int> nums2 = {5,5,4,5,4,1,1,1};
    cout << Solution().maximumScore(nums2, 0) << endl;
    // 20

    vector<int> nums3 = {6569,9667,3148,7698,1622,2194,793,9041,1670,1872};
    cout << Solution().maximumScore(nums3, 5) << endl;
    // 9732

    return 0;
}
