/// Source : https://leetcode.com/problems/sum-of-beauty-in-the-array/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {

        int n = nums.size();

        vector<bool> left(n, false);
        int cur_max = nums[0];
        for(int i = 1; i < n; i ++){
            if(cur_max < nums[i]) left[i] = true;
            cur_max = max(cur_max, nums[i]);
        }

        vector<bool> right(n, false);
        int cur_min = nums[n - 1];
        for(int i = n - 2; i >= 0; i --){
            if(nums[i] < cur_min) right[i] = true;
            cur_min = min(cur_min, nums[i]);
        }

        int res = 0;
        for(int i = 1; i + 1 < n; i ++){
            if(left[i] && right[i]) res += 2;
            else res += (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]);
        }
        return res;
    }
};


int main() {

    return 0;
}
