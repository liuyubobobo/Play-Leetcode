/// Source : https://leetcode.com/problems/create-target-array-in-the-given-order/
/// Author : liuyubobobo
/// Time   : 2020-03-21

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        vector<int> res(nums.size());
        for(int i = 0; i < nums.size(); i ++){

            for(int j = i - 1; j >= index[i]; j --)
                res[j + 1] = res[j];
            res[index[i]] = nums[i];
        }
        return res;
    }
};


int main() {

    return 0;
}
