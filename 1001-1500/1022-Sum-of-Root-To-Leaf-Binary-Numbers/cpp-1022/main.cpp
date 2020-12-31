/// Source : https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
/// Author : liuyubobobo
/// Time   : 2019-04-06

#include <iostream>

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
    int res = 0;
    const int MOD = 1e9 + 7;

public:
    int sumRootToLeaf(TreeNode* root) {

        dfs(root, 0);
        return res;
    }

private:
    void dfs(TreeNode* node, int num){

        num = (2 * num + node->val) % MOD;

        if(!node->left && !node->right){
            res = (res + num) % MOD;
            return;
        }

        if(node->left) dfs(node->left, num);
        if(node->right) dfs(node->right, num);
    }
};


int main() {

    return 0;
}