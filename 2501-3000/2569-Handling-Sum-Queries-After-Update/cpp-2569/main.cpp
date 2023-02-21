/// Source : https://leetcode.com/problems/handling-sum-queries-after-update/description/
/// Author : liuyubobobo
/// Time   : 2023-02-20

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Segment Tree
/// Time Complexity: O(nlogn + qlogn)
/// Space Complexity: O(n)
template<typename T>
class SegmentTree{

private:
    int n;
    vector<T> tree, lazy;
    T (*combine)(T a, T b);

public:
    SegmentTree(const vector<T>& data, T (*combine)(T a, T b)):
            n(data.size()), tree(4 * n, 0), lazy(4 * n, 0){
        this->combine = combine;
        buildSegTree(0, 0, n - 1, data);
    }

    SegmentTree(int n, T (*combine)(T a, T b)): n(n), tree(4 * n, 0), lazy(4 * n, 0){
        this->combine = combine;
    }

    void flip(int uL, int uR){
        assert(0 <= uL && uL < n);
        assert(0 <= uR && uR < n);
        assert(uL <= uR);
        flip(0, 0, n-1, uL, uR);
    }

    T query(int qL, int qR){
        assert(0 <= qL && qL < n);
        assert(0 <= qR && qR < n);
        assert(qL <= qR);
        return query(0, 0, n - 1, qL, qR);
    }

private:
    void buildSegTree(int treeID, int l, int r, const vector<T>& data){

        if(l == r){
            tree[treeID] = data[l];
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(treeID * 2 + 1, l, mid, data);
        buildSegTree(treeID * 2 + 2, mid + 1, r, data);
        tree[treeID] = combine(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
        return;
    }

    void flip(int treeID, int treeL, int treeR, int uL, int uR){

        if(uL > treeR || uR < treeL) return;

        if(uL <= treeL && treeR <= uR){

            int len = treeR - treeL + 1;
            tree[treeID] = len - tree[treeID];
            lazy[treeID] ++;

            return;
        }

        if(lazy[treeID])
            push(treeID, treeL, treeR);

        int mid = (treeL + treeR) / 2;
        flip(2 * treeID + 1, treeL, mid, uL, uR);
        flip(2 * treeID + 2, mid + 1, treeR, uL, uR);
        tree[treeID] = combine(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
        return;
    }

    T query(int treeID, int treeL, int treeR, int qL, int qR){

        if(qL <= treeL && treeR <= qR)
            return tree[treeID];

        if(lazy[treeID])
            push(treeID, treeL, treeR);

        int mid = (treeL + treeR) / 2;
        if(qR <= mid) return query(2 * treeID + 1, treeL, mid, qL, qR);
        if(qL >= mid + 1) return query(2 * treeID + 2, mid + 1, treeR, qL, qR);

        T resl = query(2 * treeID + 1, treeL, mid, qL, qR);
        T resr = query(2 * treeID + 2, mid + 1, treeR, qL, qR);
        T res = combine(resl, resr);
        return res;
    }

private:
    void push(int treeID, int treeL, int treeR){

        if(treeL == treeR) return;

        T v = lazy[treeID];

        int mid = (treeL + treeR) / 2;
        int tn = treeR - treeL + 1, tnl = mid - treeL + 1, tnr = tn - tnl;

        if(v & 1) {
            tree[treeID * 2 + 1] = tnl - tree[treeID * 2 + 1];
            tree[treeID * 2 + 2] = tnr - tree[treeID * 2 + 2];
        }

        lazy[treeID * 2 + 1] += v;
        lazy[treeID * 2 + 2] += v;

        lazy[treeID] = 0;
    }
};

class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {

        int n = nums1.size();

        SegmentTree<int> seg_tree(nums1, [](int a, int b){return a + b;});

        long long sum = 0;
        for(int e: nums2) sum += e;

        vector<long long> res;
        for(const vector<int>& query: queries){
//            for(int i = 0; i < n; i ++) cout << seg_tree.query(i, i) << " "; cout << '\n';
            int type = query[0];
            if(type == 1){
                int l = query[1], r = query[2];
                seg_tree.flip(l, r);
            }
            else if(type == 2){
                long long p = query[1];
                sum += p * seg_tree.query(0, n - 1);
            }
            else res.push_back(sum);
        }
        return res;
    }
};


void print_vec(const vector<long long>& res){
    for(long long e: res) cout << e << " "; cout << '\n';
}

int main() {

    vector<int> nums1_1 = {1, 0, 1}, nums1_2 = {0, 0, 0};
    vector<vector<int>>queries1 = {{1, 1, 1}, {2, 1, 0}, {3, 0, 0}};
    print_vec(Solution().handleQuery(nums1_1, nums1_2, queries1));
    // 3

    vector<int> nums2_1 = {0, 1, 0, 0, 0, 0}, nums2_2 = {14, 4, 13, 13, 47, 18};
    vector<vector<int>>queries2 = {{3,0,0},{1,4,4},{1,1,4},{1,3,4},{3,0,0},{2,5,0},{1,1,3},{2,16,0},{2,10,0},{3,0,0},{3,0,0},{2,6,0}};
    print_vec(Solution().handleQuery(nums2_1, nums2_2, queries2));
    // 109,109,197,197

    return 0;
}
