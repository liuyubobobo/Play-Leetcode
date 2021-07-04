/// Source : https://leetcode.com/problems/build-array-from-permutation/
/// Author : liuyubobobo
/// Time   : 2021-07-03

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; i ++)
            res[i] = nums[nums[i]];
        return res;
    }
};


int main() {

    return 0;
}
