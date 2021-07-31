/// Source : https://leetcode.com/problems/maximum-of-minimum-values-in-all-subarrays/
/// Author : liuyubobobo
/// Time   : 2021-07-02

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {

        int n = nums.size();

        stack<int> stack;
        vector<int> left(n, -1);
        stack.push(0);
        for(int i = 1; i < n; i ++){
            while(!stack.empty() && nums[stack.top()] >= nums[i])
                stack.pop();
            left[i] = stack.empty() ? -1: stack.top();
            stack.push(i);
        }
//        for(int e: left) cout << e << ' '; cout << endl;

        while(!stack.empty()) stack.pop();

        vector<int> right(n, n);
        stack.push(n - 1);
        for(int i = n - 2; i >= 0; i --){
            while(!stack.empty() && nums[stack.top()] >= nums[i])
                stack.pop();
            right[i] = stack.empty() ? n: stack.top();
            stack.push(i);
        }
//        for(int e: right) cout << e << ' '; cout << endl;

        vector<int> res(n, *min_element(nums.begin(), nums.end()));
        for(int i = 0; i < n; i ++){
            int v = nums[i], d = right[i] - left[i] - 1;
            res[d - 1] = max(res[d - 1], v);
        }

        for(int i = n - 2; i >= 0; i --)
            res[i] = max(res[i], res[i + 1]);
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {0, 1, 2, 4};
    print_vec(Solution().findMaximums(nums1));
    // 4 2 1 0

    vector<int> nums2 = {10, 20, 50, 10};
    print_vec(Solution().findMaximums(nums2));
    // 50 20 10 10

    vector<int> nums3 = {10, 20, 10, 50, 10};
    print_vec(Solution().findMaximums(nums3));
    // 50 10 10 10 10

    vector<int> nums4 = {10, 2, 8, 3, 2, 7, 6, 4, 10, 8};
    print_vec(Solution().findMaximums(nums4));
    // 10,8,4,4,4,2,2,2,2,2

    vector<int> nums5 = {0, 9, 5, 7, 0, 1, 5, 4, 3};
    print_vec(Solution().findMaximums(nums5));
    // 9,5,5,1,0,0,0,0,0

    vector<int> nums6 = {1, 5, 5, 1};
    print_vec(Solution().findMaximums(nums6));
    // 5, 5, 1, 1

    return 0;
}
