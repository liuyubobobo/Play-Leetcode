/// Source : https://leetcode.com/problems/smallest-index-with-equal-value/
/// Author : liuyubobobo
/// Time   : 2021-10-30

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int smallestEqual(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i ++)
            if(i % 10 == nums[i]) return i;
        return -1;
    }
};


int main() {

    return 0;
}
