/// Source : https://leetcode.com/problems/insert-into-a-binary-search-tree/
/// Author : liuyubobobo
/// Time   : 2019-04-30

#include <iostream>

using namespace std;


/// Iterative
/// Time Complexity: O(h)
/// Space Complexity: O(h)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        if(!root) return new TreeNode(val);

        TreeNode* p = root;
        while(true){
            if(val < p->val){
                if(!p->left){
                    p->left = new TreeNode(val);
                    break;
                }
                p = p->left;
            }
            else{
                if(!p->right){
                    p->right = new TreeNode(val);
                    break;
                }
                p = p->right;
            }
        }
        return root;
    }
};


int main() {

    return 0;
}