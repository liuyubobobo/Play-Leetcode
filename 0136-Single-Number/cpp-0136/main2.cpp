/// Source : https://leetcode.com/problems/single-number/
/// Author : liuyubobobo
/// Time   : 2018-06-11

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
#include <numeric>

using namespace std;


/// Using the sum of vector and the sum of set
/// mathematically get the result
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        assert(nums.size()%2 == 1);

        unordered_set<int> set;
        for(int num: nums)
            set.insert(num);

        return 2 * accumulate(set.begin(), set.end(), 0) - accumulate(nums.begin(), nums.end(), 0);
    }
};


int main() {

    vector<int> nums = {0, 0, 1, 1, 2};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}