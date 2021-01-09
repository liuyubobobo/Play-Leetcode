/// Source : https://leetcode.com/problems/calculate-money-in-leetcode-bank/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>
#include <vector>


/// Brute Force
/// Time Complexity: O(n / 7)
/// Space Complexity: O(1)
class Solution {
public:
    int totalMoney(int n) {

        int res = 0;
        for(int start = 1; n; start ++){
            if(n >= 7) res += (start + 3) * 7, n -= 7;
            else res += (start + start + n - 1) * n / 2, n = 0;
        }
        return res;
    }
};


int main() {

    return 0;
}
