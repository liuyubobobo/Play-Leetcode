/// Source : https://leetcode.com/problems/count-asterisks/
/// Author : liuyubobobo
/// Time   : 2022-06-25

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countAsterisks(string s) {

        bool out = true;
        int res = 0;
        for(char c: s){
            if(c == '|') out = !out;
            else if(c == '*') res += out;
        }
        return res;
    }
};


int main() {

    return 0;
}
