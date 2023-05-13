/// Source : https://leetcode.com/problems/power-of-heroes/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Math
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int sumOfPower(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        long long min_part = 0, res = 0;
        for(long long e: nums){
            res += e * e % MOD * min_part % MOD;
            res += e * e % MOD * e % MOD;
            res %= MOD;

            min_part = (min_part * 2 + e) % MOD;
        }
        return res;
    }
};


int main() {

    return 0;
}
