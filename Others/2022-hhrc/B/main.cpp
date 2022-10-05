/// Source : https://leetcode.cn/contest/hhrc2022/problems/0Wx4Pc/
/// Author : liuyubobobo
/// Time   : 2022-10-03

#include <iostream>
#include <vector>

using namespace std;


/// Using Segment Tree
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
        assert(l <= r);
        assert(0 <= l && l < n);
        assert(0 <= r && r < n);
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
    int longestESR(vector<int>& sales) {

        int n = sales.size();
        vector<int> data(n);
        for(int i = 0; i < n; i ++) data[i] = sales[i] > 8 ? 1 : -1;

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + data[i];

        int OFFSET = n + 5;
        SegmentTree<int> seg_tree(vector<int>(2 * n + 11, -1), [](int a, int b){return max(a, b);});
        seg_tree.update(presum.back() + OFFSET, n);
        int res = 0;
        for(int l = n - 1; l >= 0; l --){
            int cur = presum[l];
            int max_r = seg_tree.query(cur + 1 + OFFSET, 2 * n + 10);
            res = max(res, max_r - l);

            seg_tree.update(cur + OFFSET, max(seg_tree.query(cur + OFFSET), l));
        }
        return res;
    }
};


int main() {

    vector<int> sales1 = {10,2,1,4,3,9,6,9,9};
    cout << Solution().longestESR(sales1) << '\n';
    // 5

    vector<int> sales2 = {5,6,7};
    cout << Solution().longestESR(sales2) << '\n';
    // 0

    vector<int> sales3 = {6,9,6};
    cout << Solution().longestESR(sales3) << '\n';
    // 1

    vector<int> sales4 = {9,9,6};
    cout << Solution().longestESR(sales4) << '\n';
    // 3

    return 0;
}
