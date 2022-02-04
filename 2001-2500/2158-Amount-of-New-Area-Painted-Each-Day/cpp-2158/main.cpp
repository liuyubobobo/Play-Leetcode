/// Source : https://leetcode.com/problems/amount-of-new-area-painted-each-day/
/// Author : liuyubobobo
/// Time   : 2022-02-04

#include <iostream>
#include <vector>

using namespace std;


/// Segment Tree
/// Time Complexity: O(q * log(max_end))
/// Space Complexity: O(max_end)
template<typename T>
class SegmentTree{

private:
    int n;
    vector<T> tree, lazy;
    T (*combine)(T a, T b);

public:
    SegmentTree(int n, T (*combine)(T a, T b)):
            n(n), tree(4 * n, 0), lazy(4 * n, 0){
        this->combine = combine;
    }

    void update(int uL, int uR, T v){
        assert(0 <= uL && uL < n);
        assert(0 <= uR && uR < n);
        assert(uL <= uR);
        update(0, 0, n-1, uL, uR, v);
    }

    T query(int qL, int qR){
        assert(0 <= qL && qL < n);
        assert(0 <= qR && qR < n);
        assert(qL <= qR);
        return query(0, 0, n - 1, qL, qR);
    }

private:
    void update(int treeID, int treeL, int treeR, int uL, int uR, T v){

        if(uL > treeR || uR < treeL) return;

        if(uL <= treeL && treeR <= uR){
            tree[treeID] = (treeR - treeL + 1) * v;
            lazy[treeID] = v;
            return;
        }

        if(lazy[treeID])
            push(treeID, treeL, treeR);

        int mid = (treeL + treeR) / 2;
        update(2 * treeID + 1, treeL, mid, uL, uR, v);
        update(2 * treeID + 2, mid + 1, treeR, uL, uR, v);
        tree[treeID] = combine(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
        return;
    }

    T query(int treeID, int treeL, int treeR, int qL, int qR){

        if(qL <= treeL && treeR <= qR)
            return tree[treeID];

        if(lazy[treeID])
            push(treeID, treeL, treeR);

        int mid = (treeL + treeR) / 2;
        if(qR <= mid) return query(2 * treeID + 1, treeL, mid, qL, qR);
        if(qL >= mid + 1) return query(2 * treeID + 2, mid + 1, treeR, qL, qR);

        T resl = query(2 * treeID + 1, treeL, mid, qL, qR);
        T resr = query(2 * treeID + 2, mid + 1, treeR, qL, qR);
        T res = combine(resl, resr);
        return res;
    }

private:
    void push(int treeID, int treeL, int treeR){

        if(treeL == treeR) return;

        T v = lazy[treeID];

        int mid = (treeL + treeR) / 2;
        int tn = treeR - treeL + 1, tnl = mid - treeL + 1, tnr = tn - tnl;

        tree[treeID * 2 + 1] = v * tnl;
        tree[treeID * 2 + 2] = v * tnr;

        lazy[treeID * 2 + 1] = v;
        lazy[treeID * 2 + 2] = v;

        lazy[treeID] = 0;
    }
};

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {

        int max_end = 0;
        for(const vector<int>& seg: paint) max_end = max(max_end, seg[1]);

        SegmentTree<int> seg_tree(max_end, [](int a, int b){return a + b;});

        int n = paint.size();
        vector<int> res(n);
        for(int i = 0; i < n; i ++){
            int l = paint[i][0], r = paint[i][1] - 1;
            int sum = seg_tree.query(l, r);
            res[i] = (r - l + 1) - sum;
            seg_tree.update(l, r, 1);
        }
        return res;
    }
};


int main() {

    return 0;
}
