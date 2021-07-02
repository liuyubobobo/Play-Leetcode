/// Source : https://leetcode.com/problems/find-leaves-of-binary-tree/
/// Author : liuyubobobo
/// Time   : 2021-07-01

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {

        unordered_map<TreeNode*, int> level;
        level[nullptr] = 0;
        dfs(root, level);

        vector<vector<int>> res(level[root] + 1);
        for(const pair<TreeNode*, int>& p: level)
            if(p.first) res[p.second].push_back(p.first->val);
        return res;
    }

private:
    void dfs(TreeNode* node, unordered_map<TreeNode*, int>& level){

        if(!node) return;

        if(!node->left && !node->right){
            level[node] = 0;
            return;
        }

        dfs(node->left, level);
        dfs(node->right, level);
        level[node] = max(level[node->left], level[node->right]) + 1;
    }
};


int main() {

    return 0;
}
