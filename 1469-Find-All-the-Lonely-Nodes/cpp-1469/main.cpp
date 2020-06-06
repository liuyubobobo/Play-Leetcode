/// Source : https://leetcode.com/problems/find-all-the-lonely-nodes/
/// Author : liuyubobobo
/// Time   : 2020-06-05

#include <iostream>
#include <vector>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

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
    vector<int> getLonelyNodes(TreeNode* root) {

        vector<int> res;
        dfs(root, res);
        return res;
    }

private:
    void dfs(TreeNode* node, vector<int>& res){

        if(!node) return;

        if(node->left && !node->right)
            res.push_back(node->left->val);

        if(!node->left && node->right)
            res.push_back(node->right->val);

        dfs(node->left, res);
        dfs(node->right, res);
    }
};


int main() {

    return 0;
}
