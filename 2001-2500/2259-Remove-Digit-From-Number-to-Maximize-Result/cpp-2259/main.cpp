/// Source : https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
/// Author : liuyubobobo
/// Time   : 2022-04-30

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    string removeDigit(string number, char digit) {

        string res(number.size() - 1, '0');
        for(int i = 0; i < number.size(); i ++)
            if(number[i] == digit){
                string cur = number.substr(0, i) + number.substr(i + 1);
//                cout << cur << '\n';
                if(cur > res) res = cur;
            }
        return res;
    }
};


int main() {

    cout << Solution().removeDigit("123", '3') << '\n';
    // 12

    cout << Solution().removeDigit("1231", '1') << '\n';
    // 231

    cout << Solution().removeDigit("551", '5') << '\n';
    // 51

    return 0;
}
