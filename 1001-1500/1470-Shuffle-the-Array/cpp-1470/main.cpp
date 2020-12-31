/// Source : https://leetcode.com/problems/shuffle-the-array/
/// Author : liuyubobobo
/// Time   : 2020-06-06

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        vector<int> res(2 * n);
        for(int i = 0, j = 0; i < n; i ++)
            res[j ++] = nums[i], res[j ++] = nums[n + i];
        return res;
    }
};


int main() {

    return 0;
}
