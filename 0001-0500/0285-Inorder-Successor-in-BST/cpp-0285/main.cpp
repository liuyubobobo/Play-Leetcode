/// Source : https://leetcode.com/problems/inorder-successor-in-bst/
/// Author : liuyubobobo
/// Time   : 2021-04-08

#include <iostream>
#include <vector>

using namespace std;



/// Inorder DFS and using array to store all elements
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

        vector<TreeNode*> v;
        inorder(root, v);

        for(int i = 1; i < v.size(); i ++)
            if(v[i - 1] == p) return v[i];

        return nullptr;
    }

private:
    void inorder(TreeNode* node, vector<TreeNode*>& v){

        if(!node) return;

        inorder(node->left, v);
        v.push_back(node);
        inorder(node->right, v);
    }
};


int main() {

    return 0;
}
