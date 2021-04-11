/// Source : https://leetcode.com/problems/deepest-leaves-sum/
/// Author : liuyubobobo
/// Time   : 2021-04-11

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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

public:
    int deepestLeavesSum(TreeNode* root) {

        int sum = 0, maxd = 0;
        dfs(root, sum, 0, maxd);
        return sum;
    }

private:
    void dfs(TreeNode* node, int& sum, int curd, int& maxd){

        if(!node) return;

        if(curd == maxd) sum += node->val;
        else if(curd > maxd) sum = node->val, maxd = curd;

        dfs(node->left, sum, curd + 1, maxd);
        dfs(node->right, sum, curd + 1, maxd);
    }
};


int main() {

    return 0;
}
