/// Source : https://leetcode.com/problems/length-of-last-word/
/// Author : liuyubobobo
/// Time   : 2021-09-20

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {

        int res = 0;
        for(int start = next_letter(s, 0), i = start + 1; i <= s.size(); i ++){
            if(i == s.size() || s[i] == ' '){
                res = i - start;
                start = next_letter(s, i);
                i = start;
            }
        }
        return res;
    }

private:
    int next_letter(const string& s, int start){
        for(int i = start; i < s.size(); i ++)
            if(s[i] != ' ') return i;
        return INT_MAX / 2;
    }
};


int main() {

    return 0;
}
