/// Source : https://leetcode.com/problems/smallest-string-with-swaps/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS CC + Greedy
/// Time Complexity: O(|s| + |pairs| + |s|log|s|)
/// Space Complexity: O(|s| + |pairs|)
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        vector<unordered_set<int>> g(s.size());
        for(const vector<int>& p: pairs)
            g[p[0]].insert(p[1]), g[p[1]].insert(p[0]);

        vector<int> cc(s.size(), -1);
        int ccid = 0;
        for(int i = 0; i < s.size(); i ++)
            if(cc[i] == -1) dfs(g, i, ccid ++, cc);

        vector<vector<int>> poses(ccid);
        vector<string> order(ccid, "");
        for(int i = 0; i < cc.size(); i ++)
            poses[cc[i]].push_back(i), order[cc[i]] += s[i];

        for(string& s: order) sort(s.begin(), s.end());

        for(int id = 0; id < ccid; id ++){

            int index = 0;
            for(int pos: poses[id]) s[pos] = order[id][index ++];
        }
        return s;
    }

private:
    void dfs(const vector<unordered_set<int>>& g, int v, int ccid,
             vector<int>& cc){

        cc[v] = ccid;
        for(int w: g[v])
            if(cc[w] == -1) dfs(g, w, ccid, cc);
    }
};


int main() {

    return 0;
}