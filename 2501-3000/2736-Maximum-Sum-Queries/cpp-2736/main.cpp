/// Source : https://leetcode.com/problems/maximum-sum-queries/description/
/// Author : liuyubobobo
/// Time   : 2023-06-19

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


/// Segment Tree + Offline Queries
/// Time Complexity: O(nlogn + qlogn)
/// Space Complexity: O(n)
template<typename T>
class SegmentTree{

private:
    int n;
    vector<T> data, tree;
    T (*combine)(T a, T b);

public:

    SegmentTree(int n, T (*combine)(T a, T b)): n(n), data(n, -1), tree(4 * n, -1){
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
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {

        vector<pair<int, int>> v;
        for(int i = 0; i < nums1.size(); i ++) v.push_back({nums1[i], nums2[i]});
        sort(v.begin(), v.end(), greater<>());

        for(int i = 0; i < queries.size(); i ++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), greater<>());

        map<int, int> value2index;
        for(const pair<int, int>& p: v) value2index[p.second] = 0;
        for(const vector<int>& p: queries) value2index[p[1]] = 0;

        int sz = 0;
        for(auto iter = value2index.begin(); iter != value2index.end(); iter ++)
            iter->second = sz ++;

        vector<int> res(queries.size());
        SegmentTree<int> segTree(sz, [](int a, int b){return max(a, b);});
        for(int i = 0, j = 0; i < queries.size(); i ++){
            while(j < v.size() && v[j].first >= queries[i][0]){
                int index = value2index[v[j].second];
                segTree.update(index, max(segTree.query(index), v[j].first + v[j].second));
                j ++;
            }

            int index = value2index[queries[i][1]];
            int tres = segTree.query(index, sz - 1);
            res[queries[i][2]] = tres;
        }
        return res;
    }
};


int main() {

    return 0;
}
