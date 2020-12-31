/// Source : https://leetcode.com/problems/missing-number/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// minus sum
/// Time Complexity:  O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        return n * (n+1) / 2 - accumulate(nums.begin(), nums.end(), 0);
    }
};

int main() {

    int nums[3] = {0, 1, 3};
    vector<int> vec(nums, nums + 3);
    cout << Solution().missingNumber(vec) << endl;

    return 0;
}