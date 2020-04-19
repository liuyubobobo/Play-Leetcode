/// Source : https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>

using namespace  std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minStartValue(vector<int>& nums) {

        int cur = 0, res = 0;
        for(int e: nums)
            cur += e, res = min(res, cur);
        return -res + 1;
    }
};


int main() {

    return 0;
}
