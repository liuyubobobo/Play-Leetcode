/// Source : https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
/// Author : liuyubobobo
/// Time   : 2020-09-19

#include <iostream>
#include <vector>

using namespace std;


/// Sweep Line
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        int n = nums.size();

        vector<int> freq(n + 1);
        for(const vector<int>& v: requests)
            freq[v[0]] ++, freq[v[1] + 1] --;

        for(int i = 1; i <= n; i ++)
            freq[i] += freq[i - 1];

        sort(freq.begin(), freq.begin() + n);
        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = n - 1; i >= 0; i --)
            res = (res + (long long)nums[i] * freq[i]) % MOD;
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<vector<int>> request1 = {{1, 3}, {0, 1}};
    cout << Solution().maxSumRangeQuery(nums1, request1) << endl;
    // 19

    return 0;
}
