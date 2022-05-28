/// Source : https://leetcode.com/problems/booking-concert-tickets-in-groups/
/// Author : liuyubobobo
/// Time   : 2022-05-28

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Segment Tree + Binary Search
/// Time Complexity: init: O(nlogn)
///                  gather: O(logn * logn)
///                  scatter: O(logn) in average
/// Space Complexity: O(n)
template<typename T>
class SegmentTree{

private:
    int n;
    vector<T> data, max_tree, sum_tree;

public:
    SegmentTree(const vector<T>& data): n(data.size()), data(data), max_tree(4 * n, 0), sum_tree(4 * n, 0){
        buildSegTree(0, 0, n - 1);
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

    T query_max(int l, int r){
        if(l > r || l < 0 || l >= n || r < 0 || r >= n) return 0;
        return query_max(0, 0, n - 1, l, r);
    }

    T query_sum(int l, int r){
        if(l > r || l < 0 || l >= n || r < 0 || r >= n) return 0;
        return query_sum(0, 0, n - 1, l, r);
    }

private:
    void buildSegTree(int treeID, int l, int r){

        if(l == r){
            max_tree[treeID] = sum_tree[treeID] = data[l];
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(treeID * 2 + 1, l, mid);
        buildSegTree(treeID * 2 + 2, mid + 1, r);
        max_tree[treeID] = max(max_tree[treeID * 2 + 1], max_tree[treeID * 2 + 2]);
        sum_tree[treeID] = sum_tree[treeID * 2 + 1] + sum_tree[treeID * 2 + 2];
        return;
    }

    void update(int treeID, int l, int r, int index, T value){

        if(l == r){
            assert(l == index);
            max_tree[treeID] = sum_tree[treeID] = value;
            return;
        }

        int mid = (l + r) / 2;
        if(index <= mid) update(treeID * 2 + 1, l, mid, index, value);
        else update(treeID * 2 + 2, mid + 1, r, index, value);

        max_tree[treeID] = max(max_tree[treeID * 2 + 1], max_tree[treeID * 2 + 2]);
        sum_tree[treeID] = sum_tree[treeID * 2 + 1] + sum_tree[treeID * 2 + 2];
        return;
    }

    T query_max(int treeID, int l, int r, int ql, int qr){

        if(ql == l && qr == r)
            return max_tree[treeID];

        int mid = (l + r) / 2;
        if(qr <= mid) return query_max(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query_max(treeID * 2 + 2, mid + 1, r, ql, qr);

        T resl = query_max(treeID * 2 + 1, l, mid, ql, mid);
        T resr = query_max(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return max(resl, resr);
    }

    T query_sum(int treeID, int l, int r, int ql, int qr){

        if(ql == l && qr == r)
            return sum_tree[treeID];

        int mid = (l + r) / 2;
        if(qr <= mid) return query_sum(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query_sum(treeID * 2 + 2, mid + 1, r, ql, qr);

        T resl = query_sum(treeID * 2 + 1, l, mid, ql, mid);
        T resr = query_sum(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return resl + resr;
    }
};

class BookMyShow {

private:
    int n, m, first_non_zero_index;
    SegmentTree<long long> *seg_tree;

public:
    BookMyShow(int n, int m) : n(n), m(m), first_non_zero_index(0) {
        seg_tree = new SegmentTree<long long>(vector<long long>(n, m));
    }

    vector<int> gather(int k, int maxRow) {

        int l = first_non_zero_index, r = maxRow + 1;
        if(l > r) return {};

        while(l < r){
            int mid = (l + r) / 2;
            if(seg_tree->query_max(l, mid) >= k) r = mid;
            else l = mid + 1;
        }

        if(l == maxRow + 1) return {};

        int left = seg_tree->query(l);
        seg_tree->update(l, left - k);

        while(first_non_zero_index < n && seg_tree->query(first_non_zero_index) == 0)
            first_non_zero_index ++;
        return {l, m - left};
    }

    bool scatter(int k, int maxRow) {

        if(seg_tree->query_sum(first_non_zero_index, maxRow) < k) return false;

        for(int i = first_non_zero_index; i <= maxRow && k; i ++){
            int v = seg_tree->query(i);
            int t = min(k, v);

            k -= t;
            seg_tree->update(i, v - t);
            if(v - t == 0) first_non_zero_index ++;
        }
        return true;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    BookMyShow obj(19, 9);
    print_vec(obj.gather(38, 8)); // empty
    print_vec(obj.gather(27, 3)); // empty
    cout << obj.scatter(36, 14) << '\n'; // 1
    cout << obj.scatter(46, 2) << '\n'; // 0
    print_vec(obj.gather(12, 5)); // empty
    cout << obj.scatter(12, 12) << '\n'; // 1
    cout << obj.scatter(43, 12) << '\n'; // 1
    print_vec(obj.gather(30, 5)); // empty

    return 0;
}
