/// Source : https://leetcode.com/problems/sliding-window-maximum/description/
/// Author : liuyubobobo
/// Time   : 2020-04-27

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;


/// Using Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> data, tree;

public:
    SegmentTree(const vector<int>& initData): data(initData), n(initData.size()), tree(4 * n){
        buildSegTree(0, 0, n - 1);
    }

    int query(int qL, int qR){
        return query(0, 0, n-1, qL, qR);
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
        tree[treeID] = max(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
        return;
    }

    int query(int treeID, int treeL, int treeR, int qL, int qR){

        if(treeL > qR || treeR < qL) return 0;

        if(qL <= treeL && qR >= treeR)
            return tree[treeID];

        int mid = (treeL + treeR) / 2;
        int leftRes = query(2 * treeID + 1, treeL, mid, qL, qR);
        int rightRes = query(2 * treeID + 2, mid + 1, treeR, qL, qR);
        return max(leftRes, rightRes);
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if(k == 0 || nums.size() == 0)
            return vector<int>();

        if(k == 1) return nums;

        SegmentTree segmentTree(nums);
        vector<int> res;
        for(int i = k - 1 ; i < nums.size() ; i ++)
            res.push_back(segmentTree.query(i - (k - 1), i));

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    print_vec(Solution().maxSlidingWindow(nums, 3));
    // 3 3 5 5 6 7

    return 0;
}