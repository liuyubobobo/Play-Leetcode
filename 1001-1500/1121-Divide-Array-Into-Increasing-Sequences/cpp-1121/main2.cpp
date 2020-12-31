/// Source : https://leetcode.com/problems/divide-array-into-increasing-sequences/
/// Author : liuyubobobo
/// Time   : 2019-07-13

#include <iostream>
#include <vector>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {

        int count = 0;
        for(int start = 0, i = start + 1; i <= nums.size(); i ++)
            if(i == nums.size() || nums[i] != nums[start]){
                count = max(count, i - start);
                start = i;
                i = start;
            }

        return nums.size() >= K * count;
    }
};


int main() {

    return 0;
}