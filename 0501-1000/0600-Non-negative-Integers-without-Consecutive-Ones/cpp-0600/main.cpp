/// Source : https://leetcode.com/problems/rotated-digits/description/
/// Author : liuyubobobo
/// Time   : 2018-03-05

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
/// Same algorithm to Leetcode 788
///
/// dp[i][eq][last_one] means we search first i digits,
/// and the i-th digit is equal (or not) to the i-th digit in N (binary form)
/// and last digit of the search is last_one(true or false)
///
/// Time Complexity: O(logN)
/// Space Complexity: O(logN)
class Solution {

private:
    vector<vector<vector<int>>> memo;

public:
    int findIntegers(int num) {

        if(num == 0)
            return 1;

        string binary = to_binary(num);
        // cout << binary << endl;
        memo = vector<vector<vector<int>>>(binary.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        assert(binary[0] == '1');
        return search(0, true, false, binary);
    }

private:
    int search(int index, bool eq, bool last_one, const string& binary){

        if(index == binary.size())
            return 1;

        if(memo[index][eq][last_one] != -1)
            return memo[index][eq][last_one];

        int res = 0;
        char bound = (eq ? binary[index] : '1');
        for(char c = '0' ; c <= bound ; c ++){

            if(last_one && c == '1')
                continue;

            bool this_one = (c == '1');
            if(eq && c == bound)
                res += search(index + 1, true, this_one, binary);
            else
                res += search(index + 1, false, this_one, binary);
        }
        return memo[index][eq][last_one] = res;
    }

    string to_binary(int num){
        string res = "";
        while(num){
            res += ('0' + num%2);
            num /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {

    cout << Solution().findIntegers(0) << endl;
    cout << Solution().findIntegers(1) << endl;
    cout << Solution().findIntegers(2) << endl;
    cout << Solution().findIntegers(3) << endl;
    cout << Solution().findIntegers(4) << endl;
    cout << Solution().findIntegers(5) << endl;

    return 0;
}