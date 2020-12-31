/// Source : https://leetcode.com/problems/integer-break/description/
/// Author : liuyubobobo
/// Time   : 2019-07-24

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Deal with 2, 3 and 4 seperately
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    int integerBreak(int n) {

        assert(n >= 1);
        if(n == 2) return 1;
        if(n == 3) return 2;

        vector<int> memo(n + 1, -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 2;
        memo[3] = 3;
        for(int i = 2 ; i <= n ; i ++)
            for(int j = 1 ; j <= i / 2 ; j ++)
                memo[i] = max(memo[i], memo[j] * memo[i - j]);

        return memo[n];
    }
};


int main() {

    cout << Solution().integerBreak(2) << endl;
    cout << Solution().integerBreak(3) << endl;
    cout << Solution().integerBreak(4) << endl;
    cout << Solution().integerBreak(10) << endl;

    return 0;
}