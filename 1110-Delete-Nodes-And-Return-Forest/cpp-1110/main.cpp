/// Source : https://leetcode.com/problems/delete-nodes-and-return-forest/
/// Author : liuyubobobo
/// Time   : 2019-07-06

#include <iostream>
#include <vector>

using namespace std;


/// Simulations
/// Time Complexity: O(|to_delete| * n)
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        vector<TreeNode*> res = {root};
        for(int e: to_delete)
            res = delNodes(res, e);
        return res;
    }

private:
    vector<TreeNode*> delNodes(vector<TreeNode*> v, int to_delete){

        vector<TreeNode*> ret;
        bool ok = false;
        for(TreeNode* root: v)
            if(ok || !delNode(root, NULL, -1, root, to_delete, ret))
                ret.push_back(root);
            else
                ok = true;

        return ret;
    }

    bool delNode(TreeNode* root, TreeNode* parent, int index, TreeNode* node, int to_delete,
                 vector<TreeNode*>& ret){

        if(!node) return false;
        if(node->val == to_delete){
            if(node == root){
                if(node->left) ret.push_back(node->left);
                if(node->right) ret.push_back(node->right);
            }
            else{
                if(index == 0) parent->left = NULL;
                else parent->right = NULL;

                ret.push_back(root);
                if(node->left) ret.push_back(node->left);
                if(node->right) ret.push_back(node->right);
            }
            return true;
        }

        if(delNode(root, node, 0, node->left, to_delete, ret))
            return true;
        return delNode(root, node, 1, node->right, to_delete, ret);
    }
};


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> to_delete = {3, 5};
    Solution().delNodes(root, to_delete);

    return 0;
}