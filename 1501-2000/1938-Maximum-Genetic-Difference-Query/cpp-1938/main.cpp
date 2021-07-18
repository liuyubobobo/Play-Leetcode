/// Source : https://leetcode.com/problems/maximum-genetic-difference-query/
/// Author : liuyubobobo
/// Time   : 2021-07-17

#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

using namespace std;


/// Offline Query + Trie
/// Time Complexity: O(nlog(maxv))
/// Space Complexity: O(nlog(maxv))
class Trie {

private:
    class Node{

    public:
        vector<Node*> next;
        int sz;

        Node() : next(2, nullptr), sz(0) {};
    };

    int L;
    Node* root;

public:
    Trie() : root(new Node()){}

    void setL(int L){
        this->L = L;
    }

    void insert(int x) {

        Node* cur = root;
        cur->sz ++;
        for(int i = 0; i < L; i ++){
            int e = !!(x & (1 << (L - i - 1)));
            if(cur->next[e] == nullptr)
                cur->next[e] = new Node();
            cur = cur->next[e];
            cur->sz ++;
        }
    }

    void erase(int x) {

        Node* cur = root;
        cur->sz --;
        for(int i = 0; i < L; i ++){
            int e = !!(x & (1 << (L - i - 1)));
            cur = cur->next[e];
            cur->sz --;
        }
    }

    int query(int x){

        Node* cur = root;
        int res = 0;
        for(int i = 0; i < L; i ++){
            int e = !!(x & (1 << (L - i - 1)));
            if(cur->next[1 - e] && cur->next[1 - e]->sz){
                res = res * 2 + 1;
                cur = cur->next[1 - e];
            }
            else{
                res = res * 2;
                cur = cur->next[e];
            }
        }
        return res;
    }
};

class Solution {

private:
    Trie trie;

public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {

        int n = parents.size();

        vector<vector<int>> g(n);
        int root = -1;
        for(int i = 0; i < n; i ++){
            if(parents[i] == -1)
                root = i;
            else
                g[parents[i]].push_back(i);
        }
        assert(root != -1);

        int maxv = n;
        vector<vector<pair<int ,int>>> queries_map(n); // node -> {val, index}
        for(int i = 0; i < queries.size(); i ++) {
            queries_map[queries[i][0]].push_back({queries[i][1], i});
            maxv = max(maxv, queries[i][1]);
        }

        int L = 0;
        while(maxv) maxv >>= 1, L ++;
        trie.setL(L);

        vector<int> res(queries.size());
        dfs(n, g, root, queries_map, res);
        return res;
    }

private:
    void dfs(int n, const vector<vector<int>>& g, int u,
             const vector<vector<pair<int ,int>>>& queries_map, vector<int>& res){

        trie.insert(u);
        for(const pair<int, int>& p: queries_map[u]){
            int val = p.first, index = p.second;
            res[index] = trie.query(val);
        }

        for(int v: g[u])
            dfs(n, g, v, queries_map, res);

        trie.erase(u);
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << endl;
}

int main() {

    vector<int> parents1 = {-1, 0, 1, 1};
    vector<vector<int>> queris1 = {{0, 2}, {3, 2}, {2, 5}};
    print_vec(Solution().maxGeneticDifference(parents1, queris1));
    // 2 3 7

    vector<int> parents2 = {3,7,-1,2,0,7,0,2};
    vector<vector<int>> queris2 = {{4, 6}, {1, 15}, {0, 5}};
    print_vec(Solution().maxGeneticDifference(parents2, queris2));
    // 6 14 7

    vector<int> parents3 = {-1,0,0,0,3};
    vector<vector<int>> queris3 = {{4, 6}, {0, 0}, {0, 3}, {1, 8}, {4, 0}};
    print_vec(Solution().maxGeneticDifference(parents3, queris3));
    // 6 0 3 9 4

    return 0;
}
