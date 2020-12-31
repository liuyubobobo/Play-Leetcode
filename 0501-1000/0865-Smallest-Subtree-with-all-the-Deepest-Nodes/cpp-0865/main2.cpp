/// Source : https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
/// Author : liuyubobobo
/// Time   : 2018-07-07

#include <iostream>
#include <unordered_map>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Using a Two Phase Recursion
/// Which lead to a longer code, but more easy to understand:)
/// Besides, this method doesn't use any class member variables:)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {

        unordered_map<TreeNode*, int> depth;
        getDepth(root, 0, depth);

        int max_depth = -1;
        for(const pair<TreeNode*, int>& p: depth)
            max_depth = max(max_depth, p.second);

        return getRes(root, depth, max_depth);
    }

private:
    void getDepth(TreeNode* node, int d, unordered_map<TreeNode*, int>& depth){

        if(node == NULL)
            return;

        depth[node] = d;
        getDepth(node->left, d + 1, depth);
        getDepth(node->right, d + 1, depth);
    }

    TreeNode* getRes(TreeNode* node, unordered_map<TreeNode*, int>& depth,
               int max_depth){

        if(node == NULL)
            return NULL;

        if(depth[node] == max_depth)
            return node;

        TreeNode* L = getRes(node->left, depth, max_depth);
        TreeNode* R = getRes(node->right, depth, max_depth);

        if(L && R) return node;
        if(L) return L;
        if(R) return R;

        return NULL;
    }
};


int main() {

    cout << Solution().subtreeWithAllDeepest(new TreeNode(1))->val << endl;

    return 0;
}