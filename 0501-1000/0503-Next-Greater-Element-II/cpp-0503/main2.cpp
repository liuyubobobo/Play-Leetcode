/// Source : https://leetcode.com/problems/next-greater-element-ii/
/// Author : liuyubobobo
/// Time   : 2021-03-05

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Mono Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n, -1);

        for(int i = 0; i < n; i ++)
            nums.push_back(nums[i]);

        stack<int> stack;
        for(int i = 0; i < nums.size(); i ++){
            while(!stack.empty() && nums[i] > nums[stack.top()]){
                if(stack.top() < n) res[stack.top()] = nums[i];
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }
};


int main() {

    return 0;
}
