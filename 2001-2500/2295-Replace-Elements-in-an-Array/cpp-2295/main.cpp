/// Source : https://leetcode.com/problems/replace-elements-in-an-array/
/// Author : liuyubobobo
/// Time   : 2022-06-04

#include <iostream>
#include <vector>

using namespace std;


/// Hash Table
/// Time Complexity: O(|op|)
/// Space Complexity: O(max_num)
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {

        vector<int> pos(1e6 + 1, -1);
        for(int i = 0; i < nums.size(); i ++)
            pos[nums[i]] = i;

        for(const vector<int>& op: operations){
            int from_num = op[0], to_num = op[1];
            int from_index = pos[from_num];
            nums[from_index] = to_num;

            pos[from_num] = -1;
            pos[to_num] = from_index;
        }
        return nums;
    }
};


int main() {

    return 0;
}
