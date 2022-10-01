/// Source : https://leetcode-cn.com/problems/sZ59z6/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <set>

using namespace std;


/// DFS
/// Time Complexity: O(n)
/// Space Complexity: O(n)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numColor(TreeNode* root) {

        set<int> colors;
        dfs(root, colors);
        return colors.size();
    }

private:
    void dfs(TreeNode* node, set<int>& colors){

        if(!node) return;

        colors.insert(node->val);
        dfs(node->left, colors);
        dfs(node->right, colors);
    }
};


int main() {

    return 0;
}
