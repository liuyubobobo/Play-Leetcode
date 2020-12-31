/// Source : https://leetcode.com/problems/find-the-most-competitive-subsequence/
/// Author : liuyubobobo
/// Time   : 2020-11-28

#include <iostream>
#include <vector>

using namespace std;


/// Segment Tree
/// Time Complexity: O(nlogn + klogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> data, tree;

public:
    SegmentTree(const vector<int>& data): n(data.size()), data(data), tree(4 * n, 0){
        buildSegTree(0, 0, n - 1);
    }

    int query(int l, int r){
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

        int resl = tree[treeID * 2 + 1], resr = tree[treeID * 2 + 2];
        tree[treeID] = data[resl] <= data[resr] ? resl : resr;
        return;
    }

    int query(int treeID, int l, int r, int ql, int qr){

        if(ql == l && qr == r)
            return tree[treeID];

        int mid = (l + r) / 2;
        if(qr <= mid) return query(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query(treeID * 2 + 2, mid + 1, r, ql, qr);

        int resl = query(treeID * 2 + 1, l, mid, ql, mid);
        int resr = query(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return data[resl] <= data[resr] ? resl : resr;
    }
};

class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        SegmentTree segTree(nums);

        int n = nums.size();
        vector<int> res(k);
        int l = 0, r = n - k;
        for(int i = 0; i < k; i ++){
            int minindex = segTree.query(l, r);
            res[i] = nums[minindex];
            l = minindex + 1;
            r ++;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {3, 5, 2, 6};
    print_vec(Solution().mostCompetitive(nums1, 2));
    // 2 6

    vector<int> nums2 = {2,4,3,3,5,4,9,6};
    print_vec(Solution().mostCompetitive(nums2, 4));
    // 2 3 3 4

    return 0;
}