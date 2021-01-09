/// Source : https://leetcode.com/problems/calculate-money-in-leetcode-bank/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>
#include <vector>


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int totalMoney(int n) {

        int res = 0;
        for(int start = 0;;start ++){
            for(int i = 0; i < 7; i ++){
                res += start + 1 + i;
                if(start * 7 + i + 1 == n) return res;
            }
        }
        return -1;
    }
};


int main() {

    return 0;
}
