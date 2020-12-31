/// Source : https://leetcode.com/problems/largest-rectangle-in-histogram/
/// Author : liuyubobobo
/// Time   : 2020-05-13

#include <iostream>
#include <vector>

using namespace std;


/// Divide and Conquer + Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> data, tree;

public:
    SegmentTree(const vector<int>& data): data(data.begin(), data.end()), n(data.size()), tree(4*n, 0){
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
        tree[treeID] = data[tree[treeID * 2 + 1]] < data[tree[treeID * 2 + 2]] ? tree[treeID * 2 + 1] : tree[treeID * 2 + 2];
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

private:
    int n;

public:
    int largestRectangleArea(vector<int>& heights) {

        n = heights.size();
        if(!n) return 0;

        SegmentTree tree(heights);
        return largest(heights, 0, n - 1, tree);
    }

private:
    int largest(const vector<int>& heights, int l, int r, SegmentTree& tree){

        if(l > r) return 0;
        if(l == r) return heights[l];

        int min_index = tree.query(l, r);
        int res = largest(heights, l, min_index - 1, tree);
        res = max(res, largest(heights, min_index + 1, r, tree));
        res = max(res, heights[min_index] * (r - l + 1));
        return res;
    }
};


int main() {

    vector<int> heights = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(heights) << endl;
    // 10

    return 0;
}
