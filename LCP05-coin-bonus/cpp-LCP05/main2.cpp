/// Source : https://leetcode-cn.com/problems/coin-bonus/
/// Author : liuyubobobo
/// Time   : 2020-04-22

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// DFS Order + Segment Tree
/// Time Complexity: O(n + nlogn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<int> tree, lazy;
    int MOD = 1e9 + 7;

public:
    SegmentTree(int n): n(n), tree(4 * n, 0), lazy(4 * n, 0){}

    void add(int index, int val){
        update(0, 0, n - 1, index, index, val);
    }

    void add(int uL, int uR, int val){
        update(0, 0, n-1, uL, uR, val);
    }

    int query(int index){
        return query(0, 0, n-1, index, index);
    }

    int query(int qL, int qR){
        return query(0, 0, n-1, qL, qR);
    }

private:
    void update(int treeID, int treeL, int treeR, int uL, int uR, int val){

        if(lazy[treeID]){
            tree[treeID] = (tree[treeID] + (long long)(treeR - treeL + 1) * lazy[treeID]) % MOD;
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0;
        }

        if (treeL > uR || treeR < uL) return;

        if(uL <= treeL && uR >= treeR){
            tree[treeID] = (tree[treeID] + (long long)(treeR - treeL + 1) * val) % MOD;
            if(treeL != treeR){
                lazy[2 * treeID + 1] += val;
                lazy[2 * treeID + 2] += val;
            }
            return;
        }

        int mid = (treeL + treeR) / 2;
        update(2 * treeID + 1, treeL, mid, uL, uR, val);
        update(2 * treeID + 2, mid + 1, treeR, uL, uR, val);
        tree[treeID] = (tree[treeID * 2 + 1] + tree[treeID * 2 + 2]) % MOD;
        return;
    }

    int query(int treeID, int treeL, int treeR, int qL, int qR){

        if(lazy[treeID]){
            tree[treeID] = (tree[treeID] + (long long)(treeR - treeL + 1) * lazy[treeID]) % MOD;
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
        return (leftRes + rightRes) % MOD;
    }
};

class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {

        vector<set<int>> g(n);
        for(vector<int>& v: leadership)
            g[v[0] - 1].insert(v[1] - 1);
//        for(int i = 0; i < n; i ++){
//            cout << i << " : "; for(int x: g[i]) cout << x << " "; cout << endl;
//        }

        vector<pair<int, int>> vToRange(n);
        int index = 0;
        dfs(g, 0, index, vToRange);
//        for(int i = 0; i < vToRange.size(); i ++)
//            cout << i << " : [" << vToRange[i].first << " , " << vToRange[i].second << "]" << endl;

        SegmentTree tree(n);
        vector<int> res;
        for(const vector<int>&op: operations) {
            int x = op[1] - 1;
            switch(op[0]) {
                case 1:
                    tree.add(vToRange[x].first, op[2]);
                    break;
                case 2:
                    tree.add(vToRange[x].first, vToRange[x].second, op[2]);
                    break;
                case 3:
                    res.push_back(tree.query(vToRange[x].first, vToRange[x].second));
                    break;
            }
        }
        return res;
    }

private:
    void dfs(const vector<set<int>>& g, int v, int& index, vector<pair<int, int>>& vToRange){

        vToRange[v].first = index ++;
        for(int next: g[v])
            dfs(g, next, index, vToRange);
        vToRange[v].second = index - 1;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> leadership = {{1, 2}, {1, 6}, {2, 3}, {2, 5}, {1, 4}};
    vector<vector<int>> operations = {{1, 1, 500}, {2, 2, 50}, {3, 1}, {2, 6, 15}, {3, 1}};
    print_vec(Solution().bonus(6, leadership, operations));

    return 0;
}
