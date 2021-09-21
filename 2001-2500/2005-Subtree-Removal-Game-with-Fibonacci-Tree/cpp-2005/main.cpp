/// Source : https://leetcode.com/problems/subtree-removal-game-with-fibonacci-tree/
/// Author : liuyubobobo
/// Time   : 2021-09-21

#include <iostream>
#include <vector>

using namespace std;


/// Nim
/// Time Compelxity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool findGameWinner(int n) {

        if(n == 1) return false;

        vector<int> dp(n, 0);
        dp[1] = 1;
        for(int i = 2; i < n; i ++)
            dp[i] = (dp[i - 1] ^ dp[i - 2]) + 1;
        return dp[n - 1] ^ dp[n - 2];
    }
};


int main() {

    cout << Solution().findGameWinner(3) << endl;

    return 0;
}
