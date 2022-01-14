/// Source : https://leetcode.com/problems/string-to-integer-atoi/
/// Author : liuyubobobo
/// Time   : 2022-01-13

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int myAtoi(string s) {

        int i;
        for(i = 0; i < s.size() && s[i] == ' '; i ++);

        if(i == s.size()) return 0;

        bool pos = true;
        if(s[i] == '-') pos = false, i ++;
        else if(s[i] == '+') i ++;

        int j = i;
        for(j = i; j < s.size() && isdigit(s[j]); j ++);

        long long num = get_num(s.substr(i, j - i));
        if(pos) return min(num, (long long)INT_MAX);
        return max(-num, (long long)INT_MIN);
    }

private:
    long long get_num(const string& s){

        long long res = 0;
        for(char c: s){
            res = res * 10 + (c - '0');
            if(res > INT_MAX) return res;
        }
        return res;
    }
};


int main() {

    cout << Solution().myAtoi("42") << endl;
    // 42

    cout << Solution().myAtoi("   -42") << endl;
    // -42

    cout << Solution().myAtoi("4193 with words") << endl;
    // 4193

    cout << Solution().myAtoi("+1") << endl;
    // 1

    return 0;
}
