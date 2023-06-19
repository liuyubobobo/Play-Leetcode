/// Source : https://leetcode.com/problems/movement-of-robots/description/
/// Author : liuyubobobo
/// Time   : 2023-06-13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int sumDistance(vector<int>& nums, string s, int d) {

        int n = nums.size();
        for(int i = 0; i < n; i ++)
            if(s[i] == 'R') nums[i] += d; else nums[i] -= d;
        sort(nums.begin(), nums.end());

        long long right_dis = 0, right_cnt = n - 1;
        for(int i = 1; i < n; i ++) right_dis += 0ll + nums[i] - nums[0];

        long long res = right_dis % MOD;
        for(int i = 1; i < n; i ++){
            long long cur = 0ll + nums[i] - nums[i - 1];

            right_dis = (right_dis - right_cnt * cur % MOD + MOD) % MOD;
            right_cnt --;

            res = (res + right_dis) % MOD;
            res %= MOD;
        }
        return res;
    }
};


int main() {

    return 0;
}
