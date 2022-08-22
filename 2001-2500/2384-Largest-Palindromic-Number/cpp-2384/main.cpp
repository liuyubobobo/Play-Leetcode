/// Source : https://leetcode.com/problems/largest-palindromic-number/
/// Author : liuyubobobo
/// Time   : 2022-08-20

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Greedy
/// Time Complexity: O(|num|)
/// Space Complexity: O(1)
class Solution {
public:
    string largestPalindromic(string num) {

        vector<int> f(10, 0);
        for(char c: num) f[c - '0'] ++;

        if(f[0] == num.size()) return "0";

        map<int, int, greater<int>> even, odd;
        for(int i = 0; i < 10; i ++)
            if(f[i]){
                if(f[i] % 2 == 0) even[i] = f[i];
                else{
                    odd[i] = 1;
                    if(f[i] - 1) even[i] = f[i];
                }
            }

        string pre = "";
        for(const pair<int, int>& p: even){
            if(pre == "" && p.first == 0) continue;
            pre += string(p.second / 2, '0' + p.first);
        }

        string suf = pre;
        reverse(suf.begin(), suf.end());

        if(!odd.empty()) pre += string(1, '0' + odd.begin()->first);
        pre += suf;
        return pre;
    }
};


int main() {

    cout << Solution().largestPalindromic("444947137") << '\n';
    // 7449447

    cout << Solution().largestPalindromic("00009") << '\n';
    // 9

    cout << Solution().largestPalindromic("0000") << '\n';
    // 0

    cout << Solution().largestPalindromic("012303") << '\n';
    // 30203

    return 0;
}
