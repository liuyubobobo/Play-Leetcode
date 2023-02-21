/// Source : https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/
/// Author : liuyubobobo
/// Time   : 2023-02-20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        return min3(nums[n - 2] - nums[1], nums[n - 1] - nums[2], nums[n - 3] - nums[0]);
    }

private:
    int min3(int a, int b, int c) {
        return min(a, min(b, c));
    }
};


int main() {

    return 0;
}
