/// Source : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
/// Author : liuyubobobo
/// Time   : 2022-09-10

#include <iostream>
#include <vector>

using namespace std;


/// DP + Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
template<typename T>
class SegmentTree{

private:
    int n;
    vector<T> data, tree;
    T (*combine)(T a, T b);

public:
    SegmentTree(const vector<T>& data, T (*combine)(T a, T b)): n(data.size()), data(data), tree(4 * n, 0){
        this->combine = combine;
        buildSegTree(0, 0, n - 1);
    }

    SegmentTree(int n, T (*combine)(T a, T b)): n(n), data(n, 0), tree(4 * n, 0){
        this->combine = combine;
    }

    void update(int index, T value){
        if(data[index] == value) return;
        data[index] = value;
        update(0, 0, n - 1, index, value);
    }

    T query(int index){
        assert(0 <= index && index < n);
        return data[index];
    }

    T query(int l, int r){
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
        tree[treeID] = combine(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
        return;
    }

    void update(int treeID, int l, int r, int index, T value){

        if(l == r){
            assert(l == index);
            tree[treeID] = value;
            return;
        }

        int mid = (l + r) / 2;
        if(index <= mid) update(treeID * 2 + 1, l, mid, index, value);
        else update(treeID * 2 + 2, mid + 1, r, index, value);

        tree[treeID] = combine(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
        return;
    }

    T query(int treeID, int l, int r, int ql, int qr){

        if(ql == l && qr == r)
            return tree[treeID];

        int mid = (l + r) / 2;
        if(qr <= mid) return query(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query(treeID * 2 + 2, mid + 1, r, ql, qr);

        T resl = query(treeID * 2 + 1, l, mid, ql, mid);
        T resr = query(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return combine(resl, resr);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {

        int maxv = *max_element(nums.begin(), nums.end());
        SegmentTree<int> seg_tree(maxv + 1, [](int a, int b){return max(a, b);});

        seg_tree.update(nums[0], 1);
        for(int i = 1; i < nums.size(); i ++){
            int e = nums[i];
            int l = max(e - k, 0), r = e - 1;
            int t = seg_tree.query(l, r);
            seg_tree.update(e, max(seg_tree.query(e), t + 1));
        }
        return seg_tree.query(0, maxv);
    }
};


int main() {

    vector<int> nums1 = {4,2,1,4,3,4,5,8,15};
    cout << Solution().lengthOfLIS(nums1, 3) << '\n';
    // 5

    vector<int> nums2 = {7,4,5,1,8,12,4,7};
    cout << Solution().lengthOfLIS(nums2, 5) << '\n';
    // 4

    vector<int> nums3 = {1, 5};
    cout << Solution().lengthOfLIS(nums3, 1) << '\n';
    // 1

    return 0;
}
