/// Source : https://leetcode.com/problems/maximum-or/description/
/// Author : liuyubobobo
/// Time   : 2023-05-13

#include <iostream>
#include <vector>

using namespace std;


/// Bitwise
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {

        vector<int> f(30, 0);
        for(int e: nums){
            for(int p = 0; p < 30; p ++) if(e & (1 << p)) f[p] ++;
        }

        long long res = 0;
        for(int e: nums){
            for(int p = 0; p < 30; p ++) if(e & (1 << p)) f[p] --;

            long long tres = e;
            tres <<= k;
            for(int p = 0; p < 30; p ++) if(f[p]) tres |= (1ll << p);
            res = max(res, tres);

            for(int p = 0; p < 30; p ++) if(e & (1 << p)) f[p] ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
