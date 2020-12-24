/// Source : https://leetcode.com/problems/balanced-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-12-23

#include <iostream>
#include <unordered_map>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

private:
    unordered_map<TreeNode*, int> height;

public:
    bool isBalanced(TreeNode* root) {

        if(!root) return true;

        int left_height = get_height(root->left);
        int right_height = get_height(root->right);

        return isBalanced(root->left) && isBalanced(root->right) && abs(left_height - right_height) <= 1;
    }

private:
    int get_height(TreeNode* node){

        if(!node) return 0;
        if(height.count(node)) return height[node];

        return height[node] = max(get_height(node->left), get_height(node->right)) + 1;
    }
};


int main() {

    return 0;
}
