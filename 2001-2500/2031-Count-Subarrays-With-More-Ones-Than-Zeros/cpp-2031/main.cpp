/// Source : https://leetcode.com/problems/count-subarrays-with-more-ones-than-zeros/
/// Author : liuyubobobo
/// Time   : 2021-10-10

#include <iostream>
#include <vector>

using namespace std;


/// More one than zero in [l...r] means 2(presum[r] - presum[l - 1]) > (r - l + 1)
/// So: 2*presum[r] - r > 2*presum[l - 1] - (l - 1)
/// for every r, fond the number of l satisfy the above condition
/// Using segment tree
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
template<typename T>
class SegmentTree{

private:
    int n;
    vector<T> data, tree;
    T (*combine)(T a, T b);

public:
    SegmentTree(const vector<T>& data, T (*combine)(T a, T b)): n(data.size()), data(data), tree(4 * n, 0){
        this->combine = combine;
        buildSegTree(0, 0, n - 1);
    }

    SegmentTree(int n, T (*combine)(T a, T b)): n(n), data(n, 0), tree(4 * n, 0){
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
        if(l >r) return 0;
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
    int subarraysWithMoreZerosThanOnes(vector<int>& nums) {

        int n = nums.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + nums[i];

        for(int i = 0; i <= n; i ++)
            presum[i] = 2 * presum[i] - i;

//        for(int e: presum) cout << e << ' '; cout << '\n';

        vector<pair<int,int>> data(n + 1);
        for(int i = 0; i <= n; i ++)
            data[i] = {presum[i], i};
        sort(data.begin(), data.end(),
             [](const pair<int, int>& p1, const pair<int, int>& p2){
            if(p1.first != p2.first) return p1.first > p2.first;
            return p1.second < p2.second;
        });

        SegmentTree<int> seg_tree(vector<int>(n + 1, 1), [](int a, int b){return a + b;});

        int res = 0, MOD = 1e9 + 7;
        for(const pair<int, int>& p: data){
            int index = p.second;
            res += seg_tree.query(0, p.second - 1);
            res %= MOD;
            seg_tree.update(index, 0);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {0, 1, 1, 0, 1};
    cout << Solution().subarraysWithMoreZerosThanOnes(nums1) << endl;
    // 9

    vector<int> nums2 = {0};
    cout << Solution().subarraysWithMoreZerosThanOnes(nums2) << endl;
    // 0

    vector<int> nums3 = {1};
    cout << Solution().subarraysWithMoreZerosThanOnes(nums3) << endl;
    // 1

    return 0;
}
