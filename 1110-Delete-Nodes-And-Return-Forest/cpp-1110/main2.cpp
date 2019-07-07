/// Source : https://leetcode.com/problems/delete-nodes-and-return-forest/
/// Author : liuyubobobo
/// Time   : 2019-07-07

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Recursion
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
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        unordered_set<int> remove_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        remove(root, true, remove_set, res);
        return res;
    }

private:
    TreeNode* remove(TreeNode* node, bool is_root,
             const unordered_set<int>& remove_set, vector<TreeNode*>& res){

        if(!node) return NULL;

        bool deleted = remove_set.count(node->val);
        if(is_root && !deleted) res.push_back(node);
        node->left = remove(node->left, deleted, remove_set, res);
        node->right = remove(node->right, deleted, remove_set, res);
        return deleted ? NULL : node;
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