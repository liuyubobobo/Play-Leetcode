/// Source : https://leetcode.com/problems/number-of-islands-ii/description/
/// Author : liuyubobobo
/// Time   : 2023-02-15

#include <iostream>
#include <vector>

using namespace std;


/// Using UF
/// Time Complexity: O(|positions|)
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
    const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<int> numIslands2(int R, int C, vector<vector<int>>& positions) {

        vector<vector<int>> g(R, vector<int>(C, 0));
        int sz = 0;

        vector<int> res;

        UF uf(R * C);
        for(const vector<int>& pos: positions){
            int x = pos[0], y = pos[1];
            if(g[x][y] != 1){
                g[x][y] = 1; sz ++;
                for(int d = 0; d < 4; d ++){
                    int nx = x + dirs[d][0], ny = y + dirs[d][1];
                    if(!in_area(R, C, nx, ny) || g[nx][ny] == 0 || uf.is_connected(x * C + y, nx * C + ny))
                        continue;
                    uf.union_elements(x * C + y, nx * C + ny);
                    sz --;
                }
            }
            res.push_back(sz);
        }
        return res;
    }

    bool in_area(int R, int C, int x, int y){
        return 0 <= x && x < R && 0 <= y && y < C;
    }
};


int main() {

    return 0;
}
