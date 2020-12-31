/// Source : https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Check middle difference and counting left and right same substring
/// Time Complexity: O(|s| * |t|)
/// Space Complexity: O(|s| * |t|)
class Solution {
public:
    int countSubstrings(string s, string t) {

        vector<vector<int>> pre(s.size(), vector<int>(t.size(), 0));
        for(int j = 0; j < t.size(); j ++) pre[0][j] = s[0] == t[j] ? 1 : 0;
        for(int i = 0; i < s.size(); i ++) pre[i][0] = s[i] == t[0] ? 1 : 0;
        for(int i = 1; i < s.size(); i ++)
            for(int j = 1; j < t.size(); j ++)
                pre[i][j] = (s[i] == t[j] ? pre[i - 1][j - 1] + 1 : 0);

        vector<vector<int>> post(s.size(), vector<int>(t.size(), 0));
        for(int j = 0; j < t.size(); j ++) post[s.size() - 1][j] = s.back() == t[j] ? 1 : 0;
        for(int i = 0; i < s.size(); i ++) post[i][t.size() - 1] = s[i] == t.back() ? 1: 0;
        for(int i = (int)s.size() - 2; i >= 0; i --)
            for(int j = (int)t.size() - 2; j >= 0; j --)
                post[i][j] = (s[i] == t[j] ? post[i + 1][j + 1] + 1 : 0);

        int res = 0;
        for(int i = 0; i < s.size(); i ++)
            for(int j = 0; j < t.size(); j ++)
                if(s[i] != t[j]){
                    int a = ((i - 1 >= 0 && j - 1 >= 0) ? pre[i - 1][j - 1] : 0) + 1;
                    int b = ((i + 1 < s.size() && j + 1 < t.size()) ? post[i + 1][j + 1] : 0) + 1;
                    res += a * b;
                }
        return res;
    }
};


int main() {

    cout << Solution().countSubstrings("aba", "baba") << endl;
    // 6

    cout << Solution().countSubstrings("ab", "bb") << endl;
    // 3

    cout << Solution().countSubstrings("a", "a") << endl;
    // 0

    cout << Solution().countSubstrings("abe", "bbc") << endl;
    // 10

    cout << Solution().countSubstrings("abbab", "bbbbb") << endl;
    // 33

    return 0;
}
