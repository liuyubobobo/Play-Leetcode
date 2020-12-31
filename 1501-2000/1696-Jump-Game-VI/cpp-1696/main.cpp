/// Source : https://leetcode.com/problems/jump-game-vi/
/// Author : liuyubobobo
/// Time   : 2020-12-19

#include <iostream>
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
        tree[treeID] = max(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
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

        tree[treeID] = max(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
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
        return max(resl, resr);
    }
};

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {

        int n = nums.size();
        SegmentTree segTree(n);
        segTree.update(0, nums[0]);

        for(int i = 1; i < nums.size(); i ++){
            int l = max(0, i - k), r = i - 1;
            segTree.update(i, segTree.query(l, r) + nums[i]);
        }
        return segTree.query(n - 1);
    }
};


int main() {

    vector<int> nums1 = {1,-1,-2,4,-7,3};
    cout << Solution().maxResult(nums1, 2) << endl;
    // 7

    vector<int> nums2 = {10,-5,-2,4,0,3};
    cout << Solution().maxResult(nums2, 3) << endl;
    // 17

    vector<int> nums3 = {1,-5,-20,4,-1,3,-6,-3};
    cout << Solution().maxResult(nums3, 2) << endl;
    // 0

    return 0;
}
