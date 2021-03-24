/// Source : https://leetcode.com/problems/132-pattern/
/// Author : liuyubobobo
/// Time   : 2021-03-23

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Brute Force to check the middle
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size();
        for(int i = 0; i < n; i ++){

            int leftmin = INT_MAX;
            for(int j = 0; j < i; j ++)
                if(nums[j] < nums[i] && nums[j] < leftmin)
                    leftmin = nums[j];

            if(leftmin == INT_MAX) continue;

            int rightmax = INT_MIN;
            for(int j = i + 1; j < n; j ++)
                if(nums[j] < nums[i] && nums[j] > rightmax)
                    rightmax = nums[j];

            if(rightmax == INT_MIN) continue;

            if(leftmin < rightmax)
                return true;
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
