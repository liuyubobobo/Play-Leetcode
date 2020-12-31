/// Source : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
/// Author : liuyubobobo
/// Time   : 2020-03-01

#include <iostream>
#include <vector>

using namespace std;


/// Counting
/// Time Complexity: O(n)
/// Space Complexity: O(max(nums))
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {

        vector<int> count(101, 0);
        for(int e: nums) count[e] ++;
        for(int i = 1; i <= 100; i ++) count[i] += count[i - 1];

        vector<int> res;
        for(int num: nums) res.push_back(num ? count[num - 1] : 0);
        return res;
    }
};


int main() {

    return 0;
}
