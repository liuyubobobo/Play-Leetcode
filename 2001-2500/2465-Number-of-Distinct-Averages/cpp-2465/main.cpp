/// Source : https://leetcode.com/problems/number-of-distinct-averages/description/
/// Author : liuyubobobo
/// Time   : 2022-11-27

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


/// Sorting and using set
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int distinctAverages(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        set<int> res;
        for(int i = 0, j = nums.size() - 1; i < j; i ++, j --)
            res.insert(nums[i] + nums[j]);
        return res.size();
    }
};


int main() {

    return 0;
}
