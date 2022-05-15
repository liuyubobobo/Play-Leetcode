/// Source : https://leetcode.cn/problems/successor-lcci/
/// Author : liuyubobobo
/// Time   : 2022-05-15

#include <iostream>
#include <vector>

using namespace std;


/// DFS
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        bool next = false;
        return dfs(root, p, next);
    }

private:
    TreeNode* dfs(TreeNode* node, TreeNode* target, bool& next){

        if(node->left){
            TreeNode* ret = dfs(node->left, target, next);
            if(ret != nullptr) return ret;
        }

        if(next) return node;
        if(node == target) next = true;

        if(node->right){
            TreeNode* ret = dfs(node->right, target, next);
            if(ret != nullptr) return ret;
        }

        return nullptr;
    }
};


int main() {

    return 0;
}
