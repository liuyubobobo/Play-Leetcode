/// Source : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < nums.size(); i ++) presum[i + 1] = presum[i] + nums[i];

        int res = 0;

        int pmin = 0;
        for(int i = 1; i <= n; i ++){
            pmin = min(pmin, presum[i - 1]);
            res = max(res, abs(presum[i] - pmin));
        }

        int pmax = 0;
        for(int i = 1; i <= n; i ++){
            pmax = max(pmax, presum[i - 1]);
            res = max(res, abs(presum[i] - pmax));
        }

        return res;
    }
};


int main() {

    return 0;
}
