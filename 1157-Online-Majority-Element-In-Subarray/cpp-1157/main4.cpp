/// Source : https://leetcode.com/problems/online-majority-element-in-subarray/
/// Author : liuyubobobo
/// Time   : 2019-08-11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/// Segment Tree
/// if we split the interval [l, r] into several sub-intervals
/// the more than half majority should also be a more than half majority int at least one sub-interval
///
/// Time Complexity: init: O(nlogn)
///                  query: O(logn * logn)
/// Space Complexity: O(n)
class MajorityChecker {

private:
    vector<int> arr, tree;
    unordered_map<int, vector<int>> indexes;

public:
    MajorityChecker(vector<int>& arr): arr(arr.begin(), arr.end()), tree(4 * arr.size(), -1) {

        for(int i = 0; i < arr.size(); i ++)
            indexes[arr[i]].push_back(i);
        build_tree(0, 0, arr.size() - 1);
    }

    int query(int left, int right, int threshold) {


        int e = query(0, 0, arr.size() - 1, left, right);
        if(e != -1 && get_freq(e, left, right) >= threshold) return e;
        return -1;
    }

private:
    int query(int treeid, int l, int r, int ql, int qr){

        if(ql == l && qr == r) return tree[treeid];

        int mid = (l + r) / 2;
        if(qr <= mid) return query(treeid * 2 + 1, l, mid, ql, qr);
        if(ql >= mid + 1) return query(treeid * 2 + 2, mid + 1, r, ql, qr);

        int a = query(treeid * 2 + 1, l, mid, ql, mid);
        int b = query(treeid * 2 + 2, mid + 1, r, mid + 1, qr);
        if(get_freq(a, ql, qr) * 2 >= qr - ql + 1) return a;
        else if(get_freq(b, ql, qr) * 2 >= qr - ql + 1) return b;
        return -1;
    }

    void build_tree(int treeid, int l, int r){

        if(l == r){
            tree[treeid] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build_tree(treeid * 2 + 1, l, mid);
        build_tree(treeid * 2 + 2, mid + 1, r);
        if(tree[treeid * 2 + 1] && get_freq(tree[treeid * 2 + 1], l, r) * 2 >= r - l + 1)
            tree[treeid] = tree[treeid * 2 + 1];
        else if(tree[treeid * 2 + 2] && get_freq(tree[treeid * 2 + 2], l, r) * 2 >= r - l + 1)
            tree[treeid] = tree[treeid * 2 + 2];
    }

    int get_freq(int e, int left, int right){
        const vector<int>& v = indexes[e];
        vector<int>:: const_iterator iter1 = lower_bound(v.begin(), v.end(), left);
        vector<int>:: const_iterator iter2 = upper_bound(v.begin(), v.end(), right);
        return iter2 - iter1;
    }
};


int main() {

    vector<int> arr = {1,1,2,2,1,1};
    MajorityChecker checker(arr);
    cout << checker.query(0, 5, 4) << endl; // 1
    cout << checker.query(0, 3, 3) << endl; // -1
    cout << checker.query(2, 3, 2) << endl; // 2

    return 0;
}