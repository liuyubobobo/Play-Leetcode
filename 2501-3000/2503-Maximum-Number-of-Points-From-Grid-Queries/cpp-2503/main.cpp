/// Source : https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/
/// Author : liuyubobobo
/// Time   : 2022-12-15

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


/// Offline query, using UF
/// Time Complexity: O(nlogn + qlogq + q)
/// Space Complexity: O(n)
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

    bool is_connected(int p , int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
        sz[q_root] += sz[p_root];
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
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) {

        R = grid.size(), C = grid[0].size();
        int n = R * C;
        vector<pair<int, int>> v(R * C);
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++){
                int index = i * C + j;
                v[index] = {grid[i][j], index};
            }
        sort(v.begin(), v.end());

        vector<pair<int, int>> queries(q.size());
        for(int i = 0; i < q.size(); i ++) queries[i] = {q[i], i};
        sort(queries.begin(), queries.end());

        vector<int> res(q.size());

        UF uf(n);
        int i = 0;
        for(const pair<int, int>& p: queries){
            int t = p.first, q_index = p.second;
            while(i < n && v[i].first < t){
                int cx = v[i].second / C, cy = v[i].second % C;
                for(int d = 0; d < 4; d ++){
                    int nx = cx + dirs[d][0], ny = cy + dirs[d][1];
                    if(in_area(nx, ny) && grid[nx][ny] < t){
                        uf.union_elements(v[i].second, nx * C + ny);
                    }
                }
                i ++;
            }
            res[q_index] = grid[0][0] < t ? uf.size(0) : 0;
        }
        return res;
    }

private:
    bool in_area(int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
