/// Source : https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/
/// Author : liuyubobobo
/// Time   : 2022-03-19

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {

        string s1 = string(1, pattern[0]) + text;
        long long res1 = get_res(s1, pattern[0], pattern[1]);

        string s2 = text + pattern[1];
        long long res2 = get_res(s2, pattern[0], pattern[1]);

        return max(res1, res2);
    }

private:
    long long get_res(const string& s, char a, char b){

        long long bnum = 0;
        for(char c: s) bnum += (c == b);

        if(a == b) return bnum * (bnum - 1) / 2ll;

        long long res = 0, anum = 0;
        for(char c: s)
            if(c == a) anum ++, res +=  bnum;
            else if(c == b) bnum --;
        return res;
    }
};


int main() {

    cout << Solution().maximumSubsequenceCount("abdcdbc", "ac") << '\n';
    // 4

    cout << Solution().maximumSubsequenceCount("aabb", "ab") << '\n';
    // 6

    cout << Solution().maximumSubsequenceCount("mffiqmrvjmkfmbnaivajzecfdta", "hh") << '\n';
    // 0

    return 0;
}
