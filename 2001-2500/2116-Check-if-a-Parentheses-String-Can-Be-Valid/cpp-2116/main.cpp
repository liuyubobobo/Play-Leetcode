/// Source : https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
/// Author : liuyubobobo
/// Time   : 2022-01-28

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool canBeValid(string s, string locked) {

        int n = s.size();
        if(n % 2 == 1) return false;

        int open = 0, locked_num = 0;
        for(int i = 0; i < n; i ++){
            if(locked[i] == '1'){
                locked_num ++;
                if(s[i] == '(') open ++;
                else open --;
            }
            int t = (i + 1) - locked_num;
            if(open < 0 && t < abs(open)) return false;
        }

        open = 0, locked_num = 0;
        for(int i = n - 1; i >= 0; i --){
            if(locked[i] == '1'){
                locked_num ++;
                if(s[i] == ')') open ++;
                else open --;
            }
            int t = (n - i) - locked_num;
            if(open < 0 && t < abs(open)) return false;
        }
        return true;
    }
};


int main() {

    string s1 = "))()))", locked1 = "010100";
    cout << Solution().canBeValid(s1, locked1) << endl;
    // 1

    string s2 = "())(()(()(())()())(())((())(()())((())))))(((((((())(()))))(";
    string locked2 = "100011110110011011010111100111011101111110000101001101001111";
    cout << Solution().canBeValid(s2, locked2) << endl;
    // 0

    string s3 = "((()(()()))()((()()))))()((()(()";
    string locked3 = "10111100100101001110100010001001";
    cout << Solution().canBeValid(s3, locked3) << endl;
    // 1

    return 0;
}
