/// Source : https://leetcode.com/problems/kill-process/
/// Author : liuyubobobo
/// Time   : 2021-02-15

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {

public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {

        unordered_map<int, unordered_set<int>> tree;
        for(int i = 0; i < pid.size(); i ++)
            if(ppid[i] != 0) tree[ppid[i]].insert(pid[i]);

        vector<int> res;
        dfs(tree, kill, res);
        return res;
    }

private:
    void dfs(const unordered_map<int, unordered_set<int>>& tree, int u, vector<int>& res){

        res.push_back(u);
        if(tree.count(u))
            for(int v: tree.at(u))
                dfs(tree, v, res);
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> pid = {1, 3, 10, 5}, ppid = {3, 0, 5, 3};
    print_vec(Solution().killProcess(pid, ppid, 5));

    return 0;
}
