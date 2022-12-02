/// Source : https://leetcode.com/problems/maximum-xor-of-two-non-overlapping-subtrees/description/
/// Author : liuyubobobo
/// Time   : 2022-12-02

#include <iostream>
#include <vector>
#include <list>

using namespace std;


/// DFS + Trie
/// Time Complexity: O(nlogn(LONG_LONG_MAX))
/// Space Complexity: O(n * LONG_LONG_MAX)
class BinaryTrie {

private:
    class Node{

    public:
        Node* next[2];
        int sz;

        Node() : sz(0) {
            next[0] = next[1] = nullptr;
        };
    };

    int L;
    Node* root;

public:
    BinaryTrie(int L = 63) : root(new Node()), L(L){}

    void insert(long long x) {

        Node* cur = root;
        cur->sz ++;
        for(int i = L - 1; i >= 0; i --){
            int e = ((x >> i) & 1);
            if(cur->next[e] == nullptr)
                cur->next[e] = new Node();
            cur = cur->next[e];
            cur->sz ++;
        }
    }

    // 返回 Binary Trie 中存储的数字和 x 异或的最大值
    long long query(long long x){

        Node* cur = root;
        long long res = 0;
        for(int i = L - 1; i >= 0; i --){
            int e = ((x >> i) & 1);
            if(cur->next[1 - e] && cur->next[1 - e]->sz){
                res = res * 2 + 1;
                cur = cur->next[1 - e];
            }
            else if(cur->next[e]){
                res = res * 2;
                cur = cur->next[e];
            }
            else return 0;
        }
        return res;
    }
};

class Solution {

public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {

        vector<list<int>> tree(n);
        for(const vector<int>& e: edges){
            int a = e[0], b = e[1];
            tree[a].push_back(b), tree[b].push_back(a);
        }

        vector<long long> sum(n, 0);
        dfs_sum(tree, 0, 0, values, sum);

        long long res = 0;
        BinaryTrie trie;
        dfs(tree, 0, 0, sum, trie, res);
        return res;
    }

private:
    void dfs(const vector<list<int>>& tree, int u, int p,
             const vector<long long>& sum, BinaryTrie& trie, long long& res){

        res = max(res, trie.query(sum[u]));

        for(int v: tree[u]){
            if(v == p) continue;
            dfs(tree, v, u, sum, trie, res);
        }

        trie.insert(sum[u]);
    }

    long long dfs_sum(const vector<list<int>>& tree, int u, int p,
                      const vector<int>& values, vector<long long>& sum){

        long long res = values[u];
        for(int v: tree[u]){
            if(v == p) continue;
            res += dfs_sum(tree, v, u, values, sum);
        }
        return sum[u] = res;
    }
};


int main() {

    return 0;
}
