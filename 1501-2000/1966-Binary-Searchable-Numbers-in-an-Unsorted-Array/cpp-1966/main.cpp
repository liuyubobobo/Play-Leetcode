/// Source : https://leetcode.com/problems/binary-searchable-numbers-in-an-unsorted-array/
/// Author : liuyubobobo
/// Time   : 2021-08-14

#include <iostream>
#include <vector>

using namespace std;


/// Range max and min
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {

        int n = nums.size();
        vector<bool> left(n, true);

        int maxv = nums[0];
        for(int i = 1; i < n; i ++){
            left[i] = maxv < nums[i];
            maxv = max(maxv, nums[i]);
        }

        vector<bool> right(n, true);
        int minv = nums[n - 1];
        for(int i = n - 2; i >= 0; i --){
            right[i] = minv > nums[i];
            minv = min(minv, nums[i]);
        }

        int res = 0;
        for(int i = 0; i < n; i ++) res += (left[i] && right[i]);
        return res;
    }
};


int main() {

    return 0;
}
