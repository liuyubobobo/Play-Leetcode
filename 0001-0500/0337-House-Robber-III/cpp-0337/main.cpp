/// Source : https://leetcode.com/problems/house-robber-iii/description/
/// Author : liuyubobobo
/// Time   : 2017-12-09

#include <iostream>
#include <map>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Brute Force
/// Time Complexity: O(2^n), where n is the nodes' number in the tree
/// Space Complexity: O(h), where h is the tree's height
class Solution {

private:
    map<pair<TreeNode*, int>, int> dp;

public:
    int rob(TreeNode* root) {

        dp.clear();
        return rob(root, true);
    }

private:
    int rob(TreeNode* root, bool include){

        if(root == NULL)
            return 0;

        pair<TreeNode*, int> p = make_pair(root, include);
        if(dp.find(p) != dp.end())
            return dp[p];

        int res = rob(root->left, true) + rob(root->right, true);
        if(include)
            res = max(root->val + rob(root->left, false) + rob(root->right, false),
                       res);

        return dp[p] = res;
    }
};

int main() {

    return 0;
}