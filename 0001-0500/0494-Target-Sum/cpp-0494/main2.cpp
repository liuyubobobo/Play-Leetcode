/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : liuyubobobo
/// Time   : 2018-09-14

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Backtracking
/// Using Stack - Non-recursion solution
///
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        stack<int> indexStack, sumStack;
        indexStack.push(0);
        sumStack.push(0);
        int res = 0, index, sum;
        while(!indexStack.empty()){
            index = indexStack.top();
            sum = sumStack.top();
            indexStack.pop();
            sumStack.pop();

            if(index + 1 == nums.size())
                res += (sum + nums[index] == S) + (sum - nums[index] == S);
            else{
                indexStack.push(index + 1);
                sumStack.push(sum + nums[index]);
                indexStack.push(index + 1);
                sumStack.push(sum - nums[index]);
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;

    return 0;
}