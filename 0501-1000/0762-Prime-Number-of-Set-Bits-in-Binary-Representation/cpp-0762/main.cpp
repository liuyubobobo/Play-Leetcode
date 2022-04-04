/// Source : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
/// Author : liuyubobobo
/// Time   : 2022-04-04

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(right - left)
/// Space Complexity: O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {

        set<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int res = 0;
        for(int e = left; e <= right; e ++){
            int b = __builtin_popcount(e);
            res += primes.count(b);
        }
        return res;
    }
};


int main() {


    return 0;
}
