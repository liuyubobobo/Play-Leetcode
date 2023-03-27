/// Source : https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/
/// Author : liuyubobobo
/// Time   : 2023-03-26

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Presum + Binary Search
/// Time Complexity: O(nlogn + qlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> presum(n + 1, 0);
        for(int i = 1; i <= n; i++)
            presum[i] = presum[i - 1] + nums[i - 1];

        vector<long long> res(queries.size());
        for(int i = 0; i < queries.size(); i++){
            int q = queries[i];

            auto iter = lower_bound(nums.begin(), nums.end(), q);
            int index = iter - nums.begin();

            // [0... index - 1] < q; [index ... n - 1] >= q;

            long long tres = 0;
            tres += (long long)q * index - presum[index];
            tres += presum[n] - presum[index] - (long long)q * (n - index);
            res[i] = tres;
        }
        return res;
    }
};


int main() {

    return 0;
}
