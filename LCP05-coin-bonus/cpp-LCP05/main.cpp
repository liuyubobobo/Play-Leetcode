#include <iostream>
#include <vector>
#include <set>

using namespace std;


class SegmentTree{

private:
    int n;
    vector<long long> tree, lazy;
    int MOD = 1e9 + 7;

public:
    SegmentTree(int n): n(n), tree(4 * n, 0ll), lazy(4 * n, 0ll){}

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
    void update(int treeID, int treeL, int treeR, int uL, int uR, long long val){

        if(lazy[treeID]){
            tree[treeID] += (long long)(treeR - treeL + 1) * lazy[treeID];
            tree[treeID] %= MOD;
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0ll;
        }

//        if (treeL > treeR || treeL > uR || treeR < uL)
//            return;

//        assert(treeL <= uL && uR <= treeR);
        if(uL == treeL && uR == treeR){
            tree[treeID] += (long long)(treeR - treeL + 1) * val;
            tree[treeID] %= MOD;
            if(treeL != treeR){
                lazy[2 * treeID + 1] += val;
                lazy[2 * treeID + 2] += val;
            }
            return;
        }

        int mid = (treeL + treeR) / 2;

        if(uR <= mid)
            update(2 * treeID + 1, treeL, mid, uL, uR, val);
        else if(uL >= mid + 1)
            update(2 * treeID + 2, mid + 1, treeR, uL, uR, val);
        else{
            update(2 * treeID + 1, treeL, mid, uL, mid, val);
            update(2 * treeID + 2, mid + 1, treeR, mid + 1, uR, val);
        }
        tree[treeID] = tree[treeID * 2 + 1] + tree[treeID * 2 + 2];
        tree[treeID] %= MOD;
        return;
    }

    long long query(int treeID, int treeL, int treeR, int qL, int qR){

        if(treeL > qR || treeR < qL) return 0ll;

        if(lazy[treeID]){
            tree[treeID] += (long long)(treeR - treeL + 1) * lazy[treeID];
            tree[treeID] %= MOD;
            if(treeL != treeR){
                lazy[2 * treeID + 1] += lazy[treeID];
                lazy[2 * treeID + 2] += lazy[treeID];
            }
            lazy[treeID] = 0ll;
        }

        if(qL == treeL && qR == treeR)
            return tree[treeID];

        int mid = (treeL + treeR) / 2;

        if(qR <= mid)
            return query(2 * treeID + 1, treeL, mid, qL, qR);
        else if(qL >= mid + 1)
            return query(2 * treeID + 2, mid + 1, treeR, qL, qR);

        int leftRes = query(2 * treeID + 1, treeL, mid, qL, mid);
        int rightRes = query(2 * treeID + 2, mid + 1, treeR, mid + 1, qR);

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
