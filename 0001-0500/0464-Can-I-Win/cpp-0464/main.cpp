/// Source : https://leetcode.com/problems/can-i-win/
/// Author : liuyubobobo
/// Time   : 2022-05-24

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;


/// Memoization
/// Time Complexity: O(2^M * M * desiredTotal)
/// Space Complexity: O(2^M * desiredTotal)
class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if(desiredTotal == 0) return true;

        int total = (maxChoosableInteger + 1) * maxChoosableInteger / 2;

        // -1: not calculated
        //  0: can not get
        //  1: lose
        //  2: win
        unordered_map<long long, int> dp;
        return win(desiredTotal, (1 << maxChoosableInteger) - 1, maxChoosableInteger, total, dp) == 2;
    }

private:
    int win(int need, int state, int M, int total, unordered_map<long long, int>& dp){

        if(need <= 0) return 1;
        if(total < need) return 0;

        long long hash = (1ll << M) * need + state;
        auto iter = dp.find(hash);
        if(iter != dp.end()) return iter->second;

        int w = 0, all = 0;
        for(int i = M; i >= 1; i --)
            if((state & (1 << (i - 1)))){
                all ++;
                int tres = win(need - i, state - (1 << (i - 1)), M, total - i, dp);
                if(tres == 1) return dp[hash] = 2;

                w += (tres == 2);
            }

        return dp[hash] = (all && w == all);
    }
};


int main() {

    cout << Solution().canIWin(10, 11) << '\n';
    // 0

    cout << Solution().canIWin(10, 0) << '\n';
    // 1

    cout << Solution().canIWin(10, 1) << '\n';
    // 1

    cout << Solution().canIWin(5, 50) << '\n';
    // 0

    cout << Solution().canIWin(20, 209) << '\n';
    // 0

    cout << Solution().canIWin(20, 300) << '\n';
    // 0

    cout << Solution().canIWin(12, 49) << '\n';
    // 1

    cout << Solution().canIWin(6, 16) << '\n';
    // 1

    cout << Solution().canIWin(20, 152) << '\n';
    // 0

    return 0;
}
