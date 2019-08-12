/// Source : https://leetcode.com/problems/range-sum-query-mutable/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Segment Tree
/// Time Complexity: update: O(logn)
///                  query: O(logn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    vector<int> tree;
    vector<int> nums;

public:
    SegmentTree(const vector<int>& nums){

        if(nums.size() == 0)
            return;

        for(int num: nums)
            (this->nums).push_back(num);

        int size = 4*nums.size();
        for(int i = 0 ; i < size ; i ++)
            tree.push_back(-1);

        treeBuild(0, 0, nums.size()-1);
    }

    void update(int index, int val){
        assert(index >= 0 && index < nums.size());
        nums[index] = val;
        update(0, 0, nums.size()-1, index, val);
    }

    int query(int l, int r){
        assert(l >= 0 && l < nums.size());
        assert(r >= 0 && r < nums.size());
        return query(0, 0, nums.size()-1, l, r);
    }

    void print(){
        for(int e: tree)
            cout << e << " ";
        cout << endl;
    }

private:
    void treeBuild(int treeID, int nodeLeftBound, int nodeRightBound){

        assert(nodeLeftBound <= nodeRightBound);
        if(nodeLeftBound == nodeRightBound){
            tree[treeID] = nums[nodeLeftBound];
            return;
        }

        int mid = (nodeLeftBound + nodeRightBound) / 2;
        treeBuild(treeID * 2 + 1, nodeLeftBound, mid);
        treeBuild(treeID * 2 + 2, mid + 1, nodeRightBound);

        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
    }

    void update(int treeID, int nodeLeftBound, int nodeRightBound, int index, int val){

        assert(nodeLeftBound <= nodeRightBound);
        if(nodeLeftBound == nodeRightBound){
            assert(index == nodeLeftBound);
            tree[treeID] = val;
            return;
        }

        int mid = (nodeLeftBound + nodeRightBound)/2;
        if(index >= nodeLeftBound && index <= mid)
            update(treeID * 2 + 1, nodeLeftBound, mid, index, val);
        else
            update(treeID * 2 + 2, mid+1, nodeRightBound, index, val);

        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
    }

    int query(int treeID, int nodeLeftBound, int nodeRightBound, int l, int r){

        if(l == nodeLeftBound && r == nodeRightBound)
            return tree[treeID];

        int mid = (nodeLeftBound + nodeRightBound) / 2;
        if(r <= mid)
            return query(treeID * 2 + 1, nodeLeftBound, mid, l, r);
        if(l >= mid + 1)
            return query(treeID * 2 + 2, mid + 1, nodeRightBound, l, r);

        return query(treeID * 2 + 1, nodeLeftBound, mid, l, mid) +
                query(treeID * 2 + 2, mid + 1, nodeRightBound, mid + 1, r);
    }
};

class NumArray {

private:
    SegmentTree tree;

public:
    NumArray(vector<int> nums):tree(nums) {}

    void update(int i, int val) {
        tree.update(i, val);
    }

    int sumRange(int i, int j) {
        return tree.query(i, j);
    }
};


int main() {

    vector<int> nums1 = {1, 3, 5};
    NumArray obj1(nums1);

    cout << obj1.sumRange(0, 2) << endl;
    obj1.update(1, 2);
    cout << obj1.sumRange(0, 2) << endl;

    cout << endl;

    // ---

    vector<int> nums2 = {0, 9, 5, 7, 3};
    NumArray obj2(nums2);

    cout << obj2.sumRange(4, 4) << endl;
    cout << obj2.sumRange(2, 4) << endl;

    return 0;
}