/// Source : https://leetcode.com/problems/majority-element/description/
/// Author : liuyubobobo
/// Time   : 2017-11-14

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Boyer-Moore Voting Algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        assert(nums.size() > 0);

        int count = 0;
        int res = -1;
        for(int num: nums){
            if(count == 0)
                res = num;

            count += (res == num) ? 1 : -1;
        }

        return res;
    }
};

int main() {

    int nums[1] = {1};
    vector<int> vec(nums, nums + 1);
    cout << Solution().majorityElement(vec) << endl;
    return 0;
}