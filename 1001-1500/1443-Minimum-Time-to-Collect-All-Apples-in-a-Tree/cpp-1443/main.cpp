/// Source : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
/// Author : liuyubobobo
/// Time   : 2020-05-09

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    int apple = 0;

public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

        vector<unordered_set<int>> g(n);
        for(const vector<int>& edge: edges)
            g[edge[0]].insert(edge[1]), g[edge[1]].insert(edge[0]);

        return dfs(n, g, 0, -1, hasApple);
    }

private:
    int dfs(int n, vector<unordered_set<int>>& g, int v, int p, const vector<bool>& hasApple){

        apple += hasApple[v];

        int res = 0;
        int cur = apple;
        for(int next: g[v])
            if(next != p){
                int tres = dfs(n, g, next, v, hasApple);
                if(apple != cur){
                    res += 2 + tres;
                    cur = apple;
                }
            }
        return res;
    }
};


int main() {

    return 0;
}
