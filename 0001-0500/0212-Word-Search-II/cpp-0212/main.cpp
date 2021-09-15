/// Source : https://leetcode.com/problems/word-search-ii/
/// Author : liuyubobobo
/// Time   : 2019-02-08
/// Updated: 2021-09-15

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Trie + DFS
/// Time Complexity: O(4 ^ (m * n) * maxlen)
/// Space Complexity: O(m * n + total_letters_in_words)
class Solution {

private:
    class Node{
    public:
        vector<Node*> next;
        bool end = false;

        Node() : next(26, nullptr){};
    };
    Node* root = nullptr;

    const int d[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
    int R, C, maxlen = 0;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        root = new Node;
        for(const string& word: words){
            insert(word);
            maxlen = max(maxlen, (int)word.size());
        }

        set<string> res;

        R = board.size();
        assert(R > 0);
        C = board[0].size();
        for(int i = 0 ; i < R ; i ++)
            for(int j = 0 ; j < C ; j ++){
                vector<vector<bool>> visited(R, vector<bool>(C, false));
                Node* cur = root;
                string s = "";
                searchWord(board, i, j, cur, s, visited, res);
            }

        return vector<string>(res.begin(), res.end());
    }

private:
    // start from board[x][y], find word s
    void searchWord(const vector<vector<char>> &board, int x, int y, Node* cur, string& s,
                    vector<vector<bool>>& visited, set<string>& res){

        if(cur->next[board[x][y] - 'a'] == nullptr) return;

        s += board[x][y];
        if(s.size() > maxlen) return;

        cur = cur->next[board[x][y] - 'a'];
        if(cur->end) res.insert(s);

        visited[x][y] = true;
        for(int i = 0 ; i < 4 ; i ++){
            int nextx = x + d[i][0];
            int nexty = y + d[i][1];
            if(in_area(nextx, nexty) && !visited[nextx][nexty])
                searchWord(board, nextx, nexty, cur, s, visited, res);
        }
        visited[x][y] = false;
        s.pop_back();
    }

    void insert(const string& word){

        Node* cur = root;
        for(char c: word){
            if(cur->next[c - 'a'] == nullptr)
                cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }

    bool in_area(int x , int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


void print_vec(const vector<string>& v){
    for(const string& s: v) cout << s << ' ';
    cout << '\n';
}

int main() {

    vector<vector<char>> board1 = {{'o','a','a','n'},
                                   {'e','t','a','e'},
                                   {'i','h','k','r'},
                                   {'i','f','l','v'}};
    vector<string> words1 = {"oath","pea","eat","rain"};
    print_vec(Solution().findWords(board1, words1));

    return 0;
}