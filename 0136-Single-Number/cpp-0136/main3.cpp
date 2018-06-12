/// Source : https://leetcode.com/problems/single-number/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Using the attribution of xor operation:
/// a ^ 0 = a
/// a ^ a = 0
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        assert(nums.size()%2 == 1);

        int res = 0;
        for(int i = 0 ; i < nums.size() ; i ++)
            res ^= nums[i];
        return res;
    }
};


int main() {

    vector<int> nums = {0, 0, 1, 1, 2};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}