/// Source : https://leetcode.com/problems/semi-ordered-permutation/description/
/// Author : liuyubobobo
/// Time   : 2023-06-04

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {

        int n = nums.size();

        int pos_1 = find(nums.begin(), nums.end(), 1) - nums.begin();
        int pos_n = find(nums.begin(), nums.end(), n) - nums.begin();

        int res = pos_1 + n - 1 - pos_n;
        if(pos_1 > pos_n) res--;
        return res;
    }
};


int main() {

    return 0;
}
