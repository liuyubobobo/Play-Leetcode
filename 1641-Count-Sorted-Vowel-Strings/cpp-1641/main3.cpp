/// Source : https://leetcode.com/problems/count-sorted-vowel-strings/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Dynamic Programming with Space Optimization
/// Tiime Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countVowelStrings(int n) {

        vector<int> dp(5, 1);
        for(int i = 1; i < n; i ++)
            for(int j = 4; j >= 0; j --){
                for(int k = 0; k < j; k ++) dp[j] += dp[k];
            }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};


int main() {

    cout << Solution().countVowelStrings(1) << endl;
    // 5

    cout << Solution().countVowelStrings(2) << endl;
    // 15

    cout << Solution().countVowelStrings(33) << endl;
    // 66045

    cout << Solution().countVowelStrings(50) << endl;
    // 316251

    return 0;
}
