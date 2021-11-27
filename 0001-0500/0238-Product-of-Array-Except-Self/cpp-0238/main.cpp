/// Source : https://leetcode.com/problems/product-of-array-except-self/
/// Author : liuyubobobo
/// Time   : 2021-11-27

#include <iostream>
#include <vector>

using namespace std;


/// Pre + Suf
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<long long> pre(n, nums[0]);
        for(int i = 1; i < n; i ++) pre[i] = pre[i - 1] * nums[i];

        vector<long long> suf(n, nums.back());
        for(int i = n - 2; i >= 0; i --) suf[i] = suf[i + 1] * nums[i];

        vector<int> res(n);
        res[0] = suf[1]; res[n - 1] = pre[n - 2];
        for(int i = 1; i + 1 < n; i ++)
            res[i] = pre[i - 1] * suf[i + 1];
        return res;
    }
};


int main() {

    return 0;
}
