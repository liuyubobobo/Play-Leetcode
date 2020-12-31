/// Source : https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(|s| * |t|)
/// Space Complexity: O(|s| * |t|)
class Solution {
public:
    int countSubstrings(string s, string t) {

        vector<vector<int>> same(s.size(), vector<int>(t.size(), 0));
        for(int j = 0; j < t.size(); j ++) same[0][j] = s[0] == t[j] ? 1 : 0;
        for(int i = 0; i < s.size(); i ++) same[i][0] = s[i] == t[0] ? 1 : 0;
        for(int i = 1; i < s.size(); i ++)
            for(int j = 1; j < t.size(); j ++)
                same[i][j] = (s[i] == t[j] ? same[i - 1][j - 1] + 1 : 0);

        vector<vector<int>> diff1(s.size(), vector<int>(t.size(), 0));
        for(int j = 0; j < t.size(); j ++) diff1[0][j] = s[0] == t[j] ? 0 : 1;
        for(int i = 0; i < s.size(); i ++) diff1[i][0] = s[i] == t[0] ? 0 : 1;
        for(int i = 1; i < s.size(); i ++)
            for(int j = 1; j < t.size(); j ++)
                if(s[i] != t[j]) diff1[i][j] = 1 + same[i - 1][j - 1];
                else diff1[i][j] = diff1[i - 1][j - 1];

        int res = 0;
        for(int i = 0; i < s.size(); i ++)
            for(int j = 0; j < t.size(); j ++)
                res += diff1[i][j];
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
