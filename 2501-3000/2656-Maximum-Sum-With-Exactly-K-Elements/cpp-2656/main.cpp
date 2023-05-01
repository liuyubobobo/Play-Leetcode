/// Source : https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Math
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {

        int start = *max_element(nums.begin(), nums.end());
        return (start + start + k - 1) * k / 2;
    }
};


int main() {

    return 0;
}
