/// Source : https://leetcode.com/problems/word-ladder/description/
/// Author : liuyubobobo
/// Time   : 2017-11-21

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_set>

using namespace std;

/// BFS
/// Using set to store all the words and erase visited word eagerly.
/// Time Complexity: O(n*n)
/// Space Complexity: O(n)
class Solution {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // bfs
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        if(wordSet.find(beginWord) != wordSet.end())
            wordSet.erase(beginWord);

        vector<string> visited;

        while(!q.empty()){
            string curWord = q.front().first;
            int curStep = q.front().second;
            q.pop();

            visited.clear();
            for(string word: wordSet)
                if(similar(word, curWord)){
                    if(word == endWord)
                        return curStep + 1;
                    q.push(make_pair(word, curStep + 1));
                    visited.push_back(word);
                }

            for(string word: visited)
                wordSet.erase(word);
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