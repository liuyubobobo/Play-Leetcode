/// Source : https://leetcode.com/problems/range-sum-query-2d-mutable/description/
/// Author : liuyubobobo
/// Time   : 2017-10-29

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Segment Tree
class NumMatrix {

private:
    vector<int> tree;

    vector<vector<int>> matrix;
    int n, m;

public:
    NumMatrix(vector<vector<int>> matrix) {

        if(matrix.size() == 0)
            return;

        for(vector<int> row: matrix)
            (this->matrix).push_back(row);
        n = matrix.size();
        m = matrix[0].size();

        treeBuild(0, 0, 0, n-1, m-1);
    }

    void update(int row, int col, int val) {
        update(0, 0, 0, n-1, m-1, row, col, val);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(0, 0, 0, n-1, m-1, row1, col1, row2, col2);
    }

private:
    void treeBuild(int treeID, int treeLTx, int treeLTy, int treeRBx, int treeRBy){

        if(treeLTx > treeRBx || treeLTy > treeRBy){
            while(treeID >= tree.size())
                tree.push_back(0);
            tree[treeID] = 0;
            return;
        }

        if(treeLTx == treeRBx && treeLTy == treeRBy){
            while(treeID >= tree.size())
                tree.push_back(0);
            tree[treeID] = matrix[treeLTx][treeRBy];
            return;
        }

        int midx = (treeLTx + treeRBx) / 2;
        int midy = (treeLTy + treeRBy) / 2;

        treeBuild(treeID * 4 + 1, treeLTx, treeLTy, midx, midy);
        treeBuild(treeID * 4 + 2, treeLTx, midy+1, midx, treeRBy);
        treeBuild(treeID * 4 + 3, midx + 1, treeLTy, treeRBx, midy);
        treeBuild(treeID * 4 + 4, midx + 1, midy+1, treeRBx, treeRBy);

        assert(treeID < tree.size());
        tree[treeID] = tree[treeID * 4 + 1] + tree[treeID * 4 + 2] +
                       tree[treeID * 4 + 3] + tree[treeID * 4 + 4];

        return;
    }

    void update(int treeID, int treeLTx, int treeLTy, int treeRBx, int treeRBy,
                int x, int y, int val){

        assert(treeLTx <= treeRBx && treeLTy <= treeRBy);

        if(treeLTx == treeRBx && treeLTy == treeRBy){
            assert(treeLTx == x && treeLTy == y);
            tree[treeID] = val;
            return;
        }

        int midx = (treeLTx + treeRBx) / 2;
        int midy = (treeLTy + treeRBy) / 2;

        if(x <= midx && y <= midy)
            update(treeID * 4 + 1, treeLTx, treeLTy, midx, midy, x, y, val);
        else if(x <= midx && y >= midy + 1)
            update(treeID * 4 + 2, treeLTx, midy+1, midx, treeRBy, x, y, val);
        else if(x >= midx + 1 && y <= midy)
            update(treeID * 4 + 3, midx + 1, treeLTy, treeRBx, midy, x, y, val);
        else {
            assert(x >= midx + 1 && y >= midy + 1);
            update(treeID * 4 + 4, midx + 1, midy + 1, treeRBx, treeRBy, x, y, val);
        }

        tree[treeID] = tree[treeID * 4 + 1] + tree[treeID * 4 + 2] +
                       tree[treeID * 4 + 3] + tree[treeID * 4 + 4];

        return;
    }

    int query(int treeID, int treeLTx, int treeLTy, int treeRBx, int treeRBy,
                int x1, int y1, int x2, int y2){

        if(treeLTx > treeRBx || treeLTy > treeRBy)
            return 0;

        x1 = max(treeLTx, x1);
        y1 = max(treeLTy, y1);
        x2 = min(treeRBx, x2);
        y2 = min(treeRBy, y2);

        if(x1 > x2 || y1 > y2)
            return 0;

        if(treeLTx == x1 && treeLTy == y1 && treeRBx == x2 && treeRBy == y2)
            return tree[treeID];

        int midx = (treeLTx + treeRBx) / 2;
        int midy = (treeLTy + treeRBy) / 2;

        return query(treeID * 4 + 1, treeLTx, treeLTy, midx, midy,
                         x1, y1, x2, y2) +
               query(treeID * 4 + 2, treeLTx, midy+1, midx, treeRBy,
                         x1, y1, x2, y2) +
               query(treeID * 4 + 3, midx + 1, treeLTy, treeRBx, midy,
                         x1, y1, x2, y2) +
               query(treeID * 4 + 4, midx + 1, midy + 1, treeRBx, treeRBy,
                         x1, y1, x2, y2);
    }
};

int main() {

    int matrix1[5][5] = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };
    vector<vector<int>> vec1;
    for(int i = 0 ; i < 5 ; i ++)
        vec1.push_back(vector<int>(matrix1[i], matrix1[i] + sizeof(matrix1[i])/sizeof(int)));
    NumMatrix obj1(vec1);
    cout << obj1.sumRegion(2, 1, 4, 3) << endl;
    obj1.update(3, 2, 2);
    cout << obj1.sumRegion(2, 1, 4, 3) << endl;

    cout << endl;

    // ---

    int matrix2[1][10] = {
            {0, -5, 9, 1, -8, 5 ,8, 1, 1, 5}
    };
    vector<vector<int>> vec2;
    for(int i = 0 ; i < 1 ; i ++)
        vec2.push_back(vector<int>(matrix2[i], matrix2[i] + sizeof(matrix2[i])/sizeof(int)));
    NumMatrix obj2(vec2);
    cout << obj2.sumRegion(0, 5, 0, 9) << endl;
    obj2.update(0, 3, -1);
    cout << obj2.sumRegion(0, 3, 0, 6) << endl;
    obj2.update(0, 1, 6);
    obj2.update(0, 9, 3);
    obj2.update(0, 7, 2);
    cout << obj2.sumRegion(0, 4, 0, 7) << endl;
    obj2.update(0, 4, -5);
    cout << obj2.sumRegion(0, 8, 0, 9) << endl;
    obj2.update(0, 7, 8);

    return 0;
}