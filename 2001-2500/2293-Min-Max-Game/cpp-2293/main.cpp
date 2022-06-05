/// Source : https://leetcode.com/problems/min-max-game/
/// Author : liuyubobobo
/// Time   : 2022-06-04

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minMaxGame(vector<int>& nums) {

        while(nums.size() > 1){

            vector<int> nums2(nums.size() / 2);
            for(int i = 0; i < nums2.size(); i ++)
                if(i % 2 == 0) nums2[i] = min(nums[2 * i], nums[2 * i + 1]);
                else nums2[i] = max(nums[2 * i], nums[2 * i + 1]);
            nums = nums2;
        }
        return nums[0];
    }
};


int main() {


    return 0;
}
