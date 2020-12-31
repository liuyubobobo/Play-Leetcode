/// Source : https://leetcode.com/problems/minimum-moves-to-make-array-complementary/
/// Author : liuyubobobo
/// Time   : 2020-11-30

#include <iostream>
#include <vector>

using namespace std;


/// Using Segment Tree
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<long long> tree, lazy;

public:
    SegmentTree(int n): n(n), tree(4 * n, 0ll), lazy(4 * n, 0ll){}

    void add(int index, int val){
        update(0, 0, n - 1, index, index, val);
    }

    void add(int uL, int uR, int val){
        update(0, 0, n - 1, uL, uR, val);
    }

    int query(int index){
        return query(0, 0, n - 1, index, index);
    }

private:
    void update(int treeID, int treeL, int treeR, int uL, int uR, int val){

        if(lazy[treeID]){
            tree[treeID] += lazy[treeID] * (treeR - treeL + 1);
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0;
        }

        if (treeL > uR || treeR < uL) return;

        if(uL <= treeL && uR >= treeR){
            tree[treeID] += (long long)val * (treeR - treeL + 1);
            if(treeL != treeR){
                lazy[2 * treeID + 1] += val;
                lazy[2 * treeID + 2] += val;
            }
            return;
        }

        int mid = (treeL + treeR) / 2;
        update(2 * treeID + 1, treeL, mid, uL, uR, val);
        update(2 * treeID + 2, mid + 1, treeR, uL, uR, val);
        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
        return;
    }

    int query(int treeID, int treeL, int treeR, int qL, int qR){

        if(lazy[treeID]){
            tree[treeID] += lazy[treeID] * (treeR - treeL + 1);
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0;
        }

        if(treeL > qR || treeR < qL) return 0;

        if(qL <= treeL && qR >= treeR)
            return tree[treeID];

        int mid = (treeL + treeR) / 2;
        int leftRes = query(2 * treeID + 1, treeL, mid, qL, qR);
        int rightRes = query(2 * treeID + 2, mid + 1, treeR, qL, qR);
        return leftRes + rightRes;
    }
};

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {

        SegmentTree segTree(limit * 2 + 1);

        int n = nums.size();
        for(int i = 0; i < n / 2; i ++){
            int x = nums[i], y = nums[n - 1 - i];
            segTree.add(2, 2 * limit, 2);
            segTree.add(1 + min(x, y), limit + max(x, y), -1);
            segTree.add(x + y, -1);
        }

        int res = n;
        for(int i = 2; i <= 2 * limit; i ++){
//            cout << segTree.query(i);
            res = min(res, segTree.query(i));
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 4, 3};
    cout << Solution().minMoves(nums1, 4) << endl;
    // 1

    vector<int> nums2 = {1, 2, 2, 1};
    cout << Solution().minMoves(nums2, 2) << endl;
    // 2

    vector<int> nums3 = {1, 2, 1, 2};
    cout << Solution().minMoves(nums3, 2) << endl;
    // 0

    vector<int> nums4 = {3,1,2,1,2,3,3,1,2,3,2,2,1,2,3,3,3,1,1,2,3,2,1,1,2,3,3,3,1,3,3,1,1,2,2,2,2,2,1,3,1,2,2,2};
    cout << Solution().minMoves(nums4, 3) << endl;
    // 13

    return 0;
}