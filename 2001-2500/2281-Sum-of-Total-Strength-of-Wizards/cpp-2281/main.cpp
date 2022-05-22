/// Source : https://leetcode.com/problems/sum-of-total-strength-of-wizards/
/// Author : liuyubobobo
/// Time   : 2022-05-21

#include <iostream>
#include <vector>

using namespace std;


/// Counting, Segment Tree + Presum
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
template<typename T>
class SegmentTree{

private:
    int n;
    vector<T> data, tree;

public:
    SegmentTree(const vector<T>& data): n(data.size()), data(data), tree(4 * n, 0){
        buildSegTree(0, 0, n - 1);
    }

    T query(int l, int r){
//        assert(l <= r);
//        assert(0 <= l && l < n);
//        assert(0 <= r && r < n);
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
        tree[treeID] = data[tree[treeID * 2 + 1]] < data[tree[treeID * 2 + 2]] ? tree[treeID * 2 + 1] : tree[treeID * 2 + 2];
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
        return data[resl] < data[resr] ? resl : resr;
    }
};

class Solution {

private:
    const long long MOD = 1e9 + 7;
    vector<long long> presum, presum_sum, sufsum_sum;
    SegmentTree<int> *seg_tree;

public:
    int totalStrength(vector<int>& strength) {

        int n = strength.size();

        presum.assign(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + strength[i];

        presum_sum.assign(n + 2, 0);
        for(int i = 0; i < n; i ++)
            presum_sum[i + 1] = ((long long)strength[i] * (i + 1) % MOD + presum_sum[i] ) % MOD;

        sufsum_sum.assign(n + 2, 0);
        for(int i = n - 1; i >= 0; i --)
            sufsum_sum[i + 1] = ((long long)strength[i] * (n - i) % MOD + sufsum_sum[i + 2]) % MOD;

        seg_tree = new SegmentTree<int>(strength);
        return dfs(n, strength, 0, n - 1);
    }

private:
    long long dfs(int n, const vector<int>& v, int l, int r){

        if(l > r) return 0;
        if(l == r) return (long long)v[l] * v[l] % MOD;

        int min_index = seg_tree->query(l, r);
        long long sum = get_total_sum(n, l, r, min_index);

        long long res = sum * v[min_index] % MOD;
        res = (res + dfs(n, v, l, min_index - 1)) % MOD;
        res = (res + dfs(n, v, min_index + 1, r)) % MOD;
        return res;
    }

    long long get_total_sum(int n, int l, int r, int k){

        long long total_left = (presum_sum[k + 1] - presum_sum[l] + MOD) % MOD;
        total_left -= (presum[k + 1] - presum[l] + MOD) % MOD * l % MOD;
        total_left = (total_left + MOD) % MOD;

        if(k < r){
            long long additional_right = (sufsum_sum[k + 2] - sufsum_sum[r + 2] + MOD) % MOD;
            additional_right -= (presum[r + 1] - presum[k + 1] + MOD) % MOD * (n - r - 1) % MOD;
            additional_right = (additional_right + MOD) % MOD;

            long long left_cnt = k - l + 1;
            long long right_cnt = r - k;

            additional_right = additional_right * left_cnt % MOD;

            total_left = total_left * (right_cnt + 1) % MOD;
            total_left += additional_right;
            total_left %= MOD;
        }

        return total_left;
    }
};


int main() {

    vector<int> strength1 = {1, 3, 1, 2};
    cout << Solution().totalStrength(strength1) << '\n';
    // 44

    vector<int> strength2 = {5, 4, 6};
    cout << Solution().totalStrength(strength2) << '\n';
    // 213

    return 0;
}
