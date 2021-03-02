/// Source : https://leetcode.com/problems/counting-bits/
/// Author : liuyubobobo
/// Time   : 2021-03-02

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> dp(num + 1, 0);
        for(int i = 1; i <= num; i ++)
            dp[i] = 1 + dp[i - (i & (-i))];
        return dp;
    }
};


int main() {

    return 0;
}
