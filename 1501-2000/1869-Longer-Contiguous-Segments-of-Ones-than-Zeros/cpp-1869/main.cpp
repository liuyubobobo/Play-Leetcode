/// Source : https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
/// Author : liuyubobobo
/// Time   : 2021-05-22

#include <iostream>

using namespace std;


/// Split String
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkZeroOnes(string s) {

        int zero = 0, one = 0;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){

                if(s[start] == '0') zero = max(zero, i - start);
                else one = max(one, i - start);

                start = i;
                i = start;
            }
        return one > zero;
    }
};


int main() {

    return 0;
}
