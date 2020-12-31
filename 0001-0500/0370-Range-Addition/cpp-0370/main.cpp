/// Source : https://leetcode.com/problems/range-addition/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    vector<int> tree;
    vector<int> lazy;
    int n;

public:
    SegmentTree(int n){
        this->n = n;
        int size = 4*n;
        for(int i = 0 ; i < size ; i ++){
            tree.push_back(0);
            lazy.push_back(0);
        }
    }

    void update(int l, int r, int inc){
        update(0, 0, n-1, l, r, inc);
    }

    int query(int index){
        return query(0, 0, n-1, index);
    }

private:
    void update(int treeID, int treeL, int treeR, int l, int r, int inc){

        if(lazy[treeID]){
            tree[treeID] += (treeR - treeL + 1) * lazy[treeID];
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0;
        }

        if(treeL == l && treeR == r){
            tree[treeID] += (treeR - treeL + 1) * inc;
            if(treeL != treeR){
                lazy[2 * treeID + 1] += inc;
                lazy[2 * treeID + 2] += inc;
            }
            return;
        }

        int mid = (treeL + treeR) / 2;

        if(r <= mid)
            update(treeID * 2 + 1, treeL, mid, l, r, inc);
        else if(l >= mid + 1)
            update(treeID * 2 + 2, mid + 1, treeR, l, r, inc);
        else{
            update(treeID * 2 + 1, treeL, mid, l, mid, inc);
            update(treeID * 2 + 2, mid + 1, treeR, mid + 1, r, inc);
        }

        return;
    }

    int query(int treeID, int treeL, int treeR, int index){

        if(lazy[treeID]){
            tree[treeID] += (treeR - treeL + 1) * lazy[treeID];
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0;
        }

        if( treeL == treeR && treeL == index)
            return tree[treeID];

        int mid = (treeL + treeR) / 2;

        if(index <= mid)
            return query(treeID * 2 + 1, treeL, mid, index);

        assert(index >= mid + 1);
        return query (treeID * 2 + 2, mid + 1, treeR, index);
    }
};

class Solution {

public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {

        SegmentTree stree(length);
        for(vector<int> update: updates)
            stree.update(update[0], update[1], update[2]);

        vector<int> res;
        for(int i = 0 ; i < length ; i ++)
            res.push_back(stree.query(i));

        return res;
    }
};

int main() {

    int length = 5;
    int updates[5][3] = {
            {1, 3, 2},
            {2, 4, 3},
            {0, 2, -2}
    };
    vector<vector<int>> vec;
    for(int i = 0 ; i < length ; i ++)
        vec.push_back(vector<int>(updates[i], updates[i] + sizeof(updates[i])/sizeof(int)));

    vector<int> res = Solution().getModifiedArray(length, vec);
    for(int e: res)
        cout << e << " ";
    cout << endl;

    return 0;
}