/// Source : https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
/// Author : liuyubobobo
/// Time   : 2020-05-05

#include <iostream>
#include <map>

using namespace std;


/// DFS
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

private:
    int LEFT = 0;
    int RIGHT = 1;
    int res;

public:
    int longestZigZag(TreeNode* root) {

        if(!root) return 0;

        res = 0;
        dfs(root, LEFT, 0);
        dfs(root, RIGHT, 0);
        return res;
    }

private:
    void dfs(TreeNode* node, int d, int len){

        if(!node) return;

        res = max(res, len);

        dfs(d == LEFT ? node->left : node->right, 1 - d, len + 1);
        dfs(d == LEFT ? node->right : node->left, d, 1);
        return;
    }
};


int main() {

    return 0;
}
