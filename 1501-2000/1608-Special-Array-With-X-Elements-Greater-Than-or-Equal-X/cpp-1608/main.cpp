/// Source : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
/// Author : liuyubobobo
/// Time   : 2020-10-03

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int specialArray(vector<int>& nums) {

        for(int x = 0; x <= nums.size(); x ++){
            int f = 0;
            for(int e: nums) if(e >= x) f ++;
            if(f == x) return x;
        }
        return -1;
    }
};


int main() {

    return 0;
}
