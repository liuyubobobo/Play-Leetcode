/// Source : https://leetcode.com/problems/count-pairs-in-two-arrays/
/// Author : liuyubobobo
/// Time   : 2021-06-07

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Segment Tree
/// Time Complexity: O(nlog(max_range))
/// Space Complexity: O(max_range)
class SegmentTree{

private:
    int n;
    vector<int> data, tree;

public:
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
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        assert(n == nums2.size());
        for(int i = 0; i < n; i ++) nums1[i] -= nums2[i];
//        for(int e: nums1) cout << e << " "; cout << endl;

        int minv = *min_element(nums1.begin(), nums1.end());
        int maxv = *max_element(nums1.begin(), nums1.end());
        SegmentTree segTree(maxv - minv + 1);

        long long res = 0ll;
        for(int e: nums1){
            res += segTree.query(max(0, -e + 1 - minv), maxv - minv);
            segTree.update(e - minv, segTree.query(e - minv) + 1);
        }

        return res;
    }
};


int main() {

    vector<int> nums11 = {2,1,2,1}, nums12 = {1,2,1,2};
    cout << Solution().countPairs(nums11, nums12) << endl;
    // 1

    vector<int> nums21 = {1,10,6,2}, nums22 = {1,4,1,5};
    cout << Solution().countPairs(nums21, nums22) << endl;
    // 1

    return 0;
}
