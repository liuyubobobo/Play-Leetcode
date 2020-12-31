/// Source : https://leetcode.com/problems/shuffle-the-array/
/// Author : liuyubobobo
/// Time   : 2020-06-08

#include <iostream>
#include <vector>

using namespace std;


/// Using the higher bits to store the numbers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        for(int i = 0; i < 2 * n; i ++){
            int j = i < n ? 2 * i : 2 * (i - n) + 1;
            nums[j] |= (nums[i] & 1023) << 10;
        }
        for(int& e: nums) e >>= 10;
        return nums;
    }
};


int main() {

    return 0;
}
