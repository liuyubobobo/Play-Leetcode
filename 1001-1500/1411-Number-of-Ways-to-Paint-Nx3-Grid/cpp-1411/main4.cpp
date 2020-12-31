/// Source : https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
/// Author : liuyubobobo
/// Time   : 2020-04-14

#include <iostream>
#include <vector>

using namespace std;


/// State Compression and DP
/// Space Optimized
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int numOfWays(int n) {

        long long abc = 6ll, aba = 6ll;
        for(int i = 1; i < n; i ++){
            long long aba2 = 3 * aba + 2 * abc;
            long long abc2 = 2 * aba + 2 * abc;
            abc = abc2 % MOD;
            aba = aba2 % MOD;
        }
        return (aba + abc) % MOD;
    }
};


int main() {

    cout << Solution().numOfWays(2) << endl;
    // 54

    cout << Solution().numOfWays(3) << endl;
    // 246

    cout << Solution().numOfWays(7) << endl;
    // 106494

    cout << Solution().numOfWays(5000) << endl;
    // 30228214

    return 0;
}
