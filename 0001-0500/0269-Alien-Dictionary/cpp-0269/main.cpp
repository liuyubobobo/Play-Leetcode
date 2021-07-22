/// Source : https://leetcode.com/problems/alien-dictionary/
/// Author : liuyubobobo
/// Time   : 2021-07-22

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;


/// Radix Sorting + TopoSort
/// Time Complexity: O(characters number)
/// Space Complexity: O(|max_word|)
class Solution {
public:
    string alienOrder(vector<string>& words) {

        int n = words.size();

        map<char, set<char>> g;
        for(const string& word: words)
            for(char c: word) g[c];

        vector<char> temp(n);
        if(!build_graph(words, 0, words.size() - 1, 0, g, temp)){
//            cout << "build graph failed" << endl;
            return "";
        }

//        for(const pair<char, set<char>>& p: g){
//            cout << p.first << " : ";
//            for(char e: p.second) cout << e << ' ';
//            cout << endl;
//        }
        return bfs(g);
    }

private:
    string bfs(const map<char, set<char>>& g){

        vector<int> indegs(26, 0);
        vector<int> alphabets(26, 0);
        for(const pair<char, set<char>>& p: g){
            alphabets[p.first - 'a'] = 1;
            for(char to: p.second){
                indegs[to - 'a'] ++;
                alphabets[to - 'a'] = 1;
            }
        }

        queue<char> q;
        vector<bool> visited(26, false);
        for(int i = 0; i < 26; i ++)
            if(alphabets[i] && indegs[i] == 0){
                q.push((char)('a' + i));
                visited[i] = true;
            }

        string res = "";
        while(!q.empty()){
            char cur = q.front();
            q.pop();

            res += string(1, cur);

            if(g.count(cur) == 0) continue;

            for(char next: g.at(cur))
                if(!visited[next - 'a']){
                    indegs[next - 'a'] --;
                    if(indegs[next - 'a'] == 0){
                        q.push(next);
                        visited[next - 'a'] = true;
                    }
                }
        }
        return res.size() == accumulate(alphabets.begin(), alphabets.end(), 0) ? res : "";
    }

    bool build_graph(const vector<string>& words, int l, int r, int index,
                     map<char, set<char>>& g, vector<char>& temp){

        if(l >= r) return true;

        bool all_empty = true;
        for(int i = l; i <= r; i ++)
            if(index >= words[i].size()) temp[i] = ' ';
            else{
                temp[i] = words[i][index];
                all_empty = false;
            }

        if(all_empty) return true;

        vector<char> order;
        for(int start = l, i = l + 1; i <= r + 1; i ++)
            if(i == r + 1 || temp[i] != temp[start]){
                if(temp[start] != ' ' && find(order.begin(), order.end(), temp[start]) != order.end())
                    return false;

                if(temp[start] == ' ' && index && order.size()) return false;

                order.push_back(temp[start]);
                if(!build_graph(words, start, i - 1, index + 1, g, temp))
                    return false;
                start = i;
                i = start;
            }

        for(int i = 0; i < order.size(); i ++)
            for(int j = i + 1; j < order.size(); j ++)
                if(order[i] != ' ' && order[j] != ' ')
                    g[order[i]].insert(order[j]);
        return true;
    }
};


int main() {

    vector<string> words1 = {"wrt","wrf","er","ett","rftt"};
    cout << Solution().alienOrder(words1) << endl;
    // wertf

    vector<string> words2 = {"z","x"};
    cout << Solution().alienOrder(words2) << endl;
    // zx

    vector<string> words3 = {"z","x", "z"};
    cout << Solution().alienOrder(words3) << endl;
    // ""

    vector<string> words4 = {"z","z"};
    cout << Solution().alienOrder(words4) << endl;
    // "z"

    vector<string> words5 = {"abc","ab"};
    cout << Solution().alienOrder(words5) << endl;
    // ""

    return 0;
}
