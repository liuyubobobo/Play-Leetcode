/// Source : https://leetcode.com/problems/count-special-quadruplets/
/// Author : liuyubobobo
/// Time   : 2021-09-04

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^4)
/// Space Complexity: O(1)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {

        int res = 0;
        for(int a = 0; a < nums.size(); a ++)
            for(int b = a + 1; b < nums.size(); b ++)
                for(int c = b + 1; c < nums.size(); c ++)
                    for(int d = c + 1; d < nums.size(); d ++)
                        if(nums[a] + nums[b] + nums[c] == nums[d]) res ++;
        return res;
    }
};

int main() {

    return 0;
}
