/// Source : https://leetcode.com/problems/maximum-69-number/description/
/// Author : liuyubobobo
/// Time   : 2022-11-07

#include <iostream>

using namespace std;


/// Greedy
/// Time Complexity: O(log(num))
/// Space Complexity: O(log(num))
class Solution {
public:
    int maximum69Number (int num) {

        string s = to_string(num);
        for(char& c: s)
            if(c == '6'){
                c = '9';
                break;
            }
        return atoi(s.c_str());
    }
};


int main() {

    return 0;
}
