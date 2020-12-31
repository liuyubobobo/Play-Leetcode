/// Source : https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/
/// Author : liuyubobobo
/// Time   : 2020-09-19

#include <iostream>
#include <vector>

using namespace std;


/// Segment Tree with lazy propagation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> tree, lazy;

public:
    SegmentTree(int n): n(n), tree(4 * n, 0), lazy(4 * n, 0){}

    void add(int uL, int uR){
        update(0, 0, n-1, uL, uR);
    }

    int query(int index){
        return query(0, 0, n-1, index);
    }

private:
    void update(int treeID, int treeL, int treeR, int uL, int uR){

        if(lazy[treeID]){
            tree[treeID] += (treeR - treeL + 1) * lazy[treeID];
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0;
        }

        if (treeL > uR || treeR < uL) return;

        if(uL <= treeL && uR >= treeR){
            tree[treeID] += treeR - treeL + 1;
            if(treeL != treeR){
                lazy[2 * treeID + 1] ++;
                lazy[2 * treeID + 2] ++;
            }
            return;
        }

        int mid = (treeL + treeR) / 2;
        update(2 * treeID + 1, treeL, mid, uL, uR);
        update(2 * treeID + 2, mid + 1, treeR, uL, uR);
        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
        return;
    }

    int query(int treeID, int treeL, int treeR, int index){

        if(lazy[treeID]){
            tree[treeID] += (treeR - treeL + 1) * lazy[treeID];
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0;
        }

        if(treeL== treeR) return tree[treeID];

        int mid = (treeL + treeR) / 2;
        if(index <= mid) return query(2 * treeID + 1, treeL, mid, index);
        return query(2 * treeID + 2, mid + 1, treeR, index);
    }
};

class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {

        int n = nums.size();
        SegmentTree tree(n);
        for(const vector<int>& v: requests)
            tree.add(v[0], v[1]);

        vector<int> freq(n);
        for(int i = 0; i < n; i ++) freq[i] = tree.query(i);

        sort(freq.begin(), freq.end());
        sort(nums.begin(), nums.end());

        long long res = 0;
        for(int i = n - 1; i >= 0; i --)
            res = (res + (long long)nums[i] * freq[i]) % MOD;
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<vector<int>> request1 = {{1, 3}, {0, 1}};
    cout << Solution().maxSumRangeQuery(nums1, request1) << endl;
    // 19

    return 0;
}
