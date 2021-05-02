/// Source : https://leetcode.com/problems/minimum-distance-to-the-target-element/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {

        int res = INT_MAX;
        for(int i = 0; i < nums.size(); i ++)
            if(nums[i] == target)
                res = min(res, abs(i - start));
        return res;
    }
};


int main() {

    return 0;
}
