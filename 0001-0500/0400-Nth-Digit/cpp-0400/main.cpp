/// Source : https://leetcode.com/problems/nth-digit/
/// Author : liuyubobobo
/// Time   : 2021-11-29

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int findNthDigit(int n) {

        n --;

        int d = 1;
        long long total = 9;
        while(n >= total * d)
            n -= total * d, d ++, total *= 10;
        return to_string(total / 9 + n / d)[n % d] - '0';
    }
};


int main() {

    cout << Solution().findNthDigit(3) << endl;
    // 3

    cout << Solution().findNthDigit(11) << endl;
    // 0

    cout << Solution().findNthDigit(100) << endl;
    // 5

    cout << Solution().findNthDigit(1000) << endl;
    // 3

    return 0;
}
