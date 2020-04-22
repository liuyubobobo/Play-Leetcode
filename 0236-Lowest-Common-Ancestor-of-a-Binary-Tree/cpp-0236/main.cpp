/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2020-04-22

#include <iostream>
#include <vector>

using namespace std;

/// Find two paths
/// Time Complexity: O(3n)
/// Space Complexity: O(2n)

///Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> path1;
        dfs(root, p, path1);

        vector<TreeNode*> path2;
        dfs(root, q, path2);

        TreeNode* res;
        for(int i = 0; i < path1.size() && i < path2.size(); i ++)
            if(path1[i] == path2[i]) res = path1[i];
            else break;
        return res;
    }

private:
    bool dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& path){

        if(!node) return false;

        path.push_back(node);
        if(node == target) return true;

        if(dfs(node->left, target, path)) return true;
        if(dfs(node->right, target, path)) return true;

        path.pop_back();
        return false;
    }
};


int main() {

    return 0;
}