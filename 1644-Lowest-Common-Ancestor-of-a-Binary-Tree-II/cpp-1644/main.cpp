/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/
/// Author : liuyubobobo
/// Time   : 2020-11-08

#include <iostream>
#include <vector>

using namespace std;


/// Calculate the two path
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> path1, path2;
        dfs(root, p, path1);
        if(path1.empty()) return NULL;

        dfs(root, q, path2);
        if(path2.empty()) return NULL;

        reverse(path1.begin(), path1.end());
        reverse(path2.begin(), path2.end());

        TreeNode* res = root;
        for(int i = 0; i < path1.size() && i < path2.size() && path1[i] == path2[i]; i ++)
            res = path1[i];
        return res;
    }

private:
    bool dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& path){

        if(node == target){
            path.push_back(node);
            return true;
        }

        if(!node) return false;

        if(dfs(node->left, target, path) || dfs(node->right, target, path)){
            path.push_back(node);
            return true;
        }
        return false;
    }
};


int main() {

    return 0;
}
