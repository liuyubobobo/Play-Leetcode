/// Source : https://leetcode.com/problems/replace-the-substring-for-balanced-string/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    vector<char> charv = {'Q', 'W', 'E', 'R'};

public:
    int balancedString(string s) {

        map<char, int> freq;
        for(char c: charv) freq[c] = 0;
        for(char c: s) freq[c] ++;

        int m = s.size() / 4;
        for(const pair<char, int>& p: freq)
            if(p.second >= m) freq[p.first] -= m;
            else freq[p.first] = 0;

        map<char, int> cur;
        for(char c: charv) cur[c] = 0;
        int l = 0, r = -1, res = INT_MAX;
        while(l < s.size()){
            if(ok(cur, freq)) res = min(res, r - l + 1), cur[s[l ++]] --;
            else if(r + 1 < s.size()) cur[s[++r]] ++;
            else break;
        }
        return res;
    }

private:
    bool ok(map<char, int>& cur, map<char, int>& demand){
        for(char c: charv)
            if(cur[c] < demand[c]) return false;
        return true;
    }
};


int main() {

    cout << Solution().balancedString("QWER") << endl;
    // 0

    cout << Solution().balancedString("QQWE") << endl;
    // 1

    cout << Solution().balancedString("QQQW") << endl;
    // 2

    cout << Solution().balancedString("QQQQ") << endl;
    // 3

    cout << Solution().balancedString("WQWRQQQW") << endl;
    // 3

    return 0;
}