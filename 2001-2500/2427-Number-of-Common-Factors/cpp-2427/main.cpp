/// Source : https://leetcode.com/problems/number-of-common-factors/
/// Author : liuyubobobo
/// Time   : 2022-10-01

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(min(a, b))
/// Space Complexity: O(1)
class Solution {
public:
    int commonFactors(int a, int b) {

        int res = 0;
        int n = min(a, b);
        for(int i = 1; i <= n; i ++)
            if(a % i == 0 && b % i == 0) res ++;
        return res;
    }
};


int main() {

    return 0;
}
