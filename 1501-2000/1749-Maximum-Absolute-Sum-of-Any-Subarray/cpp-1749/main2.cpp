/// Source : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size(), res = 0;

        int pmin = 0, pmax = 0, presum = 0;
        for(int i = 0; i < n; i ++){
            pmin = min(pmin, presum);
            presum += nums[i];
            res = max(res, abs(presum - pmin));
        }

        presum = 0;
        for(int i = 0; i < n; i ++){
            pmax = max(pmax, presum);
            presum += nums[i];
            res = max(res, abs(presum - pmax));
        }

        return res;
    }
};


int main() {

    return 0;
}
