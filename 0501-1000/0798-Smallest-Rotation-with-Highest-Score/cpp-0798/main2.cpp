/// Source : https://leetcode.com/problems/smallest-rotation-with-highest-score/
/// Author : liuyubobobo
/// Time   : 2022-03-08

#include <iostream>
#include <vector>

using namespace std;


/// Using Segment Tree (as Sort List)
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

    void add(int index, T v){
        if(index < 0) return;
        data[index] += v;
        update(0, 0, n - 1, index, data[index]);
    }

    T query(int index){
//        assert(0 <= index && index < n);
        return data[index];
    }

    T query(int l, int r){
//        assert(l <= r);
//        assert(0 <= l && l < n);
//        assert(0 <= r && r < n);
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
//            assert(l == index);
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
    int bestRotation(vector<int>& nums) {

        const int MAXN = 2e5;
        SegmentTree<int> tree(MAXN, [](int a, int b){return a + b;});

        int n = nums.size();
        for(int i = 0; i < n; i ++)
            tree.add(-(nums[i] - i), 1);

        int best_score = 0, k = 0;
        for(int i = 0; i < n; i ++){
            int score = tree.query(i, MAXN - 1);
//            cout << "k : " << i << " score : " << score << '\n';

            if(score > best_score) best_score = score, k = i;

            tree.add(-(nums[i] - i), -1);
            tree.add(-(nums[i] - (n - 1) - (i + 1)), 1);
        }
        return k;
    }
};


int main() {

    vector<int> nums1 = {2, 3, 1, 4, 0};
    cout << Solution().bestRotation(nums1) << '\n';
    // 3

    return 0;
}
