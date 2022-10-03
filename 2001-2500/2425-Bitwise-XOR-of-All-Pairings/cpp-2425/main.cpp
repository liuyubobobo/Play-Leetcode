/// Source : https://leetcode.com/problems/bitwise-xor-of-all-pairings/
/// Author : liuyubobobo
/// Time   : 2022-10-03

#include <iostream>
#include <vector>

using namespace std;


/// Bitwise
/// Time Complexity: O(n + m)
/// Space Complexity: O(1)
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();

        int res = 0;
        for(int e: nums1)
            if(m & 1) res ^= e;
        for(int e: nums2)
            if(n & 1) res ^= e;
        return res;
    }
};


int main() {

    return 0;
}
