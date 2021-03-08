/// Source : https://leetcode.com/problems/next-greater-element-ii/
/// Author : liuyubobobo
/// Time   : 2021-03-05

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i ++)
            res[i] = next(nums, i);
        return res;
    }

private:
    int next(const vector<int>& nums, int start){

        for(int i = 1; i < nums.size(); i ++)
            if(nums[(start + i) % nums.size()] > nums[start])
                return nums[(start + i) % nums.size()];
        return -1;
    }
};


int main() {

    return 0;
}
