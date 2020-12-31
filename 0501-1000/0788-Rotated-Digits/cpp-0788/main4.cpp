/// Source : https://leetcode.com/problems/rotated-digits/description/
/// Author : liuyubobobo
/// Time   : 2018-03-05

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
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

private:
    vector<vector<vector<int>>> memo;

public:
    int rotatedDigits(int N) {

        string N_str = to_string(N);
        memo = vector<vector<vector<int>>>(N_str.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return search(0, true, false, N_str);
    }

private:
    int search(int index,bool eq, bool contain2569, const string& s){

        if(index == s.size())
            return contain2569 ? 1 : 0;

        if(memo[index][eq][contain2569] != -1)
            return memo[index][eq][contain2569];

        int res = 0;
        char bound = eq ? s[index] : '9';
        for(char c = '0' ; c <= bound ; c ++){
            if(c == '3' || c == '4' || c == '7')
                continue;

            bool is2569 = (c == '2' || c == '5' || c == '6' || c =='9');
            if(!eq)
                res += search(index + 1, eq, contain2569 || is2569, s);
            else if(c < bound)
                res += search(index + 1, false, contain2569 || is2569, s);
            else
                res += search(index + 1, true, contain2569 || is2569, s);
        }

        return memo[index][eq][contain2569] = res;
    }

};

int main() {

    cout << Solution().rotatedDigits(10) << endl; // 4
    cout << Solution().rotatedDigits(857) << endl; // 247
    return 0;
}