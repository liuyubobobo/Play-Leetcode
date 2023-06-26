/// Source : https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/
/// Author : liuyubobobo
/// Time   : 2023-06-25

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int makeTheIntegerZero(long long num1, long long num2) {

        for(int k = 1; k <= 60; k ++){
            long long x = num1 - k * num2;
            if(x <= 0) break;
            if(__builtin_popcountll(x) <= k && x >= k) return k;
        }
        return -1;
    }
};


int main() {

    return 0;
}
