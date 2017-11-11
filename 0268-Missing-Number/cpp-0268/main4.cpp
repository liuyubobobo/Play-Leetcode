/// Source : https://leetcode.com/problems/missing-number/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Using XOR
/// Time Complexity:  O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 1 ; i <= nums.size() ; i ++)
            res ^= i;
        for(int num: nums)
            res ^= num;
        return res;
    }
};

int main() {

    int nums[3] = {0, 1, 3};
    vector<int> vec(nums, nums + 3);
    cout << Solution().missingNumber(vec) << endl;

    return 0;
}