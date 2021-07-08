/// Source : https://leetcode-cn.com/problems/find-majority-element-lcci/
/// Author : liuyubobobo
/// Time   : 2021-07-08

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Boyer-Moore Voting Algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int majorityElement(vector<int>& nums) {

        assert(nums.size() > 0);

        int count = 0;
        int res = -1;
        for(int num: nums){
            if(count == 0)
                res = num;

            count += (res == num) ? 1 : -1;
        }

        count = 0;
        for(int num: nums) count += (num == res);

        return count > nums.size() / 2 ? res : -1;
    }
};


int main() {

    return 0;
}