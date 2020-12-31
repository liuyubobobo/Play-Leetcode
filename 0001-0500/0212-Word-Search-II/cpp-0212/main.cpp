/// Source : https://leetcode.com/problems/word-search-ii/
/// Author : liuyubobobo
/// Time   : 2019-02-08

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// Trie + DFS
/// The Trie class is implemented in 208
///
/// Time Complexity: O(4 ^ (m * n) * maxlen)
/// Space Complexity: O(m * n + total_letters_in_words)
class Trie{

private:
    struct Node{
        unordered_map<char, int> next;
        bool end = false;
    };
    vector<Node> trie;

public:
    Trie(){
        trie.clear();
        trie.push_back(Node());
    }

    /** Inserts a word into the trie. */
    void insert(const string& word){

        int treeID = 0;
        for(char c: word){
            if(trie[treeID].next.find(c) == trie[treeID].next.end()){
                trie[treeID].next[c] = trie.size();
                trie.push_back(Node());
            }

            treeID = trie[treeID].next[c];
        }

        trie[treeID].end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word){

        int treeID = 0;
        for(char c: word){
            if(trie[treeID].next.find(c) == trie[treeID].next.end())
                return false;

            treeID = trie[treeID].next[c];
        }
        return trie[treeID].end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {

        int treeID = 0;
        for(char c: prefix){
            if(trie[treeID].next.find(c) == trie[treeID].next.end())
                return false;

            treeID = trie[treeID].next[c];
        }
        return true;
    }
};


class Solution {

private:
    int d[4][2] = {{-1, 0}, {0,1}, {1, 0}, {0, -1}};
    int m, n;
    int maxlen = 0;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        Trie trie;
        for(const string& word: words){
            trie.insert(word);
            maxlen = max(maxlen, (int)word.size());
        }

        unordered_set<string> res;

        m = board.size();
        assert( m > 0 );
        n = board[0].size();
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0 ; j < n ; j ++){
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                searchWord(board, trie, i, j, "", visited, res);
            }

        return vector<string>(res.begin(), res.end());
    }

private:
    // start from board[x][y], find word s
    void searchWord(const vector<vector<char>> &board, Trie& trie,
                    int x, int y, string s,
                    vector<vector<bool>>& visited, unordered_set<string>& res){

        s += board[x][y];
        if(s.size() > maxlen) return;
        if(!trie.startsWith(s)) return;
        if(trie.search(s)) res.insert(s);

        visited[x][y] = true;
        for(int i = 0 ; i < 4 ; i ++){
            int nextx = x + d[i][0];
            int nexty = y + d[i][1];
            if(inArea(nextx, nexty) && !visited[nextx][nexty])
                searchWord(board, trie, nextx, nexty, s, visited, res);
        }
        visited[x][y] = false;
    }

    bool inArea(int x , int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


int main() {

    return 0;
}