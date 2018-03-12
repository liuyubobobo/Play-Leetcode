/// Source : https://leetcode.com/problems/all-paths-from-source-to-target/description/
/// Author : liuyubobobo
/// Time   : 2018-03-10

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(2^N)
/// Space Complexity: O(N*2^N)
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> res;
        vector<int> cur_res = {0};
        dfs(graph, 0, cur_res, res);
        return res;
    }

private:
    void dfs(const vector<vector<int>>& graph, int start,
             vector<int>& cur_res, vector<vector<int>>& res){

        if(start == graph.size() - 1){
            res.push_back(cur_res);
            return;
        }

        for(int next: graph[start]){
            cur_res.push_back(next);
            dfs(graph, next, cur_res, res);
            cur_res.pop_back();
        }
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> g = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> res = Solution().allPathsSourceTarget(g);
    for(const vector<int>& path: res)
        print_vec(path);

    return 0;
}