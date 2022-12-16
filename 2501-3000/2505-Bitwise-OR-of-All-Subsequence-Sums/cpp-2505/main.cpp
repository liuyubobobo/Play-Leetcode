/// Source : https://leetcode.com/problems/bitwise-or-of-all-subsequence-sums/description/
/// Author : liuyubobobo
/// Time   : 2022-12-15

#include <iostream>
#include <vector>

using namespace std;


/// Bitwise
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {

        long long res = 0;

        int cnt = 0;
        for(int p = 0; p < 62; p ++){
            cnt /= 2;
            if(p <= 31)
                for(int num: nums) cnt += ((num >> p) & 1);
            if(cnt) res += (1ll << p);
        }

        cnt /= 2;
        if(cnt) res += (1ll << 62);
        return res;
    }
};


int main() {

    return 0;
}
