/// Source : https://leetcode.com/problems/pacific-atlantic-water-flow/
/// Author : liuyubobobo
/// Time   : 2022-08-19

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS from inside to outside
/// Shrink vertex to remove all the cycles from the underlying search graph
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class UF{

private:
    vector<int> parent;

public:
    UF(int n) : parent(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool is_connected(int p, int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
    }
};

class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int R, C;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        R = heights.size(), C = heights[0].size();

        // uf 有 R * C 个节点。
        UF uf(R * C);
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                // 缩点
                if(!visited[i][j]){
                    vector<int> cc;
                    dfs_cc(heights, i, j, visited, cc);
                    for(int i = 1; i < cc.size(); i ++)
                        uf.union_elements(cc[0], cc[i]);
                }
            }

        // 根据缩好的点，创建新图，这张图是 DAG
        // 注意，这张图有 R * C + 2 个节点，索引 R * C 对应 pacific，索引 R * C + 1 对应 atlantic
        vector<set<int>> g(R * C + 2);
        for(int x = 0; x < R; x ++)
            for(int y = 0; y < C; y ++){

                // u 是 [x, y] 缩点后对应的点编号
                int u = uf.find(x * C + y);
                for(int d = 0; d < 4; d ++){
                    int nx = x + dirs[d][0], ny = y + dirs[d][1];
                    if(!in_area(nx, ny)) continue;

                    // v 是 [nx, ny] 缩点后对应的点编号
                    int v = uf.find(nx * C + ny);
                    if(u == v) continue;

                    // 注意，此时 height 的比较，可以扔掉 = 了，
                    // 因为 u 和 v 不是缩点后的一个节点，所以高度肯定不等
                    if(heights[x][y] > heights[nx][ny]) g[u].insert(v);
                }

                if(x == 0 || y == 0) g[u].insert(R * C);
                if(x == R - 1 || y == C - 1) g[u].insert(R * C + 1);
            }

        // 现在，可以在 g 这张新图上，做记忆化搜索了。
        // 因为这张图上边的方向已经代表了从高的地方走向低的地方，所以不需要再使用 height 数组了。
        // 但是，因为建图的方式，我们的搜索是从高向地进行的。
        vector<int> pacific(R * C + 2, -1), atlantic(R * C + 2, -1);
        for(int u = 0; u < R * C; u ++){
            if(pacific[u] == -1) dfs(g, u, pacific, atlantic);
        }

        vector<vector<int>> res;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                int u = uf.find(i * C + j);
                if(pacific[u] == 1 && atlantic[u] == 1)
                    res.push_back({i, j});
            }
        return res;
    }

private:
    void dfs_cc(const vector<vector<int>>& H, int x, int y,
                vector<vector<bool>>& visited, vector<int>& cc){

        visited[x][y] = true;
        cc.push_back(x * C + y);

        for(int d = 0; d < 4; d ++){
            int nx = x + dirs[d][0], ny = y + dirs[d][1];
            if(in_area(nx, ny) && !visited[nx][ny] && H[x][y] == H[nx][ny])
                dfs_cc(H, nx, ny, visited, cc);
        }
    }

    void dfs(const vector<set<int>>& g, int u,
            vector<int>& pacific, vector<int>& atlantic){

        if(u == R * C) pacific[u] = 1;
        if(u == R * C + 1) atlantic[u] = 1;

        if(pacific[u] != -1) return;

        for(int v: g[u]){
            dfs(g, v, pacific, atlantic);
            if(pacific[v] == 1) pacific[u] = 1;
            if(atlantic[v] == 1) atlantic[u] = 1;
        }

        if(pacific[u] != 1) pacific[u] = 0;
        if(atlantic[u] != 1) atlantic[u] = 0;
    }

    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    vector<vector<int>> heights = {
            {1,2,2,3,5},
            {3,2,3,4,4},
            {2,4,5,3,1},
            {6,7,1,4,5},
            {5,1,1,2,4}
    };
    Solution().pacificAtlantic(heights);

    return 0;
}
