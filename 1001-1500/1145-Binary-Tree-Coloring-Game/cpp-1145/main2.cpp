/// Source : https://leetcode.com/problems/binary-tree-coloring-game/
/// Author : liuyubobobo
/// Time   : 2019-08-04

#include <iostream>
#include <unordered_map>

using namespace std;


/// Mathematics
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
    int left = 0, right = 0;

public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {

        dfs(root, x);
        return max(max(left, right), n - left - right - 1) > n / 2;
    }

private:
    int dfs(TreeNode* node, int t){

        if(!node) return 0;
        int l = dfs(node->left, t), r = dfs(node->right, t);
        if(node->val == t)
            left = l, right = r;
        return 1 + l + r;
    }
};


int main() {

    return 0;
}