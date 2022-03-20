/// Source : https://leetcode.com/problems/count-hills-and-valleys-in-an-array/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int countHillValley(vector<int>& nums) {

        int n = nums.size(), res = 0;
        for(int start = 0, i = 1; i <= n; i ++){
            if(i == n || nums[i] != nums[start]){
                int left = -1, right = -1;
                for(int j = start - 1; j >= 0; j --)
                    if(nums[j] != nums[start]){
                        left = nums[j];
                        break;
                    }
                for(int j = start + 1; j < n; j ++)
                    if(nums[j] != nums[start]){
                        right = nums[j];
                        break;
                    }
                if(left == -1 || right == -1){
                    start = i;
                    continue;
                }
                if((left > nums[start] && right > nums[start]) || (left < nums[start] && right < nums[start]))
                    res ++;

                start = i;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, 4, 1, 1, 6, 5};
    cout << Solution().countHillValley(nums1) << '\n';
    // 3

    vector<int> nums2 = {6,6,5,5,4,1};
    cout << Solution().countHillValley(nums2) << '\n';
    // 0

    return 0;
}
