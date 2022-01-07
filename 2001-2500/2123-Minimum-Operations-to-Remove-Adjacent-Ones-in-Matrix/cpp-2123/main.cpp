/// Source : https://leetcode.com/problems/minimum-operations-to-remove-adjacent-ones-in-matrix/
/// Author : liuyubobobo
/// Time   : 2022-01-06

#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <map>

using namespace std;


/// Bipartite Graph
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class Hungarian{

private:
    int n, m; // m - row size, n = column size
    vector<vector<int>> g;
    vector<int> matching;

    bool is_solved = false;
    int max_matching_value;
    vector<pair<int, int>> best_matching;

public:
    Hungarian(int n, int m) : n(n), m(m), g(n), is_solved(false), matching(m, -1){}

    void add_edge(int u, int v){
        assert(u >= 0 && u < n);
        assert(v >= 0 && v < m);
        g[u].push_back(v);
    }

    int get_max_matching_value(){
        if(!is_solved) solve();
        return max_matching_value;
    }

    const vector<pair<int, int>> get_matching(){

        if(!is_solved) solve();
        return best_matching;
    }

private:
    void solve(){

        int res = 0;
        for(int i = 0; i < n; i ++){
            vector<bool> visited(m, false);
            if(dfs(i, visited)) res ++;
        }

        max_matching_value = res;

        best_matching.clear();
        for(int i = 0; i < m; i ++)
            if(matching[i] != -1) best_matching.push_back({matching[i], i});

        is_solved = true;
    }

    bool dfs(int u, vector<bool>& visited){

        for(int v: g[u])
            if(!visited[v]){
                visited[v] = true;
                if(matching[v] == -1 || dfs(matching[v], visited)){
                    matching[v] = u;
                    return true;
                }
            }
        return false;
    }
};

class Solution {

private:
    int R, C;
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int minimumOperations(vector<vector<int>>& grid) {

        R = grid.size(), C = grid[0].size();

        vector<vector<bool>> visited(R, vector<bool>(C, false));
        int res = 0;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == 1 && !visited[i][j]){

                    set<pair<int, int>> points;
                    dfs(grid, i, j, visited, points);

                    map<pair<int, int>, int> odd, even;
                    for(const pair<int, int>& p: points)
                        if((p.first + p.second) % 2) odd[p] = odd.size();
                        else even[p] = even.size();

                    Hungarian solver(odd.size(), even.size());
                    for(const pair<pair<int, int>, int>& p: odd){
                        int x = p.first.first, y = p.first.second, index = p.second;
                        for(int d = 0; d < 4; d ++){
                            if(even.count({x + dirs[d][0], y + dirs[d][1]}))
                                solver.add_edge(index, even[{x + dirs[d][0], y + dirs[d][1]}]);
                        }
                    }
                    res += solver.get_max_matching_value();
                }
        return res;
    }

private:
    void dfs(const vector<vector<int>>& grid, int x, int y,
             vector<vector<bool>>& visited, set<pair<int, int>>& points){

        visited[x][y] = true;
        points.insert({x, y});

        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && grid[nx][ny] == 1 && !visited[nx][ny])
                dfs(grid, nx, ny, visited, points);
        }
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<vector<int>> grid1 = {
            {1, 1, 0}, {0, 1, 1}, {1, 1, 1}
    };
    cout << Solution().minimumOperations(grid1) << endl;
    // 3

    vector<vector<int>> grid2 = {
            {0, 1, 0, 0, 1, 0}, {1, 1, 1, 1, 1, 1}, {0, 1, 0, 0, 1, 0}
    };
    cout << Solution().minimumOperations(grid2) << endl;
    // 3

    return 0;
}
