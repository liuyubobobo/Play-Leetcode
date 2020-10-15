/// Source : https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
/// Author : liuyubobobo
/// Time   : 2020-10-15

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Brute Force all combinations and get tree diameter
/// Time Complexity: O(n * 2^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {

        vector<unordered_set<int>> g(n);
        for(const vector<int>& e: edges)
            g[e[0] - 1].insert(e[1] - 1), g[e[1] - 1].insert(e[0] - 1);

        vector<int> res(n - 1);
        for(int i = 0; i <= (1 << n) - 1; i ++){
            int d = getd(n, g, i);
//            cout << "state " << i << " : " << d << endl;
            assert(d >= 0 && d < n);
            if(d) res[d - 1] ++;
        }
        return res;
    }

private:
    int getd(int n, const vector<unordered_set<int>>& g, int state){

        int visited = 0;
        for(int i = 0; i < n; i ++)
            if(state & (1 << i)){
                dfs1(n, g, i, state, visited);
                break;
            }

        if(state != visited) return 0;

        for(int i = 0; i < n; i ++)
            if(state & (1 << i)){
                visited = 0;
                pair<int, int> res = dfs2(n, g, i, state, visited);
                return res.second;
            }
        return 0;
    }

    void dfs1(int n, const vector<unordered_set<int>>& g, int v, int state, int& visited){

        visited |= (1 << v);
        for(int next: g[v])
            if((state & (1 << next)) && !(visited & (1 << next)))
                dfs1(n, g, next, state, visited);
    }

    pair<int, int> dfs2(int n, const vector<unordered_set<int>>& g, int v, int state, int& visited){

        visited |= (1 << v);

        int res = 0;
        vector<int> dis;
        for(int next: g[v])
            if((state & (1 << next)) && !(visited & (1 << next))) {
                pair<int, int> tres = dfs2(n, g, next, state, visited);
                res = max(res, tres.second);
                dis.push_back(tres.first + 1);
            }

        if(dis.size() == 0) return {0, res};
        if(dis.size() == 1) return {dis[0], max(res, dis[0])};

        sort(dis.begin(), dis.end(), greater<int>());
        return {dis[0], max(res, dis[0] + dis[1])};
    }
};


void print_v(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> edges1 = {{1, 2}, {2, 3}, {2, 4}};
    print_v(Solution().countSubgraphsForEachDiameter(4, edges1));
    // 3, 4, 0

    vector<vector<int>> edges2 = {{1, 2}};
    print_v(Solution().countSubgraphsForEachDiameter(2, edges2));
    // 1

    vector<vector<int>> edges3 = {{1, 2}, {2, 3}};
    print_v(Solution().countSubgraphsForEachDiameter(3, edges3));
    // 2 1

    vector<vector<int>> edges4 = {{1, 3}, {1, 4}, {2, 3}};
    print_v(Solution().countSubgraphsForEachDiameter(4, edges4));
    // 3 2 1

    vector<vector<int>> edges5 = {{1, 4}, {1, 3}, {2, 5}, {2, 6}, {3, 6}, {6, 7}};
    print_v(Solution().countSubgraphsForEachDiameter(7, edges5));
    // 6 7 7 5 2 0

    vector<vector<int>> edges6 = {{1, 4}, {1, 5}, {1, 6}, {2, 3}, {2, 5}};
    print_v(Solution().countSubgraphsForEachDiameter(6, edges6));
    // 5 6 4 3 0

    return 0;
}
