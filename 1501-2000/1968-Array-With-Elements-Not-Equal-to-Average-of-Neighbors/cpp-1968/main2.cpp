/// Source : https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/
/// Author : liuyubobobo
/// Time   : 2021-08-14

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> res(n);
        int j = 0;
        for(int i = 0; i < n; i += 2)
            res[i] = nums[j ++];
        for(int i = 1; i < n; i += 2)
            res[i] = nums[j ++];
        return res;
    }
};


int main() {

    return 0;
}
