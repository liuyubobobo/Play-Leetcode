/// Source : https://leetcode.com/problems/constrained-subset-sum/
/// Author : liuyubobobo
/// Time   : 2020-04-27

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// DP + Segment Tree to Optimize
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> tree;

public:
    SegmentTree(int n): n(n), tree(4 * n){}

    int query(int qL, int qR){
        return query(0, 0, n-1, qL, qR);
    }

    void update(int index, int value){
        update(0, 0, n - 1, index, value);
    }

private:
    void update(int treeID, int l, int r, int index, int value){

        if(l == r){
            assert(l == index);
            tree[treeID] = value;
            return;
        }

        int mid = (l + r) / 2;
        if(index <= mid) update(treeID * 2 + 1, l, mid, index, value);
        else update(treeID * 2 + 2, mid + 1, r, index, value);

        tree[treeID] = max(tree[treeID * 2 + 1], tree[treeID * 2 + 2]);
        return;
    }

    int query(int treeID, int treeL, int treeR, int qL, int qR){

        if(treeL > qR || treeR < qL) return 0;

        if(qL <= treeL && qR >= treeR)
            return tree[treeID];

        int mid = (treeL + treeR) / 2;
        int leftRes = query(2 * treeID + 1, treeL, mid, qL, qR);
        int rightRes = query(2 * treeID + 2, mid + 1, treeR, qL, qR);
        return max(leftRes, rightRes);
    }
};

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

        int max_value = *max_element(nums.begin(), nums.end());
        if(max_value <= 0) return max_value;

        int n = nums.size(), res = 0;
        vector<int> dp(n);
        SegmentTree tree(n);
        for(int i = 0; i < n; i ++){
            dp[i] = nums[i];
            if(i) dp[i] = max(dp[i], nums[i] + tree.query(max(0, i - k), i - 1));
            res = max(res, dp[i]);
            tree.update(i, dp[i]);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {10,2,-10,5,20};
    cout << Solution().constrainedSubsetSum(nums1, 2) << endl;
    // 37

    vector<int> nums2 = {-1, -2, -3};
    cout << Solution().constrainedSubsetSum(nums2, 1) << endl;
    // -1

    vector<int> nums3 = {10,-2,-10,-5,20};
    cout << Solution().constrainedSubsetSum(nums3, 2) << endl;
    // 23

    vector<int> nums4 = {-8269,3217,-4023,-4138,-683,6455,-3621,9242,4015,-3790};
    cout << Solution().constrainedSubsetSum(nums4, 1) << endl;
    // 16091

    return 0;
}
