/// Source : https://leetcode.com/problems/handshakes-that-dont-cross/description/
/// Author : liuyubobobo
/// Time   : 2023-02-22

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int numberOfWays(int numPeople) {

        vector<long long> dp(numPeople + 1, 0);
        dp[0] = 1;
        for(int i = 2; i <= numPeople; i ++){
            if(i % 2) continue;
            for(int j = 1; j < i; j ++){
                int len = j - 1;
                if(len & 1) continue;
                dp[i] += dp[len] * dp[i - (len + 2)] % MOD;
            }
            dp[i] %= MOD;
        }
        return dp.back();
    }
};

int main() {

    return 0;
}
