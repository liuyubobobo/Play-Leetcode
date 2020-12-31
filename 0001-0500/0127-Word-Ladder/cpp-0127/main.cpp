/// Source : https://leetcode.com/problems/word-ladder/description/
/// Author : liuyubobobo
/// Time   : 2017-11-21

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// BFS
/// Time Complexity: O(n*n)
/// Space Complexity: O(n)
class Solution {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if(end == wordList.size())
            return 0;

        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if(begin == wordList.size())
            wordList.push_back(beginWord);

        int n = wordList.size();

        vector<vector<bool>> g(n, vector<bool>(n, false));
        for(int i = 0 ; i < wordList.size() ; i ++)
            for(int j = 0 ; j < i ; j ++)
                g[i][j] = g[j][i] = similar(wordList[i], wordList[j]);

        // bfs
        queue<int> q;
        vector<int> step(n, 0);

        q.push(begin);
        step[begin] = 1;
        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for(int i = 0 ; i < n ; i ++)
                if(step[i] == 0 && g[cur][i]){
                    if(i == end)
                        return step[cur] + 1;
                    step[i] = step[cur] + 1;
                    q.push(i);
                }
        }

        return 0;
    }

private:
    bool similar(const string& word1, const string& word2){

        assert(word1 != "" && word1.size() == word2.size() && word1 != word2);

        int diff = 0;
        for(int i = 0 ; i < word1.size() ; i ++)
            if(word1[i] != word2[i]){
                diff ++;
                if(diff > 1)
                    return false;
            }
        return true;
    }
};

int main() {

    vector<string> vec1 = {"hot","dot","dog","lot","log","cog"};
    string beginWord1 = "hit";
    string endWord1 = "cog";
    cout << Solution().ladderLength(beginWord1, endWord1, vec1) << endl;
    // 5

    // ---

    vector<string> vec2 = {"a","b","c"};
    string beginWord2 = "a";
    string endWord2 = "c";
    cout << Solution().ladderLength(beginWord2, endWord2, vec2) << endl;
    // 2

    return 0;
}