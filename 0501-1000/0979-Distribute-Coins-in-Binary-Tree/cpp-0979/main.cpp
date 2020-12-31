/// Source : https://leetcode.com/problems/distribute-coins-in-binary-tree/
/// Author : liuyubobobo
/// Time   : 2019-01-20

#include <iostream>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(1)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    int distributeCoins(TreeNode* root) {

        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode* node, int& res){

        if(!node) return 0;

        int l = dfs(node->left, res);
        int r = dfs(node->right, res);
        res += abs(l) + abs(r);
        return node->val + l + r - 1;
    }
};


int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(0);
    cout << Solution().distributeCoins(root) << endl;
    // 2

    // [5,0,0,null,null,0,0,3,null,null,0,null,null,null,0]
    // 13

    // [3,null,0,0,null,0,null,2]
    // 4

    // [0,2,3,0,0,null,null,1]
    // 5

    return 0;
}