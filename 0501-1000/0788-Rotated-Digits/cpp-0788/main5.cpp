/// Source : https://leetcode.com/problems/rotated-digits/description/
/// Author : liuyubobobo
/// Time   : 2018-03-05

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
///
/// We need to write using only digits from 0125689,
/// and write at least one digit from 2569.
///
/// dp[i][eq][contain2569] means we search first i digits,
/// and the i-th digit is equal (or not) to the i-th digit in N
/// and the search has (or not) already meet a digit of 2569
///
/// Time Complexity: O(logN)
/// Space Complexity: O(logN)
class Solution {

public:
    int rotatedDigits(int N) {

        string N_str = to_string(N);
        vector<vector<vector<int>>> memo(N_str.size() + 1, vector<vector<int>>(2, vector<int>(2, 0)));

        memo[N_str.size()][false][true] = 1;
        memo[N_str.size()][true][true] = 1;
        for(int index = N_str.size() - 1 ; index >= 0 ; index --)
            for(int eq = 0 ; eq <= 1 ; eq ++)
                for(int contain2569 = 0 ; contain2569 <= 1 ; contain2569 ++){

                    int res = 0;
                    char bound = eq ? N_str[index] : '9';
                    for(char c = '0' ; c <= bound ; c ++){
                        if(c == '3' || c == '4' || c == '7')
                            continue;

                        bool is2569 = (c == '2' || c == '5' || c == '6' || c =='9');
                        if(!eq)
                            res += memo[index+1][eq][contain2569 || is2569];
                        else if(c < bound)
                            res += memo[index+1][false][contain2569 || is2569];
                        else
                            res += memo[index+1][true][contain2569 || is2569];
                    }
                    memo[index][eq][contain2569] = res;
                }

        return memo[0][true][false];
    }

};

int main() {

    cout << Solution().rotatedDigits(10) << endl; // 4
    cout << Solution().rotatedDigits(857) << endl; // 247
    return 0;
}