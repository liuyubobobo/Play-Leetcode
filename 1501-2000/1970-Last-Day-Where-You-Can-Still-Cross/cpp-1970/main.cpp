/// Source : https://leetcode.com/problems/last-day-where-you-can-still-cross/
/// Author : liuyubobobo
/// Time   : 2021-08-14

#include <iostream>
#include <vector>

using namespace std;


/// UF
/// Time Complexity: O(row * col + |cells|)
/// Space Complexity: O(row * col)
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
    const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        vector<vector<int>> g(row, vector<int>(col, 1));
        for(vector<int>& p: cells){
            p[0] --, p[1] --;
            g[p[0]][p[1]] = 0;
        }

        int s = row * col, t = row * col + 1;
        UF uf(row * col + 2);
        for(int i = 0; i < row; i ++)
            for(int j = 0; j < col; j ++)
                if(g[i][j]){
                    for(int d = 0; d < 4; d ++){
                        int nexti = i + dirs[d][0], nextj = j + dirs[d][1];
                        if(0 <= nexti && nexti < row && 0 <= nextj && nextj < col && g[nexti][nextj])
                            uf.union_elements(i * col + j, nexti * col + nextj);
                    }
                }

        for(int j = 0; j < col; j ++){
            if(g[0][j]) uf.union_elements(s, j);
            if(g[row - 1][j]) uf.union_elements((row - 1) * col + j, t);
        }

        for(int i = cells.size() - 1; i >= 0; i --){
            if(uf.is_connected(s, t)) return i + 1;

            int x = cells[i][0], y = cells[i][1];
            g[x][y] = 1;
            for(int d = 0; d < 4; d ++){
                int nextx = x + dirs[d][0], nexty = y + dirs[d][1];
                if(0 <= nextx && nextx < row && 0 <= nexty && nexty < col && g[nextx][nexty])
                    uf.union_elements(x * col + y, nextx * col + nexty);
            }
            if(x == 0) uf.union_elements(s, x * col + y);
            if(x == row - 1) uf.union_elements(x * col + y, t);
        }
        return -1;
    }
};


int main() {

    vector<vector<int>> cells1 = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};
    cout << Solution().latestDayToCross(2, 2, cells1) << endl;
    // 2

    vector<vector<int>> cells2 = {{1, 1}, {1, 2}, {2, 1}, {2, 2}};
    cout << Solution().latestDayToCross(2, 2, cells2) << endl;
    // 1

    vector<vector<int>> cells3 = {{1, 2}, {2, 1}, {3, 3}, {2, 2}, {1, 1}};
    cout << Solution().latestDayToCross(3, 3, cells3) << endl;
    // 3

    return 0;
}
