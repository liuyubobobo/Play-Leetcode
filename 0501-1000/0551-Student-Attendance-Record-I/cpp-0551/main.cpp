/// Source : https://leetcode.com/problems/student-attendance-record-i/
/// Author : liuyubobobo
/// Time   : 2021-08-17

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkRecord(string s) {

        int absent = 0;
        for(char c: s)
            absent += (c == 'A');

        if(absent >= 2) return false;

        for(int i = 0; i + 2 < s.size(); i ++)
            if(s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L')
                return false;

        return true;
    }
};


int main() {

    return 0;
}
