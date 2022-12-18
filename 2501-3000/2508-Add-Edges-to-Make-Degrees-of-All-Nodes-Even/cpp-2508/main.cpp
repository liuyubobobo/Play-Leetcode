/// Source : https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/
/// Author : liuyubobobo
/// Time   : 2022-12-18

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(V + E)
/// Space Complexity: O(V + E)
class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {

        vector<set<int>> g(n);
        for(const vector<int>& e: edges){
            int u = e[0] - 1, v = e[1] - 1;
            g[u].insert(v), g[v].insert(u);
        }

        int is_full = 0;
        vector<int> oddv;
        for(int i = 0; i < n; i ++){
            if(g[i].size() == n - 1) is_full ++;
            else if(g[i].size() % 2 == 1) oddv.push_back(i);
        }

//        cout << "is_full : " << is_full << '\n';
//        for(int e: oddv) cout << e << ' '; cout << '\n';
//        cout << g[1].count(2) << ' ' << g[2].count(1) << '\n';
        if(is_full && (n - 1) % 2) return false;

        if(oddv.empty()) return true;
        if(oddv.size() == 2) {
            if(ok_to_connect(g, oddv[0], oddv[1])) return true;
            for(int i = 0; i < n; i ++)
                if(g[i].size() + 2 <= n - 1 && ok_to_connect(g, i, oddv[0]) && ok_to_connect(g, i, oddv[1]))
                    return true;
            return false;
        }

        if(oddv.size() != 4) return false;

        do{
            if(ok_to_connect(g, oddv[0], oddv[1]) && ok_to_connect(g, oddv[2], oddv[3]))
                return true;
        }while(next_permutation(oddv.begin(), oddv.end()));
        return false;
    }

private:
    static bool ok_to_connect(const vector<set<int>>& g, int u, int v){
        return g[u].count(v) == 0 && g[v].count(u) == 0;
    }
};


int main() {

    vector<vector<int>> edges1 = {{1, 2}, {3, 4}};
    cout << Solution().isPossible(4, edges1) << '\n';
    // 1

    vector<vector<int>> edges2 = {
            {5,  9},
            {8,  1},
            {2,  3},
            {7,  10},
            {3,  6},
            {6,  7},
            {7,  8},
            {5,  1},
            {5,  7},
            {10, 11},
            {3,  7},
            {6,  11},
            {8,  11},
            {3,  4},
            {8,  9},
            {9,  1},
            {2,  10},
            {9,  11},
            {5,  11},
            {2,  5},
            {8,  10},
            {2,  7},
            {4,  1},
            {3,  10},
            {6,  1},
            {4,  9},
            {4,  6},
            {4,  5},
            {2,  4},
            {2,  11},
            {5,  8},
            {6,  9},
            {4,  10},
            {3,  11},
            {4,  7},
            {3,  5},
            {7,  1},
            {2,  9},
            {6,  10},
            {10, 1},
            {5,  6},
            {3,  9},
            {2,  6},
            {7,  9},
            {4,  11},
            {4,  8},
            {6,  8},
            {3,  8},
            {9,  10},
            {5,  10},
            {2,  8},
            {7,  11}
    };
    cout << Solution().isPossible(11, edges2) << '\n';
    // 0

    return 0;
}
