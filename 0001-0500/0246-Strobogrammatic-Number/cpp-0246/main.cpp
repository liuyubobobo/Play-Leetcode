/// Source : https://leetcode.com/problems/strobogrammatic-number/
/// Author : liuyubobobo
/// Time   : 2021-03-08

#include <iostream>
#include <map>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    bool isStrobogrammatic(string num) {

        const map<char, char> table = {
                {'0', '0'},
                {'1', '1'},
//                {'2', '2'},
//                {'5', '5'},
                {'6', '9'},
                {'8', '8'},
                {'9', '6'}
        };

        string r = "";
        for(char c: num)
            if(!table.count(c)) return false;
            else r += table.at(c);
        reverse(r.begin(), r.end());
        return num == r;
    }
};


int main() {

    return 0;
}
