/// Source : https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>

using namespace std;


/// Segment Tree
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

    void update(int treeID, int l, int r, int index, int value){

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
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

        int maxv = *max_element(obstacles.begin(), obstacles.end());

        auto combine = [](int a, int b){return max(a, b);};
        SegmentTree<int> seg_tree(maxv + 1, combine);

        int n = obstacles.size();
        vector<int> res(n, 1);
        seg_tree.update(obstacles[0], 1);
        for(int i = 1; i < n; i ++){
            int x = seg_tree.query(0, obstacles[i]);
            res[i] = x + 1;
            seg_tree.update(obstacles[i], max(seg_tree.query(obstacles[i]), res[i]));
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << endl;
}

int main() {

    vector<int> nums1 = {1,2,3,2};
    print_vec(Solution().longestObstacleCourseAtEachPosition(nums1));
    // 1 2 3 3

    vector<int> nums2 = {2,2,1};
    print_vec(Solution().longestObstacleCourseAtEachPosition(nums2));
    // 1 2 1

    vector<int> nums3 = {3,1,5,6,4,2};
    print_vec(Solution().longestObstacleCourseAtEachPosition(nums3));
    // 1 2 1

    return 0;
}
