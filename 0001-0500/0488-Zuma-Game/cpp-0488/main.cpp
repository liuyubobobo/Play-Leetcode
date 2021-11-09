/// Source : https://leetcode.com/problems/zuma-game/
/// Author : liuyubobobo
/// Time   : 2021-11-09

#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_set>

using namespace std;


/// DFS
/// Time Complexity: O(n!)
/// Space Complexity: O(n!)
class Solution {

private:
    const map<char, int> char2num = {{'R', 0}, {'Y', 1}, {'B', 2}, {'G', 3}, {'W', 4}};

public:
    int findMinStep(string board_str, string hand_str){

        string board = board_str;
        for(int i = 0; i < board_str.size(); i ++) board[i] = ('0' + char2num.at(board_str[i]));

        string hand_f(5, '0');
        for(int i =0; i < hand_str.size(); i ++) hand_f[char2num.at(hand_str[i])] ++;

        int res = INT_MAX;
        unordered_set<string> visited;
        dfs(board, hand_f, hand_str.size(), res, visited);
        return res == INT_MAX ? -1 : res;
    }


private:
    void dfs(const string& s, string& hand_f, const int handnum, int& res,
             unordered_set<string>& visited){

        string hash = s + "#" + hand_f;
        if(visited.count(hash)) return;

        if(s == ""){
            int left = 0;
            for(char c: hand_f) left += (c - '0');
            res = min(res, handnum - left);
            visited.insert(hash);
            return;
        }

        for(int start = 0, i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                if(i - start >= 3){
                    dfs(s.substr(0, start) + s.substr(i), hand_f, handnum, res, visited);
                    visited.insert(hash);
                    return;
                }
                start = i;
            }

        for(int card = 0; card < hand_f.size(); card ++)
            if(hand_f[card] > '0'){
                string news;
                for(int start = 0, i = 1; i <= s.size(); i ++)
                    if(i == s.size() || s[i] != s[start]){
                        if(card == s[start] - '0'){
                            news = s.substr(0, i) + string(1, '0' + card) + s.substr(i);
                            hand_f[card] --;
                            dfs(news, hand_f, handnum, res, visited);
                            hand_f[card] ++;
                        }
                        else{
                            news = s.substr(0, start) + string(1, '0' + card) + s.substr(start);
                            hand_f[card] --;
                            dfs(news, hand_f, handnum, res, visited);
                            hand_f[card] ++;

                            news = s.substr(0, i) + string(1, '0' + card) + s.substr(i);
                            hand_f[card] --;
                            dfs(news, hand_f, handnum, res, visited);
                            hand_f[card] ++;

                            if(i - start > 1){
                                news = s.substr(0, start + 1) + string(1, '0' + card) + s.substr(start + 1);
                                hand_f[card] --;
                                dfs(news, hand_f, handnum, res, visited);
                                hand_f[card] ++;
                            }
                        }
                        start = i;
                    }
            }

        visited.insert(hash);
    }
};


int main() {

    cout << Solution().findMinStep("WWRRBBWW", "WRBRW") << endl;
    // 2

    cout << Solution().findMinStep("RBYYBBRRB", "YRBGB") << endl;
    // 3

    cout << Solution().findMinStep("RRWWRRBBRR", "WB") << endl;
    // 2

    cout << Solution().findMinStep("WWBBWBBWW", "BB") << endl;
    // -1

    return 0;
}
