/// Source : https://leetcode.com/problems/find-largest-value-in-each-tree-row/
/// Author : liuyubobobo
/// Time   : 2022-06-23

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(depth)

/// Definition for a binary tree node.
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
    vector<int> largestValues(TreeNode* root) {

        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int depth, vector<int>& res){

        if(!node) return;

        if(depth == res.size()) res.push_back(node->val);
        else res[depth] = max(res[depth], node->val);

        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
    }
};


int main() {

    return 0;
}
