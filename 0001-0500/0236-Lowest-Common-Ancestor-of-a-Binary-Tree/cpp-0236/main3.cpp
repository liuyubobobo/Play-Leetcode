/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-11-17

#include <iostream>
#include <cassert>

using namespace std;

/// Another Recursion implementation
/// Time Complexity: O(n)
/// Space Complexity: O(n)

///Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {

private:
    TreeNode* ret = 0;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        assert(ret);
        return ret;
    }

private:
    // 在root中寻找p和q, 如果包含则返回 true
    // 否则返回false
    //
    // root是p或者q；root的左子树包含p或q；root的右子树包含p或q；三个条件有两个满足
    // 则 ret = root
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root)
            return false;

        bool mid = false;
        if(root == p || root == q)
            mid = true;

        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);

        if(mid + left + right >= 2)
            ret = root;

        return mid + left + right;
    }
};


int main() {

    return 0;
}