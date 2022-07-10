/// Source : https://leetcode.com/problems/subarray-with-elements-greater-than-varying-threshold/
/// Author : liuyubobobo
/// Time   : 2022-07-09

#include <iostream>
#include <vector>

using namespace std;


/// Divide and Conquer
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
template<typename T>
class MinIndexSegmentTree{

private:
    int n;
    vector<T> data, tree;

public:
    MinIndexSegmentTree(const vector<T>& data): n(data.size()), data(data), tree(4 * n, 0){
        buildSegTree(0, 0, n - 1);
    }

    T query(int index){
        assert(0 <= index && index < n);
        return data[index];
    }

    T query(int l, int r){
        assert(l <= r);
        assert(0 <= l && l < n);
        assert(0 <= r && r < n);
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

    T query(int treeID, int l, int r, int ql, int qr){

        if(ql == l && qr == r)
            return tree[treeID];

        int mid = (l + r) / 2;
        if(qr <= mid) return query(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query(treeID * 2 + 2, mid + 1, r, ql, qr);

        T resl = query(treeID * 2 + 1, l, mid, ql, mid);
        T resr = query(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return data[resl] < data[resr] ? resl : resr;
    }
};

class Solution {

private:
    MinIndexSegmentTree<int> *seg_tree;

public:
    int validSubarraySize(vector<int>& nums, int threshold) {

        seg_tree = new MinIndexSegmentTree<int>(nums);

        int res = solve(nums, 0, nums.size() - 1, threshold);
        return res ? res : -1;
    }

    int solve(const vector<int>& nums, int l, int r, int threshold){

        if(l > r) return 0;
        if(l == r){
            return nums[l] > threshold ? 1: 0;
        }

        int min_index = seg_tree->query(l, r);
        int min_value = nums[min_index];

        if(min_value > threshold / (r - l + 1)) return r - l + 1;

        int resl = solve(nums, l, min_index - 1, threshold);
        if(resl) return resl;
        return solve(nums, min_index + 1, r, threshold);
    }
};


int main() {

    vector<int> nums1 = {1, 3, 4, 3, 1};
    cout << Solution().validSubarraySize(nums1, 6) << '\n';
    // 3

    vector<int> nums2 = {6,5,6,5,8};
    cout << Solution().validSubarraySize(nums2, 7) << '\n';
    // 1

    return 0;
}
