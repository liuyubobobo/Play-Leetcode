/// Source : https://leetcode.com/problems/word-ladder-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-04-23
/// Updated: 2022-08-10

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;


/// BFS + Backtrack
/// Attention: backtrack from begin to end will get TLE
/// The following solution will backtrack result in reverse (from end to begin)
///
/// Time Complexity: O(?)
/// Space Complexity: O(?)
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
        vector<list<int>> g(n);
        for(int i = 0 ; i < wordList.size() ; i ++)
            for(int j = i + 1 ; j < wordList.size() ; j ++)
                if(similar(wordList[i], wordList[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }

        vector<int> distance = bfs(n, g, begin);
        if(distance[end] == -1) return {};

        vector<vector<string>> res;
        vector<string> tres = {wordList[end]};
        get_res(g, end, begin, distance, wordList, tres, res);

        return res;
    }

private:
    vector<int> bfs(int n, const vector<list<int>>& g, int begin){

        vector<int> distance(n, -1);

        queue<int> q;
        q.push(begin);
        distance[begin] = 0;

        while(!q.empty()){
            int cur = q.front(); q.pop();

            for(int j: g[cur])
                if(distance[j] == -1){
                    distance[j] = distance[cur] + 1;
                    q.push(j);
                }
        }

        return distance;
    }

    void get_res(vector<list<int>>& g, int cur, int end,
                 const vector<int>& distance,
                 const vector<string>& wordList,
                 vector<string>& tres, vector<vector<string>>& res){

        if(tres.size() > 0 && tres[tres.size() - 1] == wordList[end]){
            res.push_back(tres);
            reverse(res.back().begin(), res.back().end());
            return;
        }

        for(int i: g[cur])
            if(distance[i] == distance[cur] - 1){
                tres.push_back(wordList[i]);
                get_res(g, i, end, distance, wordList, tres, res);
                tres.pop_back();
            }

        return;
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


void print_vector(const vector<vector<string>>& res){
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
    print_vector(res1);

    vector<string> vec2 = {"a","b","c"};
    string beginWord2 = "a";
    string endWord2 = "c";
    vector<vector<string>> res2 = Solution().findLadders(beginWord2, endWord2, vec2);
    print_vector(res2);

    return 0;
}