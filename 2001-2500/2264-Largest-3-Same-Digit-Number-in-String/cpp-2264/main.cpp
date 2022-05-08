/// Source : https://leetcode.com/problems/largest-3-same-digit-number-in-string/
/// Author : liuyubobobo
/// Time   : 2022-05-07

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string largestGoodInteger(string num) {

        int res = -1;
        for(int i = 2; i < (int)num.size(); i ++)
            if(num[i - 2] == num[i - 1] && num[i - 1] == num[i])
                res = max(res, num[i] - '0');
        return res == -1 ? "" : string(3, '0' + res);
    }
};


int main() {

    return 0;
}
