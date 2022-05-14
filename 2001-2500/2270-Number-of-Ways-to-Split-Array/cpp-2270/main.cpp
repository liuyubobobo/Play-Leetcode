/// Source : https://leetcode.com/problems/number-of-ways-to-split-array/
/// Author : liuyubobobo
/// Time   : 2022-05-14

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();

        vector<long long> presum(n + 1, 0ll);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        int res = 0;
        for(int len = 1; len < n; len ++){
            int l1 = 0, r1 = l1 + len - 1, l2 = l1 + len, r2 = n - 1;
            res += presum[r1 + 1] - presum[l1] >= presum[r2 + 1] - presum[l2];
        }
        return res;
    }
};


int main() {

    return 0;
}
