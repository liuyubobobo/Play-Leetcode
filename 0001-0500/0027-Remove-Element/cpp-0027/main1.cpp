/// Source : https://leetcode.com/problems/remove-element/
/// Author : liuyubobobo
/// Time   : 2016-12-05


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Two Pointers
///Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    int removeElement(vector<int>& nums, int val) {

        int newl = 0;
        for( int i = 0 ; i < nums.size() ; i ++ )
            if( nums[i] != val )
                nums[newl++] = nums[i];

        return newl;
    }
};


int main() {

    vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    cout << Solution().removeElement(nums, val) << endl;

    return 0;
}