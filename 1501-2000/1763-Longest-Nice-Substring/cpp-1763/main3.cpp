/// Source : https://leetcode.com/problems/longest-nice-substring/
/// Author : liuyubobobo
/// Time   : 2021-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Using bitwise operation to record
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    string longestNiceSubstring(string s) {

        string res = "";
        for(int i = 0; i < s.size(); i ++){
            int lower = 0, upper = 0;
            for(int j = i; j < s.size(); j ++){
                if(islower(s[j])) lower |= 1 << (s[j] - 'a');
                else upper |= 1 << (s[j] - 'A');

                if((lower == upper) && (j - i + 1) > (int)res.size())
                    res = s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
