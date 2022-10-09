/// Source : https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
/// Author : liuyubobobo
/// Time   : 2022-10-09

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string robotWithString(string s) {

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;

        vector<char> stack;
        string res = "";
        for(char c: s){
            stack.push_back(c);
            f[c - 'a'] --;
            while(!stack.empty() && is_min(f, stack.back())){
                res += stack.back();
                stack.pop_back();
            }

        }
        while(!stack.empty()) res += stack.back(), stack.pop_back();
        return res;
    }

private:
    bool is_min(const vector<int>& f, char c){

        char min_c = 'z' + 1;
        for(int i = 0; i < 26; i ++)
            if(f[i]){
                min_c = (char)('a' + i);
                break;
            }
        return c <= min_c;
    }
};


int main() {

    string s1 = "zza";
    cout << Solution().robotWithString(s1) << '\n';
    // azz

    string s2 = "bac";
    cout << Solution().robotWithString(s2) << '\n';
    // abc

    string s3 = "bdda";
    cout << Solution().robotWithString(s3) << '\n';
    // addb

    string s4 = "vzhofnpo";
    cout << Solution().robotWithString(s4) << '\n';
    // fnohopzv

    return 0;
}
