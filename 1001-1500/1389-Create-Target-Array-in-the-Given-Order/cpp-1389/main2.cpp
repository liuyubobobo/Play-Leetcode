/// Source : https://leetcode.com/problems/create-target-array-in-the-given-order/
/// Author : liuyubobobo
/// Time   : 2020-03-27

#include <iostream>
#include <vector>

using namespace std;


/// Simulation, Using STL
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        vector<int> res;
        for(int i = 0; i < nums.size(); i ++)
            res.insert(res.begin() + index[i], nums[i]);
        return res;
    }
};


int main() {

    return 0;
}
