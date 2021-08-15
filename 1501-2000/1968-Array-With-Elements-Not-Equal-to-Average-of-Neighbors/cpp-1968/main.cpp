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
        for(int i = 1; i + 1 < nums.size(); i += 2)
            swap(nums[i], nums[i + 1]);
        return nums;
    }
};


int main() {

    return 0;
}
