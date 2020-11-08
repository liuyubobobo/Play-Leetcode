/// Source : https://leetcode.com/problems/create-sorted-array-through-instructions/
/// Author : liuyubobobo
/// Time   : 2020-11-07

#include <iostream>
#include <set>
#include <vector>

using namespace std;


/// Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> data, tree;

public:
    SegmentTree(const vector<int>& data): n(data.size()), data(data), tree(4 * n, 0){
        buildSegTree(0, 0, n - 1);
    }

    SegmentTree(int n): n(n), data(n, 0), tree(4 * n, 0){}

    void update(int index, int value){
        data[index] = value;
        update(0, 0, n - 1, index, value);
    }

    int query(int index){
        return data[index];
    }

    int query(int l, int r){
        if(l > r) return 0;
        return query(0, 0, n - 1, l, r);
    }

private:
    void buildSegTree(int treeID, int l, int r){

        if(l == r){
            tree[treeID] = data[l];
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(treeID * 2 + 1, l, mid);
        buildSegTree(treeID * 2 + 2, mid + 1, r);
        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
        return;
    }

    void update(int treeID, int l, int r, int index, int value){

        if(l == r){
            assert(l == index);
            tree[treeID] = value;
            return;
        }

        int mid = (l + r) / 2;
        if(index <= mid) update(treeID * 2 + 1, l, mid, index, value);
        else update(treeID * 2 + 2, mid + 1, r, index, value);

        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
        return;
    }

    int query(int treeID, int l, int r, int ql, int qr){

        if(ql == l && qr == r)
            return tree[treeID];

        int mid = (l + r) / 2;
        if(qr <= mid) return query(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query(treeID * 2 + 2, mid + 1, r, ql, qr);

        int resl = query(treeID * 2 + 1, l, mid, ql, mid);
        int resr = query(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return resl + resr;
    }
};

class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int createSortedArray(vector<int>& instructions) {

        SegmentTree tree(1e5 + 1);
        int res = 0;
        for(int e: instructions){
            tree.update(e, tree.query(e) + 1);
            int left = tree.query(0, e - 1), right = tree.query(e + 1, 1e5);
            res += min(left, right);
            res %= MOD;
        }
        return res;
    }
};


int main() {

    vector<int> ins1 = {1,5,6,2};
    cout << Solution().createSortedArray(ins1) << endl;
    // 1

    vector<int> ins2 = {1,2,3,6,5,4};
    cout << Solution().createSortedArray(ins2) << endl;
    // 3

    vector<int> ins3 = {1,3,3,3,2,4,2,1,2};
    cout << Solution().createSortedArray(ins3) << endl;
    // 4

    return 0;
}
