/// Source : https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {

        int res = 0;
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] <= nums[i - 1]){
                res += 1 + nums[i - 1] - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
