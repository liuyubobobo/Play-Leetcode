/// Source : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Mathematics
/// Time Complexiity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int concatenatedBinary(int n) {
        long long cur = 0;
        for(int i = 1; i <= n; i ++)
            cur = (cur * (int)pow(2, floor(log2(i)) + 1) + i) % MOD;
        return cur;
    }
};


int main() {

    cout << Solution().concatenatedBinary(1) << endl;
    // 1

    cout << Solution().concatenatedBinary(3) << endl;
    // 27

    cout << Solution().concatenatedBinary(12) << endl;
    // 505379714

    cout << Solution().concatenatedBinary(26042) << endl;
    // 502218269

    return 0;
}