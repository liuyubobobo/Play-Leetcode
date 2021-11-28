/// Source : https://leetcode.com/problems/k-radius-subarray-averages/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long> presum(n + 1, 0ll);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        vector<int> res(n, -1);
        for(int i = k; i + k < n; i ++)
            res[i] = (presum[i + k + 1] - presum[i - k]) / (2ll * k + 1);
        return res;
    }
};


int main() {

    return 0;
}
