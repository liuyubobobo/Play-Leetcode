/// Source : https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/
/// Author : liuyubobobo
/// Time   : 2021-07-31

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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int longestConsecutive(TreeNode* root) {

        map<TreeNode*, int> inc, dec;
        dfs1(root, inc);
        dfs2(root, dec);

        int res = 0;
        for(const pair<TreeNode*, int>& p: inc)
            res = max(res, p.second + dec[p.first] - 1);
        return res;
    }

private:
    int dfs1(TreeNode* node, map<TreeNode*, int>& inc){

        int res = 1, l = 0, r = 0;
        if(node->left){
            l = dfs1(node->left, inc);
            if(node->left->val == node->val + 1) res = max(res, l + 1);
        }
        if(node->right){
            r = dfs1(node->right, inc);
            if(node->right->val == node->val + 1) res = max(res, r + 1);
        }

        inc[node] = res;
        return res;
    }

    int dfs2(TreeNode* node, map<TreeNode*, int>& dec){

        int res = 1, l = 0, r = 0;
        if(node->left){
            l = dfs2(node->left, dec);
            if(node->left->val == node->val - 1) res = max(res, l + 1);
        }
        if(node->right){
            r = dfs2(node->right, dec);
            if(node->right->val == node->val - 1) res = max(res, r + 1);
        }

        dec[node] = res;
        return res;
    }
};


int main() {

    return 0;
}
