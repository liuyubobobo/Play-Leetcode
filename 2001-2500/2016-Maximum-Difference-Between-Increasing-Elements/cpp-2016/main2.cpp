/// Source : https://leetcode.com/problems/maximum-difference-between-increasing-elements/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan and record the minimum element
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int n = nums.size(), res = -1, minv = nums[0];
        for(int i = 1; i < n; i ++){
            if(minv < nums[i]) res = max(res, nums[i] - minv);
            minv = min(minv, nums[i]);
        }
        return res;
    }
};


int main() {

    return 0;
}
