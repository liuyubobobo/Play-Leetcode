/// Source : https://leetcode.com/problems/restore-the-array/
/// Author : liuyubobobo
/// Time   : 2020-04-19

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int numberOfArrays(string s, int k) {

        vector<int> dp(s.size() + 1, 0);
        dp[s.size()] = 1;
        for(int i = s.size() - 1; i >= 0; i --)
            if(s[i] != '0'){
                for(int j = i; j < s.size(); j ++){
                    if(j + 1 - i == 10 && s[i] >= '2') break;
                    int tnum = atoi(s.substr(i, j + 1 - i).c_str());
                    if(tnum > k) break;
                    dp[i] = (dp[i] + dp[j + 1]) % MOD;
                }
            }
        return dp[0];
    }
};


int main() {

    cout << Solution().numberOfArrays("1000", 10000) << endl;
    // 1

    cout << Solution().numberOfArrays("1000", 10) << endl;
    // 0

    cout << Solution().numberOfArrays("1317", 2000) << endl;
    // 8

    cout << Solution().numberOfArrays("2020", 30) << endl;
    // 1

    cout << Solution().numberOfArrays("1234567890", 90) << endl;
    // 34

    return 0;
}
