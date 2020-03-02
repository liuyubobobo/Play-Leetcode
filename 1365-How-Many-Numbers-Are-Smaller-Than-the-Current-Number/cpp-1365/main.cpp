/// Source : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
/// Author : liuyubobobo
/// Time   : 2020-02-29

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){
            int e = 0;
            for(int j = 0; j < nums.size(); j ++)
                e += (nums[j] < nums[i]);
            res.push_back(e);
        }
        return res;
    }
};


int main() {

    return 0;
}
