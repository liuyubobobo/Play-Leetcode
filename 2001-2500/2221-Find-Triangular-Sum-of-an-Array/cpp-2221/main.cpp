/// Source : https://leetcode.com/problems/find-triangular-sum-of-an-array/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int triangularSum(vector<int>& nums) {

        vector<int> t;
        while(nums.size() > 1){
            for(int i = 1; i < nums.size(); i ++)
                t.push_back((nums[i - 1] + nums[i]) % 10);
            nums = t;
            t.clear();
        }
        return nums[0];
    }
};


int main() {

    return 0;
}
