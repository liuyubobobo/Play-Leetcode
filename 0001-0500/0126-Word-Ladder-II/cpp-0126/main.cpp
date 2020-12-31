/// Source : https://leetcode.com/problems/word-ladder-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-04-23

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_map>

using namespace std;

/// BFS
/// Time Complexity: O(n*n)
/// Space Complexity: O(n)
class Solution {

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if(end == wordList.size())
            return {};

        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if(begin == wordList.size())
            wordList.push_back(beginWord);

        int n = wordList.size();

        // Create Graph
        vector<vector<int>> g(n, vector<int>());
        for(int i = 0 ; i < wordList.size() ; i ++)
            for(int j = i + 1 ; j < wordList.size() ; j ++)
                if(similar(wordList[i], wordList[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }

        unordered_map<int, int> distance;
        bfs(g, begin, end, distance);

        vector<vector<string>> res;
        vector<int> tres = {begin};
        getRes(g, begin, end, distance, wordList, tres, res);

        return res;
    }

private:
    void bfs(const vector<vector<int>>& g, int begin, int end,
             unordered_map<int, int>& distance){

        queue<int> q;
        q.push(begin);
        distance[begin] = 0;

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            // assert(distance.find(cur) != distance.end());

            for(int j: g[cur])
                if(distance.find(j) == distance.end()){
                    distance[j] = distance[cur] + 1;
                    q.push(j);
                }
        }
    }

    void getRes(vector<vector<int>>& g, int cur, int end,
                unordered_map<int, int>& distance,
                const vector<string>& wordList,
                vector<int>& tres, vector<vector<string>>& res){

        if(tres.size() > 0 && tres[tres.size() - 1] == end){
            res.push_back(getPath(tres, wordList));
            return;
        }

        for(int i: g[cur])
            if(distance[i] == distance[cur] + 1){
                tres.push_back(i);
                getRes(g, i, end, distance, wordList, tres, res);
                tres.pop_back();
            }

        return;
    }

    vector<string> getPath(const vector<int>& path,
                           const vector<string>& wordList){
        vector<string> ret;
        for(const int e: path)
            ret.push_back(wordList[e]);
        return ret;
    }

    bool similar(const string& word1, const string& word2){

        // assert(word1 != "" && word1.size() == word2.size() && word1 != word2);

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


void print_vector_vector(const vector<vector<string>>& res){
    for(const vector<string>& v: res){
        for(const string& e: v)
            cout << e << " ";
        cout << endl;
    }
    cout << endl;
}

int main() {

    vector<string> vec1 = {"hot","dot","dog","lot","log","cog"};
    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<vector<string>> res1 = Solution().findLadders(beginWord1, endWord1, vec1);
    print_vector_vector(res1);

    // ---

    vector<string> vec2 = {"a","b","c"};
    string beginWord2 = "a";
    string endWord2 = "c";
    vector<vector<string>> res2 = Solution().findLadders(beginWord2, endWord2, vec2);
    print_vector_vector(res2);

    return 0;
}