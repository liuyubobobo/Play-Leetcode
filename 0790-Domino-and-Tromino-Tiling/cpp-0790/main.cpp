/// Source : https://leetcode.com/problems/domino-and-tromino-tiling/description/
/// Author : liuyubobobo
/// Time   : 2018-02-24

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// dp[i]: how many ways to fill a 2*i tiles
///
/// Time Complexity: O(N^2)
/// Space Complexity: O(N)
class Solution {

public:
    int numTilings(int N) {

        vector<int> res;
        res.push_back(1); // 0
        res.push_back(1); // 1
        res.push_back(2); // 2

        if(N <= 2)
            return (int)res[N];

        int mod = 1000000007;
        for(int i = 3 ; i <= N ; i ++){
            // .....A      ....AA
            // .....A  and ....BB
            int x = (res[i-1] + res[i-2]) % mod;

            // AA112233..nnB
            // A112233..nnBB and
            // A112233..nnBB
            // AA112233..nnB
            for(int j = 3 ; i - j >= 0; j += 2){
                x = (x + res[i-j]) % mod;
                x = (x + res[i-j]) % mod;
            }

            // AA112233..BB
            // A112233..nnB and
            // A112233..nnB
            // AA112233..BB
            for(int j = 4 ; i - j >= 0; j += 2){
                x = (x + res[i-j]) % mod;
                x = (x + res[i-j]) % mod;
            }

            res.push_back(x);
        }

        return res[N];
    }
};

int main() {

    cout << Solution().numTilings(3) << endl; // 5
    cout << Solution().numTilings(4) << endl; // 11
    cout << Solution().numTilings(7) << endl; // 117
    cout << Solution().numTilings(1000) << endl; // 979232805

    return 0;
}