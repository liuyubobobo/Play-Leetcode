/// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/
/// Author : liuyubobobo
/// Time   : 2019-04-09

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> data, tree;

public:
    SegmentTree(const vector<int>& initData){

        data = initData;
        n = initData.size();

        int LIMIT = 4 * n;
        while(LIMIT --) tree.push_back(0);
        buildSegTree(0, 0, n - 1);
    }

    int query(int l, int r){
        return query(0, 0, n - 1, l, r);
    }

private:
    void buildSegTree(int treeID, int l, int r){

        if(l == r){
            tree[treeID] = l;
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(treeID * 2 + 1, l, mid);
        buildSegTree(treeID * 2 + 2, mid + 1, r);

        /// Using this randomization to avoid deterioration
        int left = rand() % 2;
        if(left)
            tree[treeID] = data[tree[treeID * 2 + 1]] < data[tree[treeID * 2 + 2]] ?
                            tree[treeID * 2 + 1] : tree[treeID * 2 + 2];
        else
            tree[treeID] = data[tree[treeID * 2 + 1]] <= data[tree[treeID * 2 + 2]] ?
                           tree[treeID * 2 + 1] : tree[treeID * 2 + 2];
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
        return data[resl] < data[resr] ? resl : resr;
    }
};

class Solution {

public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if(!n) return 0;

        SegmentTree tree(heights);
        return get_res(heights, 0, n - 1, tree);
    }

private:
    int get_res(const vector<int>& heights, int l, int r, SegmentTree& tree){

        if(l > r) return 0;
        if(l == r) return heights[l];

        int smallest_index = tree.query(l, r);
        return max(heights[smallest_index] * (r - l + 1),
                   max(get_res(heights, l, smallest_index - 1, tree), get_res(heights, smallest_index + 1, r, tree)));
    }
};


int main() {

    return 0;
}