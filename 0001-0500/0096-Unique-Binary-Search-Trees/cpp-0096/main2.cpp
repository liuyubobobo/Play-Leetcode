/// Source : https://leetcode.com/problems/unique-binary-search-trees/description/
/// Author : liuyubobobo
/// Time   : 2018-09-10

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int numTrees(int n) {

        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i ++)
            for(int j = 1; j <= i; j ++)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};


int main() {

    cout << Solution().numTrees(3) << endl;

    return 0;
}