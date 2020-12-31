/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {

        int f = 0;
        for(int num: nums)
            if(target == num) f ++;
        return f > nums.size() / 2;
    }
};


int main() {
    return 0;
}