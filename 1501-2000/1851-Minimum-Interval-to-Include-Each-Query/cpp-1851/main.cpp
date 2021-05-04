/// Source : https://leetcode.com/problems/minimum-interval-to-include-each-query/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>
#include <vector>

using namespace std;


/// Segment Tree
/// Time Complexity: O(nlogn + maxnum*log(maxnum))
/// Space Complexity: O(maxnum)
class SegmentTree{

private:
    int n;
    vector<int> data, tree;

public:
    SegmentTree(const vector<int>& data): n(data.size()), data(data), tree(4 * n, 0){
        buildSegTree(0, 0, n - 1);
    }

    void query(int l, int r, int a, const vector<vector<int>>& indexes, vector<int>& res){
        query(0, 0, n - 1, l, r, a, indexes, res);
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
        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
        return;
    }

    void query(int treeID, int l, int r, int ql, int qr, int a,
               const vector<vector<int>>& indexes, vector<int>& res){

        if(tree[treeID] == 0) return;
        if(qr < l || r < ql) return;

        if(l == r){
            for(int index: indexes[l])
                if(res[index] == -1) res[index] = a;
            tree[treeID] = 0;
            return;
        }

        int mid = (l + r) / 2;
        if(qr <= mid) query(treeID * 2 + 1, l, mid, ql, qr, a, indexes, res);
        else if(ql > mid) query(treeID * 2 + 2, mid + 1, r, ql, qr, a, indexes, res);
        else{
            query(treeID * 2 + 1, l, mid, ql, mid, a, indexes, res);
            query(treeID * 2 + 2, mid + 1, r, mid + 1, qr, a, indexes, res);
        }

        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
        return;
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        int maxv = *max_element(queries.begin(), queries.end());
        vector<int> data(maxv + 1, 0);
        vector<vector<int>> indexes(maxv + 1);

        for(int i = 0; i < queries.size(); i ++)
            data[queries[i]] = 1, indexes[queries[i]].push_back(i);

        SegmentTree tree(data);

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& v1, const vector<int>& v2){
                 return v1[1] - v1[0] < v2[1] - v2[0];
             });

        vector<int> res(queries.size(), -1);
        for(const vector<int>& interval: intervals){
            tree.query(interval[0], interval[1], interval[1] - interval[0] + 1, indexes, res);
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> intervals1 = {{1, 4}, {2, 4}, {3, 6}, {4, 4}};
    vector<int> queries1 = {2, 3, 4, 5};
    print_vec(Solution().minInterval(intervals1, queries1));
    // 3 3 1 4

    vector<vector<int>> intervals2 = {{2, 3}, {2, 5}, {1, 8}, {20, 25}};
    vector<int> queries2 = {2, 19, 5, 22};
    print_vec(Solution().minInterval(intervals2, queries2));
    // 2,-1,4,6

    vector<vector<int>> intervals3 = {{9, 9}, {9, 10}};
    vector<int> queries3 = {9};
    print_vec(Solution().minInterval(intervals3, queries3));
    // 1

    vector<vector<int>> intervals4 = {{5, 10}, {7, 7}};
    vector<int> queries4 = {6, 6};
    print_vec(Solution().minInterval(intervals4, queries4));
    // 6 6

    return 0;
}
