/// Source : https://leetcode.com/problems/domino-and-tromino-tiling/description/
/// Author : liuyubobobo
/// Time   : 2018-03-07

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Optimiaze last solution about space complexity
/// Time Complexity: O(N)
/// Space Complexity: O(1)
class Solution {

public:
    int numTilings(int N) {

        int res[4];

        res[0] = 0;
        res[1] = 0;
        res[2] = 0;
        res[3] = 1;

        int mod = 1000000007;
        for(int i = 1 ; i <= N ; i ++){

            int last_zero = res[0];
            int last_one = res[1];
            int last_two = res[2];

            res[0] = res[3];

            res[3] = last_zero;
            for(int j = 0 ; j < 3 ; j ++)
                res[3] = (res[3] + res[j]) % mod;

            res[1] = (last_zero + last_two) % mod;
            res[2] = (last_zero + last_one) % mod;
        }

        return res[3];
    }
};

int main() {

    cout << Solution().numTilings(3) << endl; // 5
    cout << Solution().numTilings(4) << endl; // 11
    cout << Solution().numTilings(7) << endl; // 117
    cout << Solution().numTilings(1000) << endl; // 979232805

    return 0;
}