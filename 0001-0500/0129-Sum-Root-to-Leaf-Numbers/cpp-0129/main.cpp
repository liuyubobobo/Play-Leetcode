/// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
/// Author : liuyubobobo
/// Time   : 2018-10-16

#include <iostream>

using namespace std;


/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(logn)

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {

        if(!root) return 0;

        int res = 0;
        dfs(root, 0, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int tnum, int& sum){

        tnum = tnum * 10 + node->val;

        if(!node->left && !node->right)
            sum += tnum;
        else{
            if(node->left)
                dfs(node->left, tnum, sum);
            if(node->right)
                dfs(node->right, tnum, sum);
        }
    }
};


int main() {

    return 0;
}