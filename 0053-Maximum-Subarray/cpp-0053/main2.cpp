/// Source : https://leetcode.com/problems/maximum-subarray/
/// Author : liuyubobobo
/// Time   : 2020-04-03

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int res = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i ++){
            if(sum + nums[i] < nums[i]) sum = nums[i];
            else sum += nums[i];
            res = max(res, sum);
        }
        return res;
    }
};


int main() {

    return 0;
}
