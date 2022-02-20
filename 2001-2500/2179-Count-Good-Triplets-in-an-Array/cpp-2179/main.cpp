/// Source : https://leetcode.com/problems/count-good-triplets-in-an-array/
/// Author : liuyubobobo
/// Time   : 2022-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Using Segment Tree
/// Time Complexity: O(nlogn)
/// Space Compelxity: O(n)
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

    void add(int index, T value){
//        if(data[index] == value) return;
        data[index] += value;
        add(0, 0, n - 1, index, value);
    }

    T query(int index){
        assert(0 <= index && index < n);
        return data[index];
    }

    T query(int l, int r){

        if(l <= r && 0 <= l && l < n && 0 <= r && r < n)
            return query(0, 0, n - 1, l, r);
        return 0;
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

    void add(int treeID, int l, int r, int index, T value){

        if(l == r){
            assert(l == index);
            tree[treeID] += value;
            return;
        }

        int mid = (l + r) / 2;
        if(index <= mid) add(treeID * 2 + 1, l, mid, index, value);
        else add(treeID * 2 + 2, mid + 1, r, index, value);

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
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();

        vector<int> nums2pos(n);
        for(int i = 0; i < nums2.size(); i ++)
            nums2pos[nums2[i]] = i;

        auto add = [](long long a, long long b){return a + b;};
        SegmentTree<long long> seg_tree(n, add);
        SegmentTree<long long> good2_for_nums1(n, add), good2_for_nums2(n, add);
        long long res = 0;
        for(int i = n - 1; i >= 0; i --){
            long long t = seg_tree.query(nums2pos[nums1[i]], n - 1);
            good2_for_nums1.add(i, t);
            good2_for_nums2.add(nums2pos[nums1[i]], t);

            res += min(good2_for_nums1.query(i + 1, n - 1), good2_for_nums2.query(nums2pos[nums1[i]] + 1, n - 1));
            seg_tree.add(nums2pos[nums1[i]], 1);

        }

        return res;
    }
};


int main() {

    vector<int> nums11 = {2, 0, 1, 3}, nums12 = {0, 1, 2, 3};
    cout << Solution().goodTriplets(nums11, nums12) << endl;
    // 1

    vector<int> nums21 = {4, 0, 1, 3, 2}, nums22 = {4, 1, 0, 2, 3};
    cout << Solution().goodTriplets(nums21, nums22) << endl;
    // 4

    return 0;
}
