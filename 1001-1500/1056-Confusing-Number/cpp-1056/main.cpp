/// Source : https://leetcode.com/problems/confusing-number/description/
/// Author : liuyubobobo
/// Time   : 2023-01-04

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(logn)
/// Space Compelxity: O(logn)
class Solution {
public:
    bool confusingNumber(int n) {

        string s1 = to_string(n);
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        for(char& c: s2){
            if(c != '0' && c != '1' && c != '6' && c != '8' && c != '9') return false;
            if(c == '6') c = '9'; else if(c == '9') c = '6';
        }
        return s1 != s2;
    }
};


int main() {

    return 0;
}
