/// Source : https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
/// Author : liuyubobobo
/// Time   : 2020-05-02

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


/// Sliding Window + Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> data, maxtree, mintree;

public:
    SegmentTree(const vector<int>& initData): data(initData.begin(),
            initData.end()), n(initData.size()), maxtree(4 * n, 0), mintree(4 * n, 0){
        buildSegTree(0, 0, n - 1);
    }

    int query_min(int l, int r){
        return query_min(0, 0, n - 1, l, r);
    }

    int query_max(int l, int r){
        return query_max(0, 0, n - 1, l, r);
    }

private:
    void buildSegTree(int treeID, int l, int r){

        if(l == r){
            mintree[treeID] = maxtree[treeID] = data[l];
            return;
        }

        int mid = (l + r) / 2;
        buildSegTree(treeID * 2 + 1, l, mid);
        buildSegTree(treeID * 2 + 2, mid + 1, r);
        mintree[treeID] = min(mintree[treeID * 2 + 1], mintree[treeID * 2 + 2]);
        maxtree[treeID] = max(maxtree[treeID * 2 + 1], maxtree[treeID * 2 + 2]);
        return;
    }

    int query_min(int treeID, int l, int r, int ql, int qr){

        if(ql == l && qr == r)
            return mintree[treeID];

        int mid = (l + r) / 2;
        if(qr <= mid) return query_min(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query_min(treeID * 2 + 2, mid + 1, r, ql, qr);

        int resl = query_min(treeID * 2 + 1, l, mid, ql, mid);
        int resr = query_min(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return min(resl, resr);
    }

    int query_max(int treeID, int l, int r, int ql, int qr){

        if(ql == l && qr == r)
            return maxtree[treeID];

        int mid = (l + r) / 2;
        if(qr <= mid) return query_max(treeID * 2 + 1, l, mid, ql, qr);
        else if(ql > mid) return query_max(treeID * 2 + 2, mid + 1, r, ql, qr);

        int resl = query_max(treeID * 2 + 1, l, mid, ql, mid);
        int resr = query_max(treeID * 2 + 2, mid + 1, r, mid + 1, qr);
        return max(resl, resr);
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        SegmentTree tree(nums);
        int res = 1;
        for(int l = 0, i = 1; i < nums.size(); i ++){

            if(tree.query_max(l, i ) - tree.query_min(l, i) <= limit)
                res = max(res, i - l + 1);
            else{
                while(tree.query_max(l, i) - tree.query_min(l, i) > limit)
                    l ++;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {8, 2, 4, 7};
    cout << Solution().longestSubarray(nums1, 4) << endl;
    // 2

    vector<int> nums2 = {10,1,2,4,7,2};
    cout << Solution().longestSubarray(nums2, 5) << endl;
    // 4

    vector<int> nums3 = {4,2,2,2,4,4,2,2};
    cout << Solution().longestSubarray(nums3, 0) << endl;
    // 3

    vector<int> nums4 = {4,10,2,6,1};
    cout << Solution().longestSubarray(nums4, 10) << endl;
    // 5

    return 0;
}
