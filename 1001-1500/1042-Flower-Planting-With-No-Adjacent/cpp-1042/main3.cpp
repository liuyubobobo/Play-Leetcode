/// Source : https://leetcode.com/problems/flower-planting-with-no-adjacent/
/// Author : liuyubobobo
/// Time   : 2019-05-19

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;


/// Greedy
/// Actually no need to BFS or DFS
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {

        vector<unordered_set<int>> g(N);
        for(const vector<int>& edge: paths){
            g[edge[0] - 1].insert(edge[1] - 1);
            g[edge[1] - 1].insert(edge[0] - 1);
        }

        vector<int> colors(N, -1);
        for(int i = 0; i < N; i ++){
            unordered_set<int> options = get_options(g, i, colors);
            colors[i] = *options.begin();
        }
        return colors;
    }

private:
    unordered_set<int> get_options(const vector<unordered_set<int>>& g, int v,
                                   const vector<int>& colors){

        unordered_set<int> options = {1, 2, 3, 4};
        for(int u: g[v])
            if(colors[u] != -1)
                options.erase(colors[u]);
        return options;
    }
};


void print_vec(const vector<int>& vec){

    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> paths1 = {{1, 2}, {2, 3}, {3, 1}};
    print_vec(Solution().gardenNoAdj(3, paths1));
    // 1 2 3

    vector<vector<int>> paths2 = {{3, 4}, {4, 5}, {3, 2}, {5, 1}, {1, 3}, {4, 2}};
    print_vec(Solution().gardenNoAdj(5, paths2));
    // 1 2 4 3 1

    return 0;
}