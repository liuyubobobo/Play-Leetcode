/// Source : https://leetcode.com/problems/apply-operations-to-an-array/
/// Author : liuyubobobo
/// Time   : 2022-11-05

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n = nums.size();
        for(int i = 0; i + 1 < n; i ++)
            if(nums[i] == nums[i + 1]) nums[i] *= 2, nums[i + 1] = 0;

        vector<int> res(n, 0);
        for(int i = 0, k = 0; i < n; i ++)
            if(nums[i]) res[k ++] = nums[i];
        return res;
    }
};


int main() {

    return 0;
}
