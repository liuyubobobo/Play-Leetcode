/// Source : https://leetcode.com/problems/couples-holding-hands/description/
/// Author : liuyubobobo
/// Time   : 2018-06-17

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Graph Solution
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        assert(row.size() % 2 == 0);
        for(int i = 0 ; i < row.size() ; i ++)
            row[i] = row[i] / 2;
        // print_vec(row);

        unordered_map<int, vector<int>> node_map;
        for(int i = 0 ; i < row.size() ; i ++)
            node_map[row[i]].push_back(i / 2);

        vector<unordered_set<int>> g(row.size() / 2);
        for(const pair<int, vector<int>>& p: node_map){
            g[p.second[0]].insert(p.second[1]);
            g[p.second[1]].insert(p.second[0]);
        }

        int component_num = 0;
        vector<bool> visited(g.size(), false);
        for(int i = 0 ; i < g.size() ; i ++)
            if(!visited[i]){
                component_num ++;
                dfs(g, i, visited);
            }
        return g.size() - component_num;
    }

private:
    void dfs(const vector<unordered_set<int>>& g, int index, vector<bool>& visited){

        visited[index] = true;
        for(int node: g[index])
            if(!visited[node])
                dfs(g, node, visited);
        return;
    }
};


int main() {

    vector<int> row1 = {0, 2, 1, 3};
    cout << Solution().minSwapsCouples(row1) << endl;

    vector<int> row2 = {3, 2, 0, 1};
    cout << Solution().minSwapsCouples(row2) << endl;

    return 0;
}