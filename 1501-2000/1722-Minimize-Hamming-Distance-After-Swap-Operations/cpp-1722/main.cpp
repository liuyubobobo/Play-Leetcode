/// Source : https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
/// Author : liuyubobobo
/// Time   : 2021-01-09

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/// Connected Components
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {

        int n = source.size();
        vector<unordered_set<int>> g(n);
        for(const vector<int>& e: allowedSwaps)
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);

        vector<int> cc(n, -1);
        int color = 0;
        for(int i = 0; i < n; i ++)
            if(cc[i] == -1)
                dfs(g, i, color ++, cc);

        vector<vector<int>> C(color);
        for(int i = 0; i < n; i ++) C[cc[i]].push_back(i);

        int res = 0;
        for(int co = 0; co < color; co ++){
            unordered_map<int, int> f;
            for(int index: C[co])
                f[source[index]] ++;

            for(int index: C[co])
                if(f.count(target[index])){
                    res ++;
                    f[target[index]] --;
                    if(f[target[index]] == 0) f.erase(target[index]);
                }
        }
        return n - res;
    }

private:
    void dfs(const vector<unordered_set<int>>& g, int u, int color, vector<int>& cc){

        cc[u] = color;
        for(int v: g[u])
            if(cc[v] == -1)
                dfs(g, v, color, cc);
    }
};


int main() {

    vector<int> s1 = {1, 2, 3, 4}, t1 = {2, 1, 4, 5};
    vector<vector<int>> as1 = {{0, 1}, {2, 3}};
    cout << Solution().minimumHammingDistance(s1, t1, as1) << endl;
    // 1

    vector<int> s2 = {1, 2, 3, 4}, t2 = {1, 3, 2, 4};
    vector<vector<int>> as2 = {};
    cout << Solution().minimumHammingDistance(s2, t2, as2) << endl;
    // 2

    vector<int> s3 = {5, 1, 2, 4, 3}, t3 = {1, 5, 4, 2, 3};
    vector<vector<int>> as3 = {{0, 4}, {4, 2}, {1, 3}, {1, 4}};
    cout << Solution().minimumHammingDistance(s3, t3, as3) << endl;
    // 0

    return 0;
}
