/// Source : https://leetcode-cn.com/problems/broken-board-dominoes/
/// Author : liuyubobobo
/// Time   : 2020-04-22

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Bipartition Match
/// Time Complexity: O(n * m * n * m)
/// Space Complexity: O(n * m)
class Solution {

private:
    int n, m;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int domino(int n, int m, vector<vector<int>>& broken) {

        this->n = n, this->m = m;
        vector<vector<int>> board(n, vector<int>(m, 0));
        for(const vector<int>& p: broken)
            board[p[0]][p[1]] = 1;

        vector<set<int>> g(n * m);
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++)
                if(!board[i][j])
                    for(int d = 0; d < 4; d ++){
                        int nexti = i + dirs[d][0], nextj = j + dirs[d][1];
                        if(in_area(nexti, nextj) && !board[nexti][nextj])
                            g[i * m + j].insert(nexti * m + nextj),
                            g[nexti * m + nextj].insert(i * m + j);
                    }

        vector<int> colors(n * m, -1);
        for(int i = 0; i < n * m; i ++)
            if(colors[i] == -1)
                fillcolor(g, i, 0, colors);

        return max_match(g, colors);
    }

private:
    int max_match(const vector<set<int>>& g, const vector<int>& colors){

        vector<int> matching(g.size(), -1);

        int res = 0;
        for(int i = 0; i < g.size(); i ++)
            if(colors[i] == 0 && matching[i] == -1){
                vector<bool> visited(g.size(), false);
                if(dfs(g, i, visited, matching)) res ++;
            }
        return res;
    }

    bool dfs(const vector<set<int>>& g, int v, vector<bool>& visited, vector<int>& matching){

        visited[v] = true;
        for(int u: g[v])
            if(!visited[u]){
                visited[u] = true;
                if(matching[u] == -1 || dfs(g, matching[u], visited, matching)){
                    matching[u] = v;
                    matching[v] = u;
                    return true;
                }
            }
        return false;
    }

    void fillcolor(const vector<set<int>>& g, int v, int color, vector<int>& colors){

        colors[v] = color;
        for(int next: g[v])
            if(colors[next] == -1)
                fillcolor(g, next, 1 - color, colors);
    }

    bool in_area(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
};


int main() {

    vector<vector<int>> broken1 = {{1, 0}, {1, 1}};
    cout << Solution().domino(2, 3, broken1) << endl;
    // 2

    vector<vector<int>> broken2 = {};
    cout << Solution().domino(3, 3, broken2) << endl;
    // 4

    return 0;
}