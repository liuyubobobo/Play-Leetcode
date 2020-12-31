/// Source : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
/// Author : liuyubobobo
/// Time   : 2020-01-11

#include <iostream>
#include <vector>

using namespace std;


/// Convert every number into binary representation in the run
/// Time Complexity: O(log(max(a, b, c)))
/// Space Complexity: O(1)
class Solution {
public:
    int minFlips(int a, int b, int c) {

        int res = 0;
        while(a || b || c){
            int abit  = a & 1, bbit = b & 1, cbit = c & 1;
            a >>= 1, b >>= 1, c >>= 1;

            if(cbit == 0) res += abit + bbit;
            else res += (abit | bbit) ? 0 : 1;
        }
        return res;
    }
};


int main() {

    cout << Solution().minFlips(2, 6, 5) << endl;
    // 3

    cout << Solution().minFlips(4, 2, 7) << endl;
    // 1

    cout << Solution().minFlips(1, 2, 3) << endl;
    // 0

    return 0;
}
