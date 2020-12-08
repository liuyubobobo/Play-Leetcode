/// Source : https://leetcode.com/problems/missing-ranges/
/// Author : liuyubobobo
/// Time   : 2020-12-08

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {

        nums.insert(nums.begin(), lower - 1);
        nums.push_back(upper + 1);

        vector<string> res;
        for(int i = 0; i + 1 < nums.size(); i ++)
            if(nums[i] + 1 != nums[i + 1]){
                int l = nums[i] + 1, r = nums[i + 1] - 1;
                if(l == r) res.push_back(to_string(l));
                else res.push_back(to_string(l) + "->" + to_string(r));
            }
        return res;
    }
};


int main() {

    return 0;
}
