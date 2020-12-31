/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-28

#include <iostream>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Morris InOrder traversal
/// Attention: you can not change the give Tree structure in Leetcode,
/// So try to return result early will lead to RE :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    bool flag;
    int pre;

public:
    bool isValidBST(TreeNode* root) {

        flag = false;
        pre = -1;
        TreeNode* cur = root;

        bool res = true;
        while(cur != NULL){
            if(cur->left == NULL){
                if(!process(cur))
                    res = false;
                cur = cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right != NULL && prev->right != cur)
                    prev = prev->right;

                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                else{
                    prev->right = NULL;
                    if(!process(cur))
                        res = false;
                    cur = cur->right;
                }
            }
        }

        return res;
    }

private:
    bool process(TreeNode* node){

        if(flag && pre >= node->val)
            return false;
        flag = true;
        pre = node->val;
        return true;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    print_bool(Solution().isValidBST(root));

    return 0;
}