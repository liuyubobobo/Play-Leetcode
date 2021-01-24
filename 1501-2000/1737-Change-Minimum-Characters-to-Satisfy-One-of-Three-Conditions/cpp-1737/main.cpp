/// Source : https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


/// Brute Force
/// Time Complexity: O(|a| + |b|)
/// Space Complexity: O(1)
class Solution {
public:
    int minCharacters(string a, string b) {

        vector<int> fa(26, 0), fb(26, 0);
        for(char c: a) fa[c - 'a'] ++;
        for(char c: b) fb[c - 'a'] ++;

        int res = solve_same(fa, a.size(), fb, b.size());
        for(int s = 0; s < 26; s ++)
            for(int t = s + 1; t < 26; t ++){
                res = min(res, solve_less(fa, s, fb, t));
                res = min(res, solve_less(fb, s, fa, t));
            }
        return res;
    }

private:
    int solve_less(const vector<int>& fa, int s, const vector<int>& fb, int t){

        int res = 0;
        res += accumulate(fa.begin() + (s + 1), fa.end(), 0);
        res += accumulate(fb.begin(), fb.begin() + t, 0);
        return res;
    }

    int solve_same(const vector<int>& fa, int lena, const vector<int>& fb, int lenb){

        int res = INT_MAX;
        for(int i = 0; i < 26; i ++)
            res = min(res, lena - fa[i] + lenb - fb[i]);
        return res;
    }
};


int main() {

    cout << Solution().minCharacters("aba", "caa") << endl;
    // 2

    cout << Solution().minCharacters("dabadd", "cda") << endl;
    // 3

    return 0;
}
