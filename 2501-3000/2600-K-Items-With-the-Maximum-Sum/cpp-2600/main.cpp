/// Source : https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/
/// Author : liuyubobobo
/// Time   : 2023-03-26

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {

        int res = 0;

        int t = min(numOnes, k);
        res += t, k -= t;

        t = min(numZeros, k);
        k -= t;

        t = min(numNegOnes, k);
        k -= t, res -= t;

        return res;
    }
};


int main() {

    return 0;
}
