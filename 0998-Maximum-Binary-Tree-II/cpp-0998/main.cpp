/// Source : https://leetcode.com/problems/maximum-binary-tree-ii/
/// Author : liuyubobobo
/// Time   : 2019-02-23

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


/// Simulation
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {

        vector<int> A;
        dfs(root, A);
        A.push_back(val);
        return construct(A, 0, A.size() - 1);
    }

private:
    TreeNode* construct(const vector<int>& A, int l, int r){

        if(l > r) return NULL;

        int best_val = A[l], best_index = l;
        for(int i = l + 1; i <= r; i ++)
            if(A[i] > best_val)
                best_val = A[i], best_index = i;

        TreeNode* retNode = new TreeNode(A[best_index]);
        retNode->left = construct(A, l, best_index - 1);
        retNode->right = construct(A, best_index + 1, r);
        return retNode;
    }

    void dfs(TreeNode* root, vector<int>& A){

        if(!root) return;
        dfs(root->left, A);
        A.push_back(root->val);
        dfs(root->right, A);
    }
};

int main() {

    return 0;
}