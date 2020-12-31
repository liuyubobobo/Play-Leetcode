/// Source : https://leetcode.com/problems/rank-transform-of-a-matrix/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


/// Sorting + UF
/// Time Complexity: O(R * C * log(R * C))
/// Space Complexity: O(R * C)
class UF{

private:
    vector<int> parent;

public:
    UF(int n){
        for(int i = 0 ; i < n ; i ++)
            parent.push_back(i);
    }

    int find(int p){
        if( p != parent[p] )
            parent[p] = find( parent[p] );
        return parent[p];
    }

    bool isConnected(int p , int q){
        return find(p) == find(q);
    }

    void unionElements(int p, int q){

        int pRoot = find(p);
        int qRoot = find(q);

        if( pRoot == qRoot )
            return;

        parent[pRoot] = qRoot;
    }
};

class Solution {

private:
    int R, C;

public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {

        R = matrix.size();
        C = matrix[0].size();

        map<int, vector<int>> data;
        for(int i = 0; i < R; i ++)
            for(int j = 0; j < C; j ++)
                data[matrix[i][j]].push_back(i * C + j);

        vector<vector<int>> res(R, vector<int>(C, 0));
        vector<int> rowmax(R, 0), colmax(C, 0);
        UF uf(R * C);
        for(const pair<int, vector<int>>& p: data){

            unordered_map<int, vector<int>> groups = get_groups(p.second, uf);
            for(const pair<int, vector<int>>&pgroup: groups){

                //pgroup.second : one group
                int rank = 0;
                for(int v: pgroup.second)
                    rank = max(rank, max(rowmax[v / C], colmax[v % C]) + 1);

                for(int v: pgroup.second){
                    res[v / C][v % C] = rank;
                    rowmax[v / C] = max(rowmax[v / C], rank);
                    colmax[v % C] = max(colmax[v % C], rank);
                }
            }
        }
        return res;
    }

private:
    unordered_map<int, vector<int>> get_groups(const vector<int>& vec, UF& uf){

        unordered_map<int, vector<int>> rows, cols;
        for(int v: vec)
            rows[v / C].push_back(v), cols[v % C].push_back(v);

        for(const pair<int, vector<int>>& p: rows)
            for(int i = 1; i < p.second.size(); i ++)
                uf.unionElements(p.second[i], p.second[i - 1]);

        for(const pair<int, vector<int>>& p: cols)
            for(int i = 1; i < p.second.size(); i ++)
                uf.unionElements(p.second[i], p.second[i - 1]);

        unordered_map<int, vector<int>> res;
        for(int v: vec)
            res[uf.find(v)].push_back(v);
        return res;
    }
};


void print_matrix(const vector<vector<int>>& matrix){
    for(const vector<int>& row: matrix){
        for(int e: row) cout << e << " "; cout << endl;
    }
    cout << endl;
}

int main() {

    vector<vector<int>> matrix1 = {{1, 2}, {3, 4}};
    print_matrix(Solution().matrixRankTransform(matrix1));
    // 1 2
    // 2 3

    vector<vector<int>> matrix2 = {{7, 7}, {7, 7}};
    print_matrix(Solution().matrixRankTransform(matrix2));
    // 1 1
    // 1 1

    vector<vector<int>> matrix3 = {{20,-21,14}, {-19,4,19}, {22, -47,24}, {-19, 4, 19}};
    print_matrix(Solution().matrixRankTransform(matrix3));
    // 4 2 3
    // 1 3 4
    // 5 1 6
    // 1 3 4

    vector<vector<int>> matrix4 = {{7, 3, 6}, {1, 4, 5}, {9, 8, 2}};
    print_matrix(Solution().matrixRankTransform(matrix4));
    // 5 1 4
    // 1 2 3
    // 6 3 1

    vector<vector<int>> matrix5 = {{-37, -50, -3, 44}, {-37, 46, 13, -32}, {47, -42, -3, -40}, {-17, -22, -39, 24}};
    print_matrix(Solution().matrixRankTransform(matrix5));
    // 2 1 4 6
    // 2 6 5 4
    // 5 2 4 3
    // 4 3 1 5

    return 0;
}
