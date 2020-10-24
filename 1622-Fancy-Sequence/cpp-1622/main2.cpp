/// Source : https://leetcode.com/problems/fancy-sequence/
/// Author : liuyubobobo
/// Time   : 2020-10-18

#include <iostream>
#include <vector>

using namespace std;


/// Segment tree
/// Time Complexity: all operations: O(logn)
/// Space Complexity: O(n)
class SegmentTree{

private:
    int n;
    vector<long long> tree, lazya, lazym;
    const long long MOD = 1e9 + 7;

public:
    SegmentTree(int n): n(n), tree(4 * n, 0ll), lazya(4 * n, 0ll), lazym(4 * n, 1ll){}

    void add(int index, int val){
        update(0, 0, n - 1, index, index, val, 1);
    }

    void update_add(int uL, int uR, int inc){
        update(0, 0, n-1, uL, uR, inc, 1);
    }

    void update_mul(int uL, int uR, int mul){
        update(0, 0, n-1, uL, uR, 0, mul);
    }

    int query(int index){
        return query(0, 0, n-1, index);
    }

private:
    void update(int treeID, int treeL, int treeR, int uL, int uR, int inc, int mul){

        if(lazya[treeID] != 0 || lazym[treeID] != 1){
            tree[treeID] = (tree[treeID] * lazym[treeID] + (treeR - treeL + 1)* lazya[treeID]) % MOD;
            if(treeL != treeR){
                lazym[2 * treeID + 1] = lazym[2 * treeID + 1] * lazym[treeID] % MOD;
                lazya[2 * treeID + 1] = lazya[2 * treeID + 1] * lazym[treeID] % MOD;
                lazya[2 * treeID + 1] = (lazya[2 * treeID + 1] + lazya[treeID]) % MOD;

                lazym[2 * treeID + 2] = lazym[2 * treeID + 2] * lazym[treeID] % MOD;
                lazya[2 * treeID + 2] = lazya[2 * treeID + 2] * lazym[treeID] % MOD;
                lazya[2 * treeID + 2] = (lazya[2 * treeID + 2] + lazya[treeID]) % MOD;
            }
            lazya[treeID] = 0;
            lazym[treeID] = 1;
        }

        if (treeL > uR || treeR < uL) return;

        if(uL <= treeL && uR >= treeR){
            tree[treeID] = (tree[treeID] + tree[treeID] * (mul - 1) + (treeR - treeL + 1) * inc) % MOD;
            if(treeL != treeR){
                lazym[2 * treeID + 1] = lazym[2 * treeID + 1] * mul % MOD;
                lazya[2 * treeID + 1] = lazya[2 * treeID + 1] * mul % MOD;
                lazya[2 * treeID + 1] = (lazya[2 * treeID + 1] + inc) % MOD;

                lazym[2 * treeID + 2] = lazym[2 * treeID + 2] * mul % MOD;
                lazya[2 * treeID + 2] = lazya[2 * treeID + 2] * mul % MOD;
                lazya[2 * treeID + 2] = (lazya[2 * treeID + 2] + inc) % MOD;
            }
            return;
        }

        int mid = (treeL + treeR) / 2;
        update(2 * treeID + 1, treeL, mid, uL, uR, inc, mul);
        update(2 * treeID + 2, mid + 1, treeR, uL, uR, inc, mul);
        tree[treeID] = (tree[treeID * 2 + 1] + tree[treeID * 2 + 2]) % MOD;
        return;
    }

    int query(int treeID, int treeL, int treeR, int index){

        if(lazya[treeID] != 0 || lazym[treeID] != 1){
            tree[treeID] = (tree[treeID] * lazym[treeID] + (treeR - treeL + 1)* lazya[treeID]) % MOD;
            if(treeL != treeR){
                lazym[2 * treeID + 1] = lazym[2 * treeID + 1] * lazym[treeID] % MOD;
                lazya[2 * treeID + 1] = lazya[2 * treeID + 1] * lazym[treeID] % MOD;
                lazya[2 * treeID + 1] = (lazya[2 * treeID + 1] + lazya[treeID]) % MOD;

                lazym[2 * treeID + 2] = lazym[2 * treeID + 2] * lazym[treeID] % MOD;
                lazya[2 * treeID + 2] = lazya[2 * treeID + 2] * lazym[treeID] % MOD;
                lazya[2 * treeID + 2] = (lazya[2 * treeID + 2] + lazya[treeID]) % MOD;
            }
            lazya[treeID] = 0;
            lazym[treeID] = 1;
        }

        if(treeL == treeR) return tree[treeID];

        int mid = (treeL + treeR) / 2;
        if(index <= mid) return query(2 * treeID + 1, treeL, mid, index);
        return query(2 * treeID + 2, mid + 1, treeR, index);
    }
};

class Fancy {

private:
    SegmentTree tree;
    int len = 0;

public:
    Fancy() : tree(1e5 + 1){}

    void append(int val) {
        tree.add(len ++, val);
    }

    void addAll(int inc) {
        tree.update_add(0, len - 1, inc);
    }

    void multAll(int mul) {
        tree.update_mul(0, len - 1, mul);
    }

    int getIndex(int idx) {
        if(idx >= 0 && idx < len)
            return tree.query(idx);
        return -1;
    }
};


int main() {

    return 0;
}
