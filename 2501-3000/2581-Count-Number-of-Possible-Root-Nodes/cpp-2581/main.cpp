/// Source : https://leetcode.com/problems/count-number-of-possible-root-nodes/description/
/// Author : liuyubobobo
/// Time   : 2023-03-04

#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;


/// Rerooting
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {

        int n = edges.size() + 1;
        vector<list<int>> tree(n);
        for(const vector<int>& edge: edges){
            int u = edge[0], v = edge[1];
            tree[u].push_back(v), tree[v].push_back(u);
        }

        set<pair<int, int>> guess_set;
        for(const vector<int>& guess: guesses){
            int u = guess[0], v = guess[1];
            guess_set.insert({u, v});
        }

        set<pair<int, int>> correct_guesses;
        dfs(tree, 0, -1, guess_set, correct_guesses);

        int res = 0;
        dfs_reroot(tree, 0, -1, guess_set, correct_guesses, k, res);
        return res;
    }

private:
    void dfs_reroot(const vector<list<int>>& tree, int u, int p,
                    const set<pair<int, int>>& guess_set, set<pair<int, int>>& correct_guesses,
                    const int k, int& res){

        if(correct_guesses.size() >= k) res ++;

        for(int v: tree[u]){
            if(v == p) continue;

            correct_guesses.erase({u, v});
            if(guess_set.count({v, u})) correct_guesses.insert({v, u});
            dfs_reroot(tree, v, u, guess_set, correct_guesses, k, res);
            correct_guesses.erase({v, u});
            if(guess_set.count({u, v})) correct_guesses.insert({u, v});
        }
    }

    void dfs(const vector<list<int>>& tree, int u, int p,
             const set<pair<int, int>>& guess_set, set<pair<int, int>>& correct_guesses){

        for(int v: tree[u]){
            if(v == p) continue;
            if(guess_set.count({u, v}))
                correct_guesses.insert({u, v});
            dfs(tree, v, u, guess_set, correct_guesses);
        }
    }
};

int main() {

    return 0;
}
