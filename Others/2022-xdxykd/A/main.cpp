/// Source : https://leetcode.cn/contest/ubiquant2022/problems/xdxykd/
/// Author : liuyubobobo
/// Time   : 2022-08-25

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


/// Math
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int numberOfPairs(vector<int>& nums) {

        int n = nums.size();
        vector<int> nums2(n);
        for(int i = 0; i < n; i ++){
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            nums2[i] = atoi(s.c_str());
        }

        for(int i = 0; i < n; i ++)
            nums[i] -= nums2[i];

        map<int, int> f;
        for(int e: nums) f[e] ++;

        long long res = 0;
        for(const pair<int, int>& p: f){
            long long cnt = p.second;
            res += cnt * (cnt - 1) / 2 % MOD;
            res %= MOD;
        }
        return res;
    }
};


int main() {

    return 0;
}
