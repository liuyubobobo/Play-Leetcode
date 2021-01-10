/// Source : https://leetcode.com/problems/maximum-score-from-removing-substrings/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumGain(string s, int x, int y) {

        string first = "ab", second = "ba";
        if(x < y) swap(first, second), swap(x, y);

        int res = 0;
        res += solve(s, first, x);
        res += solve(s, second, y);
        return res;
    }

private:
    int solve(string& s, const string& t, int score){

        string a = "";
        int res = 0;
        for(char c: s)
            if(!a.empty() && a.back() == t[0] && c == t[1])
                res += score, a.pop_back();
            else
                a += c;
        s = a;
        return res;
    }
};


int main() {

    cout << Solution().maximumGain("cdbcbbaaabab", 4, 5) << endl;
    // 19

    return 0;
}
