/// Source : https://leetcode.com/problems/number-of-good-paths/
/// Author : liuyubobobo
/// Time   : 2022-10-12

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;


/// Using UF
/// Time Complexity: O(max(vals) + |edges|)
/// Space Complexity: O(n)
class UF{

private:
    vector<int> parent;

public:
    UF(int n) : parent(n){
        for(int i = 0 ; i < n ; i ++)
            parent[i] = i;
    }

    int find(int p){
        if(p != parent[p])
            parent[p] = find(parent[p]);
        return parent[p];
    }

    bool is_connected(int p, int q){
        return find(p) == find(q);
    }

    void union_elements(int p, int q){

        int p_root = find(p), q_root = find(q);

        if(p_root == q_root) return;

        parent[p_root] = q_root;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {

        int n = vals.size();
        int max_vals = *max_element(vals.begin(), vals.end());

        vector<list<pair<int, int>>> data(max_vals + 1);
        for(const vector<int>& edge: edges){
            int a = edge[0], b = edge[1];
            data[max(vals[a], vals[b])].push_back({a, b});
        }

        UF uf(n);
        int res = n;
        for(int v = 0; v <= max_vals; v ++){
            list<pair<int, int>>& l = data[v];
            set<int> vset;
            for(const pair<int, int>& p: l) {
                uf.union_elements(p.first, p.second);
                if(vals[p.first] == v) vset.insert(p.first);
                if(vals[p.second] == v) vset.insert(p.second);
            }

            map<int, int> cc;
            for(int u: vset) cc[uf.find(u)] ++;

            for(const pair<int, int>& p: cc){
                int k = p.second;
                res += k * (k - 1) / 2;
            }
        }
        return res;
    }
};


int main() {

    vector<int> vals1 = {1, 3, 2, 1, 3};
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    cout << Solution().numberOfGoodPaths(vals1, edges1) << '\n';

    return 0;
}
