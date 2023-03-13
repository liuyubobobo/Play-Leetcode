/// Source : https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/
/// Author : liuyubobobo
/// Time   : 2023-03-13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Presum
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxScore(vector<int>& nums) {

        sort(nums.begin(), nums.end(), greater<int>());

        int n = nums.size();
        vector<long long> presum(n + 1, 0ll);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        int res = 0;
        for(int i = 1; i <= n; i ++) res += presum[i] > 0;
        return res;
    }
};


int main() {

    return 0;
}
