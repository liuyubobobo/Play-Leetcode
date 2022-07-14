/// Source : https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/
/// Author : liuyubobobo
/// Time   : 2022-07-14

#include <iostream>
#include <algorithm>
#include <numeric>
#include <climits>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {

        int n = nums.size();

        int min_v = nums[0], min_v_index = 0;
        for(int i = 1; i < n; i ++)
            if(nums[i] < min_v) min_v = nums[i], min_v_index = i;

        int max_v = nums[0], max_v_index = 0;
        for(int i = 1; i < n; i ++)
            if(nums[i] >= max_v) max_v = nums[i], max_v_index = i;

        if(min_v_index == 0 && max_v_index == n - 1) return 0;
        if(min_v_index < max_v_index) return min_v_index + n - 1 - max_v_index;
        return min_v_index + n - 2 - max_v_index;
    }
};


int main() {

    return 0;
}
