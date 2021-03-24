/// Source : https://leetcode.com/problems/132-pattern/
/// Author : liuyubobobo
/// Time   : 2021-03-23

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Better Brute Force
/// Record min value during the scan
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size(), leftmin = INT_MAX;
        for(int i = 0; i < n; i ++){

            if(nums[i] > leftmin){

                int rightmax = INT_MIN;
                for(int j = i + 1; j < n; j ++)
                    if(nums[j] < nums[i] && nums[j] > rightmax)
                        rightmax = nums[j];

                if(rightmax == INT_MIN) continue;

                if(leftmin < rightmax)
                    return true;
            }

            leftmin = min(leftmin, nums[i]);
        }

        return false;
    }
};


int main() {

    vector<int> nums1 = {1, 0, 1, -4, -3};
    cout << Solution().find132pattern(nums1) << endl;
    // 0

    return 0;
}
