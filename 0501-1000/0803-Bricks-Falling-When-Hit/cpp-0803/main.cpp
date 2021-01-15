/// Source : https://leetcode.com/problems/bricks-falling-when-hit/
/// Author : liuyubobobo
/// Time   : 2021-01-15

#include <iostream>
#include <vector>

using namespace std;


/// UF
/// Time Complexity: O(R * C)
/// Space Complexity: O(R * C)
class UF{

private:
    vector<int> parent, sz;

public:
    UF(int n) : parent(n), sz(n, 1){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool isConnected(int p , int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p), qRoot = find(q);

        if(pRoot == qRoot) return;

        parent[pRoot] = qRoot;
        sz[qRoot] += sz[pRoot];
    }

    int size(int p){
        return sz[find(p)];
    }
};

class Solution {

private:
    const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int R, C;

public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {

        C = grid[0].size();
        grid.insert(grid.begin(), vector<int>(C, 1));
        R = grid.size();

        for(vector<int>& hit: hits){
            hit[0] ++;
            if(grid[hit[0]][hit[1]] == 1)
                grid[hit[0]][hit[1]] = -1;
        }

        UF uf(R * C);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                if(grid[i][j] == 1){
                    for(int d = 0; d < 4; d ++){
                        int x = i + dirs[d][0], y = j + dirs[d][1];
                        if(in_area(x, y) && grid[x][y] == 1)
                            uf.unionElements(i * C + j, x * C + y);
                    }
                }

        vector<int> res(hits.size());
        int pre = uf.size(0);
        for(int i = (int)hits.size() - 1; i >= 0; i --)
            if(grid[hits[i][0]][hits[i][1]] == -1){
                grid[hits[i][0]][hits[i][1]] = 1;
                for(int d = 0; d < 4; d ++){
                    int x = hits[i][0] + dirs[d][0], y = hits[i][1] + dirs[d][1];
                    if(in_area(x, y) && grid[x][y] == 1)
                        uf.unionElements(hits[i][0] * C + hits[i][1], x * C + y);
                }
                int cur = uf.size(0);
                if(cur > pre){
                    res[i] = cur - pre - 1;
                    pre = cur;
                }
            }
            else
                res[i] = 0;

        return res;
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> grid1 = {
            {1, 0, 0, 0},
            {1, 1, 1, 0}
    };
    vector<vector<int>> hits1 = {{1, 0}};
    print_vec(Solution().hitBricks(grid1, hits1));
    // 2

    vector<vector<int>> grid2 = {
            {1, 0, 0, 0},
            {1, 1, 0, 0}
    };
    vector<vector<int>> hits2 = {{1, 1}, {1, 0}};
    print_vec(Solution().hitBricks(grid2, hits2));
    // 0 0

    vector<vector<int>> grid3 = {
            {1}, {1}, {1}, {1}, {1}
    };
    vector<vector<int>> hits3 = {{3, 0}, {4, 0}, {1, 0}, {2, 0}, {0, 0}};
    print_vec(Solution().hitBricks(grid3, hits3));
    // 1 0 1 0 0

    return 0;
}
