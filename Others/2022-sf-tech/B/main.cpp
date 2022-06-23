/// Source : https://leetcode.cn/contest/sf-tech/problems/cINqyA/
/// Author : liuyubobobo
/// Time   : 2022-06-23

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Backpack DP
/// Time complexity: O(C * n)
/// Space Complexity: O(C)
class Solution {
public:
    int minRemainingSpace(vector<int>& V, int C) {

        vector<bool> dp(C + 1, false);
        dp[0] = true;
        for(int v: V){
            for(int c = C; c >= v; c --)
                if(dp[c - v]) dp[c] = true;
        }

        for(int i = C; i >= 0; i --)
            if(dp[i]) return C - i;
        assert(false);
        return -1;
    }
};


int main() {

    return 0;
}
