/// Source : https://leetcode.com/problems/array-partition-i/solution/
/// Author : liuyubobobo
/// Time   : 2018-06-04

#include <iostream>
#include <vector>

using namespace std;

/// Sort
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i += 2)
            sum += nums[i];
        return sum;
    }
};


int main() {

    vector<int> nums = {1, 4, 3, 2};
    cout << Solution().arrayPairSum(nums) << endl;

    return 0;
}