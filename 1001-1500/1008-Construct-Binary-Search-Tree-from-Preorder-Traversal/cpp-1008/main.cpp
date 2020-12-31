/// Source : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
/// Author : liuyubobobo
/// Time   : 2019-03-09

#include <iostream>
#include <vector>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Recursive
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        int n = preorder.size();
        return dfs(preorder, 0, n - 1);
    }

private:
    TreeNode* dfs(const vector<int>& v, int l, int r){

        if(l > r || l >= v.size() || r >= v.size()) return NULL;

        TreeNode* root = new TreeNode(v[l]);

        int i;
        for(i = l + 1; i <= r; i ++)
            if(v[i] > v[l]) break;

        root->left = dfs(v, l + 1, i - 1);
        root->right = dfs(v, i, r);
        return root;
    }
};


int main() {

    return 0;
}