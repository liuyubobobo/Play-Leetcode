/// Source : https://leetcode.com/problems/rearrange-array-elements-by-sign/
/// Author : liuyubobobo
/// Time   : 2022-01-22

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n);
        for(int i = 0, posi = 0, negi = 1; i < n; i ++)
            if(nums[i] > 0)
                res[posi] = nums[i], posi += 2;
            else
                res[negi] = nums[i], negi += 2;

        return res;
    }
};


int main() {

    return 0;
}
