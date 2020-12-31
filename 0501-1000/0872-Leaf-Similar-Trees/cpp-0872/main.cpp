/// Source : https://leetcode.com/problems/leaf-similar-trees/description/
/// Author : liuyubobobo
/// Time   : 2018-07-21

#include <iostream>
#include <vector>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// DFS
/// Time Complexity: O(T1 + T2)
/// Space Complexity: O(T1 + T2)
class Solution {

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int> leaf_seq1;
        get_leaf_sequence(root1, leaf_seq1);

        vector<int> leaf_seq2;
        get_leaf_sequence(root2, leaf_seq2);

        return leaf_seq1 == leaf_seq2;
    }

private:
    void get_leaf_sequence(TreeNode* node, vector<int>& res){

        if(node->left == NULL && node->right == NULL){
            res.push_back(node->val);
            return;
        }

        if(node->left)
            get_leaf_sequence(node->left, res);

        if(node->right)
            get_leaf_sequence(node->right, res);

        return;
    }
};


int main() {

    return 0;
}