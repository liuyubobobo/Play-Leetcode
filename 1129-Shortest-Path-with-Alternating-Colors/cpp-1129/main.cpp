/// Source : https://leetcode.com/problems/shortest-path-with-alternating-colors/
/// Author : liuyubobobo
/// Time   : 2019-07-20

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


/// BFS
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        vector<unordered_map<int, unordered_set<int>>> g(n);
        for(vector<int>& edge: red_edges)
            g[edge[0]][edge[1]].insert(1);
        for(vector<int>& edge: blue_edges)
            g[edge[0]][edge[1]].insert(2);

        queue<pair<int, int>> q;
        unordered_set<int> visited;
        vector<int> res(n, -1);

        res[0] = 0;
        for(const pair<int, unordered_set<int>>& p: g[0])
            if(p.first)
                for(int color: p.second){
                    res[p.first] = 1;
                    q.push(make_pair(p.first * 10 + color, 1));
                    visited.insert(p.first * 10 + color);
                }

        while(!q.empty()){
            int cur = q.front().first / 10;
            int color = q.front().first % 10;
            int step = q.front().second;
            q.pop();

            for(const pair<int, unordered_set<int>>& p: g[cur]){
                for(int newcolor: p.second){
                    int hash = p.first * 10 + newcolor;
                    if(!visited.count(hash) && newcolor != color){
                        q.push(make_pair(hash, step + 1));
                        if(res[p.first] == -1)
                            res[p.first] = step + 1;
                        visited.insert(hash);
                    }
                }
            }
        }
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int> > red_edges1 = {{0, 1}, {0, 2}};
    vector<vector<int> > blue_edges1 = {{1, 0}};
    print_vec(Solution().shortestAlternatingPaths(3, red_edges1, blue_edges1));
    // 0 1 1

    vector<vector<int> > red_edges2 = {{0, 1}};
    vector<vector<int> > blue_edges2 = {{1, 2}};
    print_vec(Solution().shortestAlternatingPaths(3, red_edges2, blue_edges2));
    // 0 1 2

    vector<vector<int> > red_edges3 = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
    vector<vector<int> > blue_edges3 = {{1, 2}, {2, 3}, {3, 1}};
    print_vec(Solution().shortestAlternatingPaths(5, red_edges3, blue_edges3));
    // 0 1 2 3 7

    vector<vector<int> > red_edges4 = {{2, 2}, {0, 1}, {0, 3}, {0, 0}, {0, 4}, {2, 1}, {2, 0}, {1, 4}, {3, 4}};
    vector<vector<int> > blue_edges4 = {{1, 3}, {0, 0}, {0, 3}, {4, 2}, {1, 0}};
    print_vec(Solution().shortestAlternatingPaths(5, red_edges4, blue_edges4));
    // 0 1 2 1 1

    return 0;
}