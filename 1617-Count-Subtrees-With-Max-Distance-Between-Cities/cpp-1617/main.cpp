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
//            assert(d >= 0 && d < n);
            if(d) res[d - 1] ++;
        }
        return res;
    }

private:
    int getd(int n, const vector<unordered_set<int>>& g, int state){

        for(int i = 0; i < n; i ++)
            if(state & (1 << i)){
                int visited = 0, res = 0;
                dfs(n, g, i, state, visited, res);
                return visited == state ? res : 0;
            }
        return 0;
    }

    int dfs(int n, const vector<unordered_set<int>>& g, int v, int state,
            int& visited, int& res){

        visited |= (1 << v);

        int first = 0, second = 0;
        for(int next: g[v])
            if((state & (1 << next)) && !(visited & (1 << next))){
                int t = dfs(n, g, next, state, visited, res) + 1;
                if(t >= first) second = first, first = t;
                else if(t > second) second = t;
            }
        res = max(res, first + second);
        return first;
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
