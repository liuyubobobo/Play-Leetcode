/// Source : https://leetcode.com/problems/maximum-subarray-sum-after-one-operation/
/// Author : liuyubobobo
/// Time   : 2021-02-05

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class MinSegmentTree{

private:
    int n;
    vector<int> data, tree;

public:
    MinSegmentTree(const vector<int>& data): n(data.size()), data(data), tree(4 * n, 0){
        buildSegTree(0, 0, n - 1);
    }

    int query(int l, int r){
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
        tree[treeID] = min(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
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
        return min(resl, resr);
    }
};

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {

        int n = nums.size();
        vector<int> presum(n + 1, 0), sufsum(n + 1, 0);

        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + nums[i];
        for(int i = n - 1; i >= 0; i --)
            sufsum[i] = sufsum[i + 1] + nums[i];

        MinSegmentTree pretree(presum), suftree(sufsum);
        int res = INT_MIN;
        for(int i = 0; i < n; i ++){
            int tres = nums[i] * nums[i];
            tres += presum[i] - pretree.query(0, i);
            tres += sufsum[i + 1] - suftree.query(i + 1, n);
            res = max(res, tres);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, -1, -4, -3};
    cout << Solution().maxSumAfterOperation(nums1) << endl;
    // 17

    vector<int> nums2 = {1,-1,1,1,-1,-1,1};
    cout << Solution().maxSumAfterOperation(nums2) << endl;
    // 4

    return 0;
}
