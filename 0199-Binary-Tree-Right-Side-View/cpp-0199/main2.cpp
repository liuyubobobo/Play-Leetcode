/// Source : https://leetcode.com/problems/binary-tree-right-side-view/
/// Author : liuyubobobo
/// Time   : 2019-09-26

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {

private:
    vector<int> res;

public:
    vector<int> rightSideView(TreeNode* root) {

        if(!root) return res;

        dfs(root, 0);
        return res;
    }

private:
    void dfs(TreeNode* node, int d){

        if(res.size() <= d) res.push_back(0);
        res[d] = node->val;

        if(node->left) dfs(node->left, d + 1);
        if(node->right) dfs(node->right, d + 1);
    }
};


int main() {

    return 0;
}