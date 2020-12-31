/// Source : https://leetcode.com/problems/word-ladder/description/
/// Author : liuyubobobo
/// Time   : 2017-11-21

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// Bi-directional BFS
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


        // bi-derectional-bfs
        vector<int> step_s(n, 0);
        vector<int> step_t(n, 0);

        queue<int> queue_s;
        queue<int> queue_t;

        queue_s.push(begin);
        step_s[begin] = 1;

        queue_t.push(end);
        step_t[end] = 1;
        while(!queue_s.empty() && !queue_t.empty()){

            int cur_s = queue_s.front();
            queue_s.pop();

            int cur_t = queue_t.front();
            queue_t.pop();

            for(int i = 0 ; i < wordList.size() ; i ++)
                if(step_s[i] == 0 && g[cur_s][i]){
                    step_s[i] = step_s[cur_s] + 1;
                    queue_s.push(i);
                }

            for(int i = 0 ; i < wordList.size() ; i ++)
                if(step_t[i] == 0 && g[cur_t][i]){
                    step_t[i] = step_t[cur_t] + 1;
                    queue_t.push(i);
                }

            // check intersection
            int res = INT_MAX;
            for(int i = 0 ; i < wordList.size() ; i ++)
                if(step_s[i] != 0 && step_t[i] != 0)
                    res = min(res, step_s[i] + step_t[i] - 1);

            if(res != INT_MAX)
                return res;
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

    // ---

    vector<string> vec3 = {"most","fist","lost","cost","fish"};
    string beginWord3 = "lost";
    string endWord3 = "cost";
    cout << Solution().ladderLength(beginWord3, endWord3, vec3) << endl;
    // 2

    return 0;
}