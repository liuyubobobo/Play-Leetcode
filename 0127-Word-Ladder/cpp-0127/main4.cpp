/// Source : https://leetcode.com/problems/word-ladder/description/
/// Author : liuyubobobo
/// Time   : 2017-11-21
/// Updated: 2018-03-27

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_map>

using namespace std;

/// Bi-directional BFS
/// No need to calculate all pairs similarity
/// Time Complexity: O(n*n)
/// Space Complexity: O(n)
class Solution {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;

        // bi-derectional bfs
        unordered_map<string, int> step_s;
        unordered_map<string, int> step_t;

        queue<string> queue_s;
        queue<string> queue_t;

        queue_s.push(beginWord);
        step_s[beginWord] = 1;

        queue_t.push(endWord);
        step_t[endWord] = 1;
        while(!queue_s.empty() && !queue_t.empty()){

            string sWord = queue_s.front();
            queue_s.pop();

            string tWord = queue_t.front();
            queue_t.pop();

            for(string word: wordList){
                if(step_s.find(word) == step_s.end() && similar(word, sWord)){
                    step_s[word] = step_s[sWord] + 1;
                    queue_s.push(word);
                }

                if(step_t.find(word) == step_t.end() && similar(word, tWord)){
                    step_t[word] = step_t[tWord] + 1;
                    queue_t.push(word);
                }
            }

            // check intersection
            int res = INT_MAX;
            for(string word: wordList)
                if(step_s.find(word) != step_s.end() && step_t.find(word) != step_t.end())
                    res = min(res, step_s[word] + step_t[word] - 1);

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

    // ---

    vector<string> vec4 = {"hot","dot","dog","lot","log"};
    string beginWord4 = "hit";
    string endWord4 = "cog";
    cout << Solution().ladderLength(beginWord4, endWord4, vec4) << endl;
    // 0

    return 0;
}