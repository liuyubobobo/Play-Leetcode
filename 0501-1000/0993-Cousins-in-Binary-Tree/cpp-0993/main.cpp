/// Source : https://leetcode.com/problems/cousins-in-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-02-16

#include <iostream>
#include <cassert>

using namespace std;


/// Two-Pass DFS
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
    bool isCousins(TreeNode* root, int x, int y) {

        if(!root || root->val == x || root->val == y)
            return false;

        pair<int, int> p1; // depth, parent
        if(!dfs(root, x, 0, p1)) return false;

        pair<int, int> p2;
        if(!dfs(root, y, 0, p2)) return false;

        return p1.first == p2.first && p1.second != p2.second;
    }

private:
    bool dfs(TreeNode* node, int x, int d, pair<int, int>& p){

        if(node->left && node->left->val == x){
            p = make_pair(d + 1, node->val);
            return true;
        }

        if(node->right && node->right->val == x){
            p = make_pair(d + 1, node->val);
            return true;
        }

        if(node->left && dfs(node->left, x, d + 1, p))
            return true;

        if(node->right && dfs(node->right, x, d + 1, p))
            return true;

        return false;
    }
};


int main() {

    return 0;
}