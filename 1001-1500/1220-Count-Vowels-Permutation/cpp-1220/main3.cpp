/// Source : https://leetcode.com/problems/count-vowels-permutation/
/// Author : liuyubobobo
/// Time   : 2019-10-06

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming with Space Optimization
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    int MOD = 1e9 + 7;
    vector<vector<int>> g = {
            //a  e  i  o  u
            {0, 1, 0, 0, 0}, // a
            {1, 0, 1, 0, 0}, // e
            {1, 1, 0, 1, 1}, // i
            {0, 0, 1, 0, 1}, // o
            {1, 0, 0, 0, 0} // u
    };

public:
    int countVowelPermutation(int n) {

        vector<int> dp(5, 1);

        for(int j = n - 2; j >= 0; j --){
            vector<int> dp2(5, 0);
            for(int i = 0; i < 5; i ++){
                for(int k = 0; k < 5; k ++)
                    if(g[i][k])
                        dp2[i] += dp[k], dp2[i] %= MOD;
            }
            dp = dp2;
        }

        int res = 0;
        for(int e: dp)
            res += e, res %= MOD;
        return res;
    }
};


int main() {

    cout << Solution().countVowelPermutation(1) << endl;
    // 5

    cout << Solution().countVowelPermutation(2) << endl;
    // 10

    cout << Solution().countVowelPermutation(5) << endl;
    // 68

    return 0;
}