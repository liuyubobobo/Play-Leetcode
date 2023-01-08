/// Source : https://leetcode.com/problems/find-xor-beauty-of-array/description/
/// Author : liuyubobobo
/// Time   : 2023-01-07

#include <iostream>
#include <vector>

using namespace std;


/// Bitwise
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int xorBeauty(vector<int>& nums) {

        long long n = nums.size();

        int res = 0;
        for(int p = 0; p < 30; p ++){
            vector<long long> cnt(2, 0);
            for(int num: nums) cnt[(num >> p) & 1] ++;

            long long a = n * n - cnt[0] * cnt[0];
            long long b = a * cnt[1];
            if(b & 1) res += (1 << p);
        }
        return res;
    }
};


int main() {

    return 0;
}
