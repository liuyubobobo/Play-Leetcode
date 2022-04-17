/// Source : https://leetcode-cn.com/problems/QO5KpG/
/// Author : liuyubobobo
/// Time   : 2022-04-17

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template<typename T>
class SegmentTree{

private:
    int n;
    vector<T> tree, lazy;
    T (*combine)(T a, T b);

public:
    SegmentTree(int n, T (*combine)(T a, T b)): n(n), tree(4 * n, 0), lazy(4 * n, -1){
        this->combine = combine;
    }

    void set(int uL, int uR, T v){
        if(uL > uR) return;
        set(0, 0, n - 1, uL, uR, v);
    }

    T query(int qL, int qR){
        if(qL > qR) return 0;
        return query(0, 0, n - 1, qL, qR);
    }

private:
    void set(int treeID, int treeL, int treeR, int uL, int uR, T v){

        if(uL > treeR || uR < treeL) return;

        if(uL <= treeL && treeR <= uR){
            tree[treeID] = (treeR - treeL + 1) * v;
            lazy[treeID] = v;
            return;
        }

        if(lazy[treeID] != -1)
            push(treeID, treeL, treeR);

        int mid = (treeL + treeR) / 2;
        set(2 * treeID + 1, treeL, mid, uL, uR, v);
        set(2 * treeID + 2, mid + 1, treeR, uL, uR, v);
        tree[treeID] = combine(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
        return;
    }

    T query(int treeID, int treeL, int treeR, int qL, int qR){

        if(qL <= treeL && treeR <= qR)
            return tree[treeID];

        if(lazy[treeID] != -1)
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

        lazy[treeID] = -1;
    }
};

class Solution {

public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {

        vector<int> index2value;
        init(root, index2value);

        int n = index2value.size();
//        for(int e: index2value) cout << e << ' '; cout << '\n';

        SegmentTree<int> seg_tree(n, [](int a, int b){return a + b;});

        for(const vector<int>& op: ops){
            int color = op[0], l_value = op[0], r_value = op[1];
            int l = lower_bound(index2value.begin(), index2value.end(), l_value) - index2value.begin();
            int r = (upper_bound(index2value.begin(), index2value.end(), r_value) - index2value.begin()) - 1;

//            cout << l << ' ' << r << ' ' << color << '\n';
            seg_tree.set(l, r, color);
        }
        return seg_tree.query(0, n - 1);
    }

private:
    void init(TreeNode* node, vector<int>& index2value){

        if(!node) return;

        init(node->left, index2value);
        index2value.push_back(node->val);
        init(node->right, index2value);
    }
};


int main() {

    return 0;
}
