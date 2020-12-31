/// Source : https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>

using namespace std;

/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int maxNum = *max_element(nums.begin(), nums.end());
        int res = -1;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i] != maxNum){
                if(maxNum < 2 * nums[i])
                    return -1;
            }
            else
                res = i;
        return res;
    }
};


int main() {

    return 0;
}