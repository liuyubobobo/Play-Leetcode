/// Source : https://leetcode.cn/problems/rMeRt2/
/// Author : liuyubobobo
/// Time   : 2022-10-07

#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <cstring>

using namespace std;


/// Memoization
/// Time Complexity: O(1000 * n * m * 2^m)
/// Space Complexity: O(1000 * n * 2^m)
int dp[2][2][5][2][4][3][2][25][1 << 8];

class Solution {

private:
    const string target = "helloleetcode";
    vector<int> c2index;
    const int INF = INT_MAX / 2;

public:
    int Leetcode(vector<string>& words) {

        c2index.resize(26, -1);
        c2index['c' - 'a'] = 0;
        c2index['d' - 'a'] = 1;
        c2index['e' - 'a'] = 2;
        c2index['h' - 'a'] = 3;
        c2index['l' - 'a'] = 4;
        c2index['o' - 'a'] = 5;
        c2index['t' - 'a'] = 6;

        vector<int> leftv = {1, 1, 4, 1, 3, 2, 1};
        memset(dp, -1, sizeof(dp));

        int res = dfs(words.size(), words, leftv, 0, 0, 13);
        return res == INF ? -1 : res;
    }

private:
    int dfs(int n, const vector<string>& words,
            vector<int>& l, int index, int word_state, int left){

        if(index == n) return left == 0 ? 0 : INF;

        if(dp[l[0]][l[1]][l[2]][l[3]][l[4]][l[5]][l[6]][index][word_state] != -1)
            return dp[l[0]][l[1]][l[2]][l[3]][l[4]][l[5]][l[6]][index][word_state];

        int res = dfs(n, words, l, index + 1, 0, left);
        for(int i = 0; i < words[index].size(); i ++)
            if(((word_state >> i) & 1) == 0){
                int cindex = c2index[words[index][i] - 'a'];
                if(cindex != -1 && l[cindex] > 0){
                    int a = i - __builtin_popcount(word_state & ((1 << i) - 1));
                    int b = words[index].size() - 1 - i - __builtin_popcount(word_state >> (i + 1));
//                    assert(a >= 0 && b >= 0);
                    l[cindex] --;
                    res = min(res, a * b + dfs(n, words, l, index, word_state + (1 << i), left - 1));
                    l[cindex] ++;
                }
            }
        return dp[l[0]][l[1]][l[2]][l[3]][l[4]][l[5]][l[6]][index][word_state] = res;
    }
};


int main() {

    vector<string> words1 = {"engineer","hold","cost","level"};
    cout << Solution().Leetcode(words1) << '\n';
    // 5

    vector<string> words2 = {"hello","leetcode"};
    cout << Solution().Leetcode(words2) << '\n';
    // 0

    vector<string> words3 = {"ecleob","rho","tw","lpl","ebolddec"};
    cout << Solution().Leetcode(words3) << '\n';
    // 6

    return 0;
}
