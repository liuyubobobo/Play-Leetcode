/// Source : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/
/// Author : liuyubobobo
/// Time   : 2022-10-15

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Using Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findMaxK(vector<int>& nums) {

        set<int> s(nums.begin(), nums.end());
        int res = -1;
        for(int e: nums)
            if(e > 0 && s.count(-e)) res = max(res, e);
        return res;
    }
};


int main() {

    return 0;
}
